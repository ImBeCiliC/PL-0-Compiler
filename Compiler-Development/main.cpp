#include <iostream>
#include "SymbolTable.h"
#include "TableEntry.h"
#include "AstBlock.h"

extern "C"
{
	#include "parser.tab.c"
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("fatal error: no input file");
	}
	else
	{
		FILE* pFile;
  		pFile = fopen (argv[1], "r");
		if (pFile != NULL)
  		{
  			//Eingabestrom aus Datei laden
			yyin = pFile;

			int pr = yyparse();
			if (pr == 0)
			{
				printf("Gültige Syntax\n\n");

				//Symboltabelle ausgeben
				SymbolTable::getInstance()->print();
				printf("\n");
			}

			fclose (pFile);
		}
	}
	return 0;
}
