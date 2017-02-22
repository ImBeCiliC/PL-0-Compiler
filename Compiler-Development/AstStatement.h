#ifndef ASTSTMT_H_
#define ASTSTMT_H_

#include "AstExpression.h"

class AstStatement
{
	public:
		AstStatement(int);
		~AstStatement();
		int token;
		char ident[20];
		AstExpression* expr;
		AstStatement* next;
		AstStatement* jump;
};

#endif //ASTSTMT
