#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include "TableEntry.h"

using std::cout;
using std::endl;

class SymbolTable
{
        private:
            int level;
            int maxDepth;
            std::vector<TableEntry*> entries[20];
            SymbolTable();
            ~SymbolTable();
            static SymbolTable* pInstance;

        public:
            // returns the Instanz of the Singleton
            static SymbolTable* getInstance();

            // inserts new entry into the symboltabel
            void insert(TableEntry*);

            // search for a entry
            TableEntry* lookup(TableEntry*);

            // increase the level
            void level_up();

            // decrease the level
            void level_down();

            // set level to the value
            void setLevel(int);

            // returns current level
            int getLevel();

            // prints out every entry of the symboltable
            void print();
};

#endif
