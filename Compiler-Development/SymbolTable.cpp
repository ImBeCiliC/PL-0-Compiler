#include "SymbolTable.h"

SymbolTable* SymbolTable::pInstance = 0;

SymbolTable* SymbolTable::getInstance()
{
    if(pInstance == 0)
        pInstance = new SymbolTable();

    return pInstance;
}

SymbolTable::SymbolTable() : maxDepth(0)
{
    setLevel(-1);
}

SymbolTable::~SymbolTable()
{

}

int SymbolTable::getLevel()
{
    return level;
}

void SymbolTable::setLevel(int lev)
{
    level = lev;
}

void SymbolTable::level_up()
{
    cout << "Level Up" << endl;
    level++;

    // refresh max depfh
    if(level > maxDepth)
        maxDepth = level;
}

void SymbolTable::level_down()
{
    cout << "Level Down" << endl;
    // Level can't be under 0
    if(level > 0)
        level --;
}

void SymbolTable::insert(TableEntry* entry)
{
    //get level and set TableEntry to specific level
    int level = getLevel();
    entry->setLevel(level);

    // set index of the TableEntry
    entry->setIndex(entries[level].size());

    //insert the entry to the vector entries array
    entries[level].push_back(entry);
}

TableEntry* SymbolTable::lookup(TableEntry* entry)
{
    // load current level and search for entry if entry is not on the level do a level - down
    // and research if nothing is found in the SymbolTable return NULL
    int current = getLevel();

    // used for debugging no need to print on screen
    cout << "Level: " << current << endl;
    cout << "Identifier: " << entry->getIdentifier() << endl;

    // go through all level
    while(current >= 0)
    {
        // go through every index in the level
        for(int index = 0; index < entries[current].size(); index++)
        {
            // do a string compare with the entry identifier and the identifier of current index
            if(strcmp(entries[current].at(index)->getIdentifier(), entry->getIdentifier()) == 0)
            {
                // do a string compare with the name of the current index and the entry
                // to check if the type matches
                const char* a = typeid(*entries[current].at(index)).name();
                const char* b = typeid(*entry).name();

                if(strcmp(a, b) == 0)
                {
                    return entries[current].at(index);
                }
            }
        }
        current--;
    }

    // nothing found in the SymbolTable
    return NULL;
}

void SymbolTable::print()
{
    cout << "Symboltabelle: " << endl;
    // go through all Level
    for(int level = 0; level < maxDepth; level++)
    {
        // go through every entry
        for(int index = 0; index < entries[level].size(); index++)
        {
            // select the vector and print it
            entries[level].at(index)->print();
        }
        printf("\n");
    }
}

