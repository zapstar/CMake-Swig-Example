/**
 * Exposed header for public use - Hash table module
 */
#ifndef __MY_MODULE_H__
#define __MY_MODULE_H__

/* Add a key to the hash table */
int hash_table_add(const char *key_in, const char *val_in);

/* Get the added keys from the hash table */
int hash_table_get(const char *key_in, char *val_out);

/* Get the current size of the hash table */
size_t hash_table_current_size(void);

#endif /* __MY_MODULE_H__ */
