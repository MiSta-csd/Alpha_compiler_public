
parser: parser.cpp lex.yy.cpp
	g++ lex.yy.cpp parser.cpp -o parser

parser.cpp: parser.y	
	bison parser.y

lex.yy.cpp: scanner.l
	flex --outfile=lex.yy.cpp scanner.l

clean:
	rm -f parser lex.yy.cpp parser.cpp parser.hpp scanner.hpp
