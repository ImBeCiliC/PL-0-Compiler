ReadMe:

To Compile the Files install Flex, Bison and g++ (not tested with gcc) on your Computer

1. Open Command Prompt in the Folder
2. Flex -l scanner.lex
3. Bison -d parser.y
4. g++ -g -o Parser main.cpp SymbolTable.cpp TableEntry.cpp VarEntry.cpp ConstEntry.cpp ProcEntry.cpp AstExpression.cpp AstStatement.cpp AstBlock.cpp AstIdentifier.cpp

After these Steps the Parser.exe is generated.

5. Parser.exe "Add Testing File without quotion marks"
6 Result of the Symboltable and AST should be shown in the Command Prompt