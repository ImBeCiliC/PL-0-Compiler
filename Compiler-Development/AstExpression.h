#ifndef ASTEXPR_H_
#define ASTEXPR_H_

#include <cstring>

class AstExpression
{
	public:
		AstExpression(const char*, AstExpression*, AstExpression*);
		~AstExpression();
		char ident[20];
		AstExpression* left;
		AstExpression* right;		
};

#endif //ASTSTMT
