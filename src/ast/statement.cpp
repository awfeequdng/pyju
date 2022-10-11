// Part of the Carbon Language project, under the Apache License v2.0 with LLVM
// Exceptions. See /LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception


#include "ast/statement.h"
#include "ast/name.h"
#include "ast/expression.h"
#include "base/check.h"
#include "base/arena.h"
#include "llvm/Support/Casting.h"

namespace PYJU {

using llvm::cast;

Statement::~Statement() = default;

llvm::raw_ostream& Statement::Space(int depth, llvm::raw_ostream& out) {
  if (depth == 0) return out;
  std::string str(4 * depth, '.');
  out << str;
  return out;
}

void Statement::PrintDepth(int depth, llvm::raw_ostream& out) const {

    switch (kind()) {
      case StatementKind::ExprStmt: {
          const auto &expr = cast<ExprStmt>(*this).expression();
          Space(depth, out) << expr << "\n";
          break;
      }
      case StatementKind::If: {
          auto &if_stmt = cast<If>(*this);
          auto &test = if_stmt.test();
          auto &body = if_stmt.body();
          auto &orelse = if_stmt.orelse();

          Space(depth, out) << "if " << test << ":\n";
          for (auto &b: body) {
            cast<Statement>(*b).PrintDepth(depth+1, out);
          }
          if (orelse.size()) {
            Space(depth, out) << "else:\n";
            for (auto &o: orelse) {
              cast<Statement>(*o).PrintDepth(depth + 1, out);
            }
          }
          break;
      }
      case StatementKind::FunctionDef: {
          auto &name = cast<FunctionDef>(*this).name_;
          auto &args = cast<FunctionDef>(*this).args_;
          auto &body = cast<FunctionDef>(*this).body_;
          auto &returns = cast<FunctionDef>(*this).returns_;
          auto &decorator_list = cast<FunctionDef>(*this).decorator_list_;
          for (auto &d: decorator_list) {
            Space(depth, out) << "@" << (*d) << "\n";
          }
          Space(depth, out) << "def " << *name << "("
            << *args << ")";
          if (returns) out << "->" << **returns << ":\n";
          else out << ":\n";
          for (auto &b: body) {
            cast<Statement>(*b).PrintDepth(depth+1, out);
          }
        break;
      }
      case StatementKind::Global: {
          auto &names = cast<Global>(*this).names();
          Space(depth, out) << "global ";
          size_t i = 0;
          for (; i < names.size() - 1; i++) {
            out << (*names[i]) << ", ";
          }
          out << (*names[i]) << "\n";
        break;
      }
      case StatementKind::NonLocal: {
          auto &names = cast<NonLocal>(*this).names();
          Space(depth, out) << "local ";
          size_t i = 0;
          for (; i < names.size() - 1; i++) {
            out << (*names[i]) << ", ";
          }
          out << (*names[i]) << "\n";
        break;
      }
      case StatementKind::Import: {
        auto &impt = cast<Import>(*this);
        Space(depth, out) << "import ";
        size_t i = 0;
        for (; i < impt.names().size() - 1; i++) {
          auto &alias = impt.names()[i];
          out << *alias << ", ";
        }
        out << *(impt.names()[i]) << "\n";

        break;
      }
      case StatementKind::ImportFrom: {
        auto &impt = cast<ImportFrom>(*this);
        Space(depth, out) << "from ";
        size_t i = 0;
        for (i = 0; i < impt.level(); i++) {
          out << ".";
        }
        auto &mod = impt.mod();
        for (i = 0; i < mod.size() - 1; i++) {
          auto &m = mod[i];
          out << *m << ".";
        }
        out << *(mod[i]);

        out << " import ";

        auto &names = impt.names();
        for (i = 0; i < names.size() - 1; i++) {
          auto &name = names[i];
          out << *name << ", ";
        }
        out << *(names[i]) << "\n";

        break;
      }
      case StatementKind::Pass: {
        Space(depth, out) << "pass\n";
        break;
      }
      case StatementKind::Continue: {
        Space(depth, out) << "continue\n";
        break;
      }
      case StatementKind::Break: {
        Space(depth, out) << "break\n";
        break;
      }
      case StatementKind::Assert: {
        auto &asrt = cast<Assert>(*this);
        auto &test = asrt.test();
        auto &msg = asrt.msg();
        Space(depth, out) << "assert " << asrt.test();
        if (msg) out << " , " << **msg;
        out << "\n";
        break;
      }
      case StatementKind::Raise: {
        auto &raise = cast<Raise>(*this);
        auto &exc = raise.exc();
        auto &cause = raise.cause();
        Space(depth, out) << "raise";
        if (exc) out << " " << **exc;
        if (cause) out << "from " << **cause;
        out << "\n";
        break;
      }
      case StatementKind::Return: {
        auto &ret = cast<Return>(*this);
        auto &value = ret.value();
        Space(depth, out) << "return";
        if (value) out << " " << **value;
        out << "\n";
        break;
      }
      case StatementKind::TupleStmt: {
        Space(depth, out) << "TupleStmt(";
        for (auto &elt: cast<TupleStmt>(*this).tuple()) {
          out << *elt << ",";
        }
        out << ")\n";
        break;
      }
      case StatementKind::Delete: {
        Space(depth, out) << "del ";
        for (auto &elt: cast<Delete>(*this).targets()) {
          out << *elt << ", ";
        }
        out << "\n";
        break;
      }
      case StatementKind::Assign: {
        auto &assign = cast<Assign>(*this);
        auto &targets = assign.targets();
        auto &value = assign.value();
        Space(depth, out) << "Assign:";
        for (auto &target: targets) {
          out << *target << " = ";
        }
        out << *value;
        out << "\n";
        break;
      }
      default:
        out << "unknown kind: ";
        break;
    }
}

}  // namespace PYJU
