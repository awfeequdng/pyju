#include "llvm-version.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"
#include <cstddef>

using namespace llvm;

namespace  {

bool demoteFloat16(Function &F) {
    auto &ctx = F.getContext();
    auto T_float16 = Type::getHalfTy(ctx);
    auto T_float32 = Type::getFloatTy(ctx);
    SmallVector<Instruction*, 0> erase;
    for (auto &B : F) {
        for (auto &I : B) {
            switch (I.getOpcode()) {
            case Instruction::FAdd:
            case Instruction::FSub:
            case Instruction::FMul:
            case Instruction::FDiv:
            case Instruction::FCmp:
            case Instruction::FNeg:
            case Instruction::FRem:
                break;
            default:
                continue;
            }
            if (I.isFast())
                continue;
            IRBuilder<> builder(&I);
            // expand float16 to float32
            bool operandsChanged = false;
            SmallVector<Value*, 2> operands(I.getNumOperands());
            for (size_t i = 0; i < I.getNumOperands(); i++) {
                Value *op = I.getOperand(i);
                if (op->getType() == T_float16) {
                    op = builder.CreateFPExt(op, T_float32);
                    operandsChanged = true;
                }
                operands[i] = op;
            }

            if (operandsChanged == false)
                continue;
            Value *newI;
            switch (I.getOpcode()) {
            case Instruction::FAdd:
                assert(I.getNumOperands() == 2);
                newI = builder.CreateFAdd(operands[0], operands[1]);
                break;
            case Instruction::FSub:
                assert(I.getNumOperands() == 2);
                newI = builder.CreateFSub(operands[0], operands[1]);
                break;
            case Instruction::FMul:
                assert(I.getNumOperands() == 2);
                newI = builder.CreateFMul(operands[0], operands[1]);
                break;
            case Instruction::FDiv:
                assert(I.getNumOperands() == 2);
                newI = builder.CreateFDiv(operands[0], operands[1]);
                break;
            case Instruction::FCmp:
                assert(I.getNumOperands() == 2);
                newI = builder.CreateFCmp(cast<FCmpInst>(&I)->getPredicate(),
                                          operands[0], operands[1]);
                break;
            case Instruction::FRem:
                assert(I.getNumOperands() == 2);
                newI = builder.CreateFRem(operands[0], operands[1]);
                break;
            case Instruction::FNeg:
                assert(I.getNumOperands() == 1);
                newI = builder.CreateFNeg(operands[0]);
                break;
            default:
                abort();
            }
            cast<Instruction>(newI)->copyMetadata(I);
            cast<Instruction>(newI)->copyFastMathFlags(&I);
            if (newI->getType() != I.getType()) {
                newI = builder.CreateFPTrunc(newI, I.getType());
            }
            I.replaceAllUsesWith(newI);
            erase.push_back(&I);
        }
    }
    if (erase.size() > 0) {
        for (auto I : erase) {
            I->eraseFromParent();
        }
        return true;
    }
    return false;
}

struct DemoteFloat16Legacy : public FunctionPass {
    static char ID;
    DemoteFloat16Legacy() : FunctionPass(ID) {}

private:
    bool runOnFunction(Function &F) override {
        return demoteFloat16(F);
    }
};

char DemoteFloat16Legacy::ID = 0;

} // end anonymous namespace

Pass* createDemoteFloat16Pass() {
    return new DemoteFloat16Legacy();
}