#include "ConstEntry.h"

ConstEntry::ConstEntry(const char* id) : TableEntry(id)
{

}

void ConstEntry::print()
{
    printf("%d\t%d\t%s\t\tCONST\n", getLevel(), getIndex(), getIdentifier());
}
