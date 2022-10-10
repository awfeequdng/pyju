

all: lexer parser

lexer:
	~/opt/flex/bin/flex --outfile=./lexer.cpp  --header-file=./lexer.h lexer.lpp

parser:
	~/opt/bison/bin/bison --output=./parser.cpp --report=state --defines=./parser.h parser.ypp
	#~/opt/bison/bin/bison --output=./parser.cpp --report=state -d parser.ypp
	# python3 comment_parser_header.py

test: lexer
	g++ lexer.cpp -o lexer

clean:
	rm lexer lexer.cpp
