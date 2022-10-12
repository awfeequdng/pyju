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
      case StatementKind::AugAssign: {
        auto &aug_assign = cast<AugAssign>(*this);
        auto &target = aug_assign.target();
        auto &op = aug_assign.op();
        auto &value = aug_assign.value();
        Space(depth, out) << "AugAssign:"
                          << *target
                          << operatorTypeStr(op) << "="
                          << *value
                          << "\n";
        break;
      }
      case StatementKind::AnnAssign: {
        auto &ann_assign = cast<AnnAssign>(*this);
        auto &target = ann_assign.target();
        auto &annotation = ann_assign.annotation();
        auto &value = ann_assign.value();
        Space(depth, out) << "AnnAssign:"
                          << *target << ":"
                          << *annotation;
        if (value) {
          out << " = " << **value;
        }
        out << "\n";
        break;
      }
      case StatementKind::For: {
        auto &for_stmt = cast<For>(*this);
        auto &target = for_stmt.target();
        auto &iter = for_stmt.iter();
        auto &body = for_stmt.body();
        auto &orelse = for_stmt.orelse();
        Space(depth, out) << "for " << *target << " in " << *iter << ":\n";
        for (auto &b: body)
          cast<Statement>(*b).PrintDepth(depth + 1, out);
        if (orelse.size()) {
          Space(depth, out) << "else:\n";
          for (auto &b: orelse)
            cast<Statement>(*b).PrintDepth(depth + 1, out);
        }
        break;
      }
      case StatementKind::While: {
        auto &while_stmt = cast<While>(*this);
        auto &test = while_stmt.test();
        auto &body = while_stmt.body();
        auto &orelse = while_stmt.orelse();
        Space(depth, out) << "while " << *test << ":\n";
        for (auto &b: body)
          cast<Statement>(*b).PrintDepth(depth + 1, out);
        if (orelse.size()) {
          Space(depth, out) << "else:\n";
          for (auto &b: orelse)
            cast<Statement>(*b).PrintDepth(depth + 1, out);
        }
        break;
      }
      case StatementKind::ExceptHandler: {
        auto &except = cast<ExceptHandler>(*this);
        auto &type = except.type();
        auto &name = except.name();
        auto &body = except.body();
        Space(depth, out) << "except";
        if (type) {
          out << " " << **type;
          if (name) out << " as " << **name;
        }
        out << ":\n";
        for (auto &b: body) {
          cast<Statement>(*b).PrintDepth(depth + 1, out);
        }
        break;
      }
      case StatementKind::Try: {
        auto &try_stmt = cast<Try>(*this);
        auto &body = try_stmt.body();
        auto &handlers = try_stmt.handlers();
        auto &orelse = try_stmt.orelse();
        auto &finalbody = try_stmt.finalbody();
        Space(depth, out) << "try:\n";
        for (auto &b: body) {
          cast<Statement>(*b).PrintDepth(depth + 1, out);
        }
        for (auto &b: handlers) {
          cast<Statement>(*b).PrintDepth(depth, out);
        }
        if (orelse.size() > 0) {
          Space(depth, out) << "else:\n";
          for (auto &b: orelse) {
            cast<Statement>(*b).PrintDepth(depth + 1, out);
          }
        }
        if (finalbody.size() > 0) {
          Space(depth, out) << "finally:\n";
          for (auto &b: finalbody) {
            cast<Statement>(*b).PrintDepth(depth + 1, out);
          }
        }
        break;
      }
      case StatementKind::With: {
        auto &with = cast<With>(*this);
        auto &items = with.items();
        auto &body = with.body();
        Space(depth, out) << "with ";
        for (size_t i = 0; i < items.size(); i++) {
          if (i > 0) out << ", ";
          out << *items[i];
        }
        out << ":\n";
        for (auto &b: body) {
          cast<Statement>(*b).PrintDepth(depth + 1, out);
        }
        break;
      }
      case StatementKind::WithItem: {
        auto &with_item = cast<WithItem>(*this);
        auto &expr = with_item.expr();
        auto &vars = with_item.vars();
        out << *expr;
        if (vars) out << " as " << **vars;
        break;
      }
      case StatementKind::ClassDef: {
        auto &class_def = cast<ClassDef>(*this);
        auto &name = class_def.name();
        auto &bases = class_def.bases();
        auto &keywords = class_def.keywords();
        auto &body = class_def.body();
        auto &decorator_list = class_def.decorator_list();
        for (auto &expr: decorator_list) {
          Space(depth, out) << "@" << *expr << "\n";
        }
        Space(depth, out) << "class " << *name << " (";
        bool have_bases = (bases.size() > 0);
        for (size_t i = 0; i < bases.size(); i++) {
          if (i > 0) out << ", ";
          out << *bases[i];
        }
        for (size_t i = 0; i < keywords.size(); i++) {
          if (have_bases || i > 0) out << ", ";
          out << *keywords[i];
        }
        out << "):\n";
        for (auto &b: body) {
          cast<Statement>(*b).PrintDepth(depth + 1, out);
        }

        break;
      }
      default:
        out << "unknown kind: ";
        break;
    }
}

}  // namespace PYJU
