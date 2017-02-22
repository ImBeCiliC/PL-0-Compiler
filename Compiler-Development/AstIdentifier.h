#ifndef ASTID_H_
#define ASTID_H_

#include <cstring>

class AstIdentifier
{
	public:
		AstIdentifier(const char*);
		~AstIdentifier();
		char name[20];
		int value;	//Für Konstanten
		AstIdentifier* next;
};

#endif //ASTID
