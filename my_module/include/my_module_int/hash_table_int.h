/**
 * Internal header for hash table module
 */
#ifndef __HASH_TABLE_INT_H__
#define __HASH_TABLE_INT_H__

/* Maximum entries that can be stored in the hash table */
#define HASH_TABLE_SIZE 4

/* Maximum key/value size in the hash table */
#define MAX_STR_SIZE 127

/* Hash table node */
typedef struct
{
    char key[MAX_STR_SIZE + 1];
    char val[MAX_STR_SIZE + 1];
} hash_info_t;

/* Hash table data structure - Simple array! */
typedef struct
{
    hash_info_t hash_info[HASH_TABLE_SIZE];
    size_t next_empty_index;
} hash_table_t;

#endif /* __HASH_TABLE_INT_H__ */
