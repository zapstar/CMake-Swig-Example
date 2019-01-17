import my_swig


def test_add():
    """
    Run tests to see if `add` in `my_swig` works correctly
    :return:
    """
    from random import randint
    a = randint(1, 100)
    b = randint(100, 200)
    assert my_swig.add(a, b) == a + b


def test_hash_table():
    """
    Run tests to see if `hash_table_add` and `hash_table_get`
    from `my_swig` work correctly
    :return:
    """
    key = "foo_key"
    val = "foo_val"
    try:
        my_swig.hash_table_add(key, val)
        assert my_swig.hash_table_get(key) == val
    except RuntimeError:
        raise AssertionError('Internal Error')


if __name__ == '__main__':
    try:
        test_add()
        test_hash_table()
        print("Tests passed")
    except AssertionError:
        print("Tests FAILURE")
