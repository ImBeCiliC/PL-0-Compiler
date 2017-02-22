#include"AstBlock.h"

AstBlock::AstBlock(AstIdentifier* con, AstIdentifier* id, AstBlock* subBlock, AstStatement* astStmt)
{
	sub = subBlock;
	next = NULL;
	stmt = astStmt;
	identifier = id;
	constants = con;
}

AstBlock::~AstBlock()
{
	delete sub;
	delete next;
	delete stmt;
	delete identifier;
	delete constants;
}

void AstBlock::print()
{
	std::cout << "Block \"" << ident << "\"" << std::endl;
	
	while (sub)
	{
		sub->print();
		sub = sub->next;
	}
}
