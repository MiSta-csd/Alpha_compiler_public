
parser: parser.cpp lex.yy.cpp symtable.cpp quads.cpp
	g++ lex.yy.cpp parser.cpp symtable.cpp quads.cpp -o $@ -g

hashmap_parser: parser.cpp lex.yy.cpp kostas_sym.cpp quads.cpp
	g++ lex.yy.cpp parser.cpp kostas_sym.cpp quads.cpp -o $@

parser.cpp: parser.y	
	bison parser.y

lex.yy.cpp: scanner.l
	flex --outfile=lex.yy.cpp scanner.l

clean:
	rm -f parser hashmap_parser lex.yy.cpp parser.cpp parser.hpp
