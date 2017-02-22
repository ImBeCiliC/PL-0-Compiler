#ifndef PROCENTRY_H_
#define PROCENTRY_H_

#include "TableEntry.h"
#include <stdio.h>
#include <cstring>

class ProcEntry : public TableEntry
{
    public:
        // Constructor
        ProcEntry(const char*);
        ~ProcEntry();

        // Printout of the Proc Entry
        void print();
};

#endif //PROCENTRY_H_
