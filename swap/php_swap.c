#include "php_swap.h"

#if COMPILE_DL_SWAP
ZEND_GET_MODULE(swap)
#endif

static const zend_function_entry swap_functions[] = {
  PHP_FE(swap, NULL)
  PHP_FE_END
};

zend_module_entry swap_module_entry = {
  STANDARD_MODULE_HEADER,
  "Swap",                       // your extension name
  swap_functions,               // where you define your functions
  NULL, // PHP_MINIT(swap),     // for module initialization
  NULL, // PHP_MSHUTDOWN(swap), // for module shutdown process
  NULL, // PHP_RINIT(swap)      // for request initialization
  NULL, // PHP_RSHUTDOWN(swap)  // for reqeust shutdown process
  NULL, // PHP_MINFO(swap),     // for providing module information
  "0.1",
  STANDARD_MODULE_PROPERTIES
};

// Remove the comment if you want to initiazlie something (class entry, resource entry, constants ... etc)
/*
PHP_MINIT_FUNCTION(swap) {
  return SUCCESS;
}
PHP_MSHUTDOWN_FUNCTION(swap) {
  return SUCCESS;
}
*/

//PHP_MINFO_FUNCTION(swap) {}

// Your functions here...
PHP_FUNCTION(swap) {
    zval *za = NULL;
    zval *zb = NULL;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &za, &zb) == FAILURE) {
        RETURN_FALSE;
    }
    zval tmp = *za;
    *za = *zb;
    *zb = tmp;
    RETURN_TRUE;
}
