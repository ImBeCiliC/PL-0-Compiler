#include "AstStatement.h"

AstStatement::AstStatement(int tok)
{
	token = tok;
	next = NULL;
	expr = NULL;
}

AstStatement::~AstStatement()
{
	delete expr;
	delete next;
	delete jump;
}
