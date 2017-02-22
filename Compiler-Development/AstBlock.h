#ifndef ASTBLOCK_H_
#define ASTBLOCK_H_

#include "AstStatement.h"
#include "AstIdentifier.h"
#include <iostream>

class AstBlock
{
	public:
		AstBlock(AstIdentifier*, AstIdentifier*, AstBlock*, AstStatement*);
		~AstBlock();
		char ident[20];
		AstBlock* sub;
		AstBlock* next;
		AstStatement* stmt;
		AstIdentifier* identifier;
		AstIdentifier* constants;
		void print();
};

#endif //ASTBLOCK
