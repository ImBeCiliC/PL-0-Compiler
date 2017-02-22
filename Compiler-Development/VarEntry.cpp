#include "VarEntry.h"

VarEntry::VarEntry(const char* id) : TableEntry(id)
{

}

void VarEntry::print()
{
    printf("%d\t%d\t%s\t\tVAR\n", getLevel(), getIndex(), getIdentifier());
}
