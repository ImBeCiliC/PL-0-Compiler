#include "TableEntry.h"

using namespace std;

TableEntry::TableEntry(const char* id)
{
    setIdentifier(id);
}

TableEntry::~TableEntry()
{
}

int TableEntry::getLevel()
{
    return level;
}

int TableEntry::getIndex()
{
    return index;
}

void TableEntry::setIndex(int ind)
{
    index = ind;
}

void TableEntry::setLevel(int lev)
{
    level = lev;
}

const char* TableEntry::getIdentifier()
{
    return identifier;
}

void TableEntry::setIdentifier(const char* ident)
{
    identifier = ident;
}
