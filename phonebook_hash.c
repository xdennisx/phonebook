#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

unsigned int BKDRHash(char* key)
{
    unsigned int seed = 31;
    unsigned int hash = 0;

    while (*key) {
        hash = hash * seed + (*key++);
    }

    return hash & 0x7FFFFFFF;
}

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *e[])
{
    /* TODO: implement */
    unsigned int hash_index = (BKDRHash(lastName) % HASH_TABLE_SIZE);
    entry *pHead = e[hash_index]->pNext;
    while (pHead) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

void append(char lastName[], entry *e[])
{
    /* allocate memory for the new entry and put lastName */
    unsigned int hash_index = (BKDRHash(lastName) % HASH_TABLE_SIZE);
    e[hash_index]->pNext = (entry *) malloc(sizeof(entry));
    entry *pHead = e[hash_index]->pNext;
    strcpy(pHead->lastName, lastName);
    pHead->pNext = NULL;
    e[hash_index] = pHead;
}

void free_list(entry *pHead)
{
    while(pHead->pNext) {
        entry *temp = pHead->pNext;
        pHead->pNext = temp->pNext;
        free(temp);
    }
}
