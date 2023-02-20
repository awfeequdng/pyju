
#include "ast/name.h"
#include "ast/expression.h"
#include "ast/statement.h"

namespace PYJU {

class Visitor {
public:
    virtual void visit(Name&) = 0;
};

}