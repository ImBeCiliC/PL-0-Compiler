#ifndef CONSTENTRY_H_
#define CONSTENTRY_H_

#include "TableEntry.h"
#include <stdio.h>
#include <cstring>

class ConstEntry : public TableEntry
{
    private:
        int value;

    public:

        ConstEntry(const char*);
        ~ConstEntry();

        // returns the Value of the Const
        int getValue();

        // sets the Value of the Const
        void setValue(int);

        // Printout of the Const Entry
        void print();
};

#endif //CONSTENTRY_H_
