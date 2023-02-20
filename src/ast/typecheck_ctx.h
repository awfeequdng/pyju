
#include "ast/ctx.h"

namespace PYJU {
class TypecheckItem {

    enum class Kind {
        Func,
        Type,
        Var
    } kind;

    TypecheckItem(Kind k): kind(k) {}
};

struct TypecheckContext : public Context<TypecheckItem> {

};


}