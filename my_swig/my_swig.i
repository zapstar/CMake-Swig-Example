%module my_swig
%include <cstring.i>

%{
#include "my_module/hash_table.h"
%}

%pythonappend hash_table_add {
    try:
        rc_dict = {
            -1: "Key is null",
            -2: "Value is null",
            -3: "Key is empty",
            -4: "Value is empty",
            -5: "Key too long",
            -6: "Value too long",
            -7: "Pre-allocated table is full",
            -8: "Hash table entry already exists",
        }
        rc, val = val, None
        if rc < 0:
            err_msg = rc_dict[rc] if rc in rc_dict else "Unknown Error"
            raise RuntimeError(err_msg)
    except RuntimeError:
        raise
    except Exception as err:
        raise RuntimeError("Internal SWIG Error - hash_table_add: ", repr(err))
}

/* Designate val_out as output value */
%cstring_bounded_output(char *val_out, 128);

%pythonappend hash_table_get {
    try:
        rc_dict = {
                -1: "Key array is null",
                -2: "Value array is null",
                -3: "Key is empty",
                -4: "Key is too long",
                -5: "Key not found",
        }
        rc, val = val
        if rc < 0:
            err_msg = rc_dict[rc] if rc in rc_dict else "Unknown Error"
            raise RuntimeError(err_msg)
    except RuntimeError:
        raise
    except Exception as err:
        raise RuntimeError("Internal SWIG Error - hash_table_get: ", repr(err))
}

/* We want all functions in `add.h` to be exposed in Python */
%include <my_module/add.h>

/* We don't want any functions in `sub.h` to be exposed in Python */

/* We want get & set functions in `hash_table.h` to be exposed in Python */
int hash_table_add(const char *key_in, const char *val_in);
int hash_table_get(const char *key_in, char *val_out);
