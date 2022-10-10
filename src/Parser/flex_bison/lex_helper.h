#pragma once

#define YY_USER_ACTION  \
    context.current_token_position.columns(yyleng);

#define PXC_TOKEN(name) \
    PYJU::Parser::make_##name(context.current_token_position);

#define PXC_ARG_TOKEN(name, arg) \
    PYJU::Parser::make_##name(arg, context.current_token_position);
