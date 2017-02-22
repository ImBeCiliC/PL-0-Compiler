#include "ProcEntry.h"

ProcEntry::ProcEntry(const char* id) : TableEntry(id)
{

}

void ProcEntry::print()
{
    printf("%d\t%d\t%s\t\tPROC\n", getLevel(), getIndex(), getIdentifier());
}
