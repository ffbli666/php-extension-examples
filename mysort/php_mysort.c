#include "php_mysort.h"

#if COMPILE_DL_MYSORT
    ZEND_GET_MODULE(mysort)
#endif

static const zend_function_entry mysort_functions[] = {
    PHP_FE(swap, NULL)
    PHP_FE(mysort, NULL)
    PHP_FE(myarray_sum, NULL)
    PHP_FE_END
};

zend_module_entry mysort_module_entry = {
    STANDARD_MODULE_HEADER,
    "Mysort",                       // your extension name
    mysort_functions,               // where you define your functions
    NULL, // PHP_MINIT(mysort),     // for module initialization
    NULL, // PHP_MSHUTDOWN(mysort), // for module shutdown process
    NULL, // PHP_RINIT(mysort)      // for request initialization
    NULL, // PHP_RSHUTDOWN(mysort)  // for reqeust shutdown process
    NULL, // PHP_MINFO(mysort),     // for providing module information
    "0.1",
    STANDARD_MODULE_PROPERTIES
};

static void _swap(zval *za, zval *zb) {
    zval tmp = *za;
    *za = *zb;
    *zb = tmp;
}

// Your functions here...
PHP_FUNCTION(swap) {
    zval *za = NULL;
    zval *zb = NULL;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &za, &zb) == FAILURE) {
        RETURN_FALSE;
    }
    _swap(za, zb);
    RETURN_TRUE;
}
/*
    Reference:
    http://www.phpinternalsbook.com/hashtables/hashtable_api.html
    http://www.phpinternalsbook.com/zvals/casts_and_operations.html
    http://devzone.zend.com/317/extension-writing-part-ii-parameters-arrays-and-zvals/
*/
PHP_FUNCTION(mysort) {
    zval *arr;
    zval **a, **b, *result, tmp;
    HashTable *arr_hash;
    int arr_count;
    int i, j;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &arr) == FAILURE) {
        RETURN_FALSE;
    }
    arr_hash = Z_ARRVAL_P(arr);
    arr_count = zend_hash_num_elements(arr_hash);
    MAKE_STD_ZVAL(result);
    for (i=0; i<arr_count; i++) {
        for (j=0; j<arr_count-1-i; j++) {
            zend_hash_index_find(arr_hash, j, (void **) &a);
            zend_hash_index_find(arr_hash, j+1, (void **) &b);
            compare_function(result, *a, *b TSRMLS_DC);
            if (Z_LVAL_P(result) > 0) {
                _swap(*a, *b);
            }
        }
    }

    RETURN_TRUE;
}

PHP_FUNCTION(myarray_sum) {
    zval *arr, **data;
    HashTable *arr_hash;
    HashPosition pointer;
    long sum = 0;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &arr) == FAILURE) {
        RETURN_FALSE;
    }

    arr_hash = Z_ARRVAL_P(arr);
    for(zend_hash_internal_pointer_reset_ex(arr_hash, &pointer);
        zend_hash_get_current_data_ex(arr_hash, (void**) &data, &pointer) == SUCCESS;
        zend_hash_move_forward_ex(arr_hash, &pointer)) {
        if (Z_TYPE_PP(data) == IS_LONG) {
            sum += Z_LVAL_PP(data);
        }
    }
    RETURN_LONG(sum);
}