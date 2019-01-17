#include <string.h>

#include "hash_table_int.h"
#include "hash_table.h"

/* Hash table - Private */
static hash_table_t hash_table[1];

/**
 * Function to add a key to the hash table
 * @param key_in Key to add
 * @param val_in Value associated with the key
 * @return 0 on success, -1 on failure
 */
int hash_table_add(const char *key_in, const char *val_in)
{
    /* Sanity on key and value null pointers */
    if (!key_in)
    {
        /* Key is null */
        return -1;
    }
    if (!val_in)
    {
        /* Value is null */
        return -2;
    }

    /* Sanity on key and value null strings */
    if (!*key_in)
    {
        /* Key is empty */
        return -3;
    }
    if (!*val_in)
    {
        /* Value is empty */
        return -4;
    }

    /* Sanity on key and value string lengths */
    if (strlen(key_in) > MAX_STR_SIZE)
    {
        /* Key is too long */
        return -5;
    }
    if (strlen(val_in) > MAX_STR_SIZE)
    {
        /* Value is too long */
        return -6;
    }

    /* Get the index */
    size_t next_index = hash_table->next_empty_index;

    /* Sanity on the index */
    if (next_index >= HASH_TABLE_SIZE)
    {
        /* Hash table is full */
        return -7;
    }

    size_t i;
    for (i = 0; i < next_index; ++i)
    {
        if (!strcmp(hash_table->hash_info[i].key, key_in))
        {
            /* Hash table already exists */
            return -8;
        }
    }

    strcpy(hash_table->hash_info[next_index].key, key_in);
    strcpy(hash_table->hash_info[next_index].val, val_in);
    ++hash_table->next_empty_index;

    return 0;
}


/**
 * Get the value associated with a key in the hash table
 * @param key_in Key to fetch the value for
 * @param val_out Value pointer (will be filled)
 * @return 0 on success, < 0 on failure
 *
 * NOTE: Please don't forget to populate the rc_dict in the SWIG file
 */
int hash_table_get(const char *key_in, char *val_out)
{
    /* Sanity on key and value null pointers */
    if (!key_in)
    {
        return -1;
    }
    if (!val_out)
    {
        return -2;
    }
    if (key_in[0] == '\0')
    {
        return -3;
    }

    val_out[0] = '\0';

    /* Sanity on key */
    if (strlen(key_in) > MAX_STR_SIZE)
    {
        return -4;
    }

    size_t max_index = hash_table->next_empty_index, i;
    for (i = 0; i < max_index; ++i)
    {
        if (!strcmp(hash_table->hash_info[i].key, key_in))
        {
            strcpy(val_out, hash_table->hash_info[i].val);
            break;
        }
    }
    if (i >= max_index)
    {
        return -5;
    }

    return 0;
}

/**
 * Return the current size of the hash table
 *
 * This is equal to the number of keys present in it
 *
 * @return A positive number or zero
 */
size_t hash_table_current_size(void)
{
    return hash_table->next_empty_index;
}
