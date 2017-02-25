#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH 1
#define HASH_TABLE_SIZE 42737

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
typedef struct __OTHER_PHONE_BOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} other_entry;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    /*
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    */
    other_entry *otherInfomation;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

entry *findName(char lastName[], entry *e[]);
void append(char lastName[], entry *e[]);
unsigned int BKDRHash(char *key);
void free_list(entry *e);

#endif
