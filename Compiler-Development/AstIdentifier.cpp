#include "AstIdentifier.h"

AstIdentifier::AstIdentifier(const char* id)
{
	strcpy(name, id);
}

AstIdentifier::~AstIdentifier()
{
	delete name;
}
