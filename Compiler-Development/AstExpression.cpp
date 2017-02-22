#include"AstExpression.h"

AstExpression::AstExpression(const char* id, AstExpression* l, AstExpression* r)
{
	strcpy(ident, id);
	left = l;
	right = r;
}

AstExpression::~AstExpression()
{
	delete right;
	delete left;
}
