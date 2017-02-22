#ifndef TABLEENTRY_H_
#define TABLEENTRY_H_

#include <stdio.h>
#include <cstring>

class TableEntry
{
    private:
        int level;
        int index;
        const char* identifier;

    public:
        // Constructor needs to be public cause its used in the other Entry Types
        TableEntry(const char*);
        ~TableEntry();
        // returns the Level of the Entry
        int getLevel();
        // sets the Level of the Entry
        void setLevel(int);
        // return the Index of the Entry
        int getIndex();
        // sets the Index of the Entry
        void setIndex(int);
        // returns the Identifier of the Entry
        const char* getIdentifier();
        // sets the Entry of the Identifier
        void setIdentifier(const char*);
        // Is overwritten in the other Entry Types
        virtual void print() = 0;
};
#endif
