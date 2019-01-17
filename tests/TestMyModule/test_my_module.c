/**
 * This C file looks like a test harness, but in reality
 * can be any binary which uses your C library.
 */
#include <stdio.h>
#include <string.h>

#include "my_module/add.h"
#include "my_module/sub.h"
#include "my_module/hash_table.h"

/**
 * Test function that uses `add` function of `my_module`
 * @return 0 on pass, -1 on failure
 */
static int
test_add(void)
{
    int a = 5, b = 7;
    return add(a, b) == a + b ? 0 : -1;
}

/**
 * Test function that uses `sub` function of `my_module`
 * @return 0 on pass, -1 on failure
 */
static int
test_sub(void)
{
    int a = 7, b = 5;
    return sub(a, b) == a - b ? 0 : -1;
}

/**
 * Test function that uses `hash_table_add` and `hash_table_get`
 * present in `my_module`.
 * @return 0 on pass, -1 on failure
 */
static int
test_hash_table(void)
{
    const char key_in[128] = "FOO", val_in[128] = "ABC";
    if (hash_table_add(key_in, val_in) < 0)
    {
        fprintf(stderr, "test_hash_table: Unable to set configuration\n");
        return -1;
    }

    char val_out[128] = "";
    if (hash_table_get(key_in, val_out) < 0)
    {
        fprintf(stderr, "test_hash_table: Unable to get configuration\n");
        return -1;
    }

    /* Compare the added value with the one fetched back */
    if (strcmp(val_in, val_out) != 0)
    {
        fprintf(stderr, "test_hash_table: mismatch\n");
        return -1;
    }

    if (hash_table_current_size() != 1)
    {
        fprintf(stderr, "test_hash_table: Size mismatch\n");
        return -1;
    }

    return 0;
}

int
main(void)
{

    if (test_add() < 0)
    {
        fprintf(stderr, "test_add: Failure\n");
        return -1;
    }
    printf("test_add: PASS\n");

    if (test_sub() < 0)
    {
        fprintf(stderr, "test_sub: Failure\n");
        return -1;
    }
    printf("test_sub: PASS\n");

    if (test_hash_table() < 0)
    {
        fprintf(stderr, "test_hash_table: Failure\n");
        return -1;
    }
    printf("test_hash_table: PASS\n");

    return 0;
}