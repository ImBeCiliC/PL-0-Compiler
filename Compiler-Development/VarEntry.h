#ifndef VARENTRY_H_
#define VARENTRY_H_

#include "TableEntry.h"
#include <stdio.h>
#include <cstring>

class VarEntry : public TableEntry
{
    private:
        int value;

    public:
        // Constructor
        VarEntry(const char*);
        ~VarEntry();

        // returns the Value of the Var
        int getValue();

        // sets the Value of the Var
        void setValue(int);

        // Printout of the Var Entry
        void print();
};

#endif //VARENTRY_H_
