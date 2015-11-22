#include "php_myclass.h"

#if COMPILE_DL_MYCLASS
    ZEND_GET_MODULE(myclass)
#endif
/*
    Reference:
    http://www.phpinternalsbook.com/classes_objects/simple_classes.html
    http://www.kchodorow.com/blog/2011/08/11/php-extensions-made-eldrich-classes/
    http://www.walu.cc/phpbook/preface.md
 */

zend_class_entry *myclass_ce;
/*
    flag have ZEND_ACC_PUBLIC, ZEND_ACC_PROTECTED, ZEND_ACC_PRIVATE, ZEND_ACC_STATIC, ZEND_ACC_FINAL and ZEND_ACC_ABSTRACT
 */
static const zend_function_entry myclass_functions[] = {
    PHP_ME(MyClass, __construct,        NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(MyClass, getName,            NULL, ZEND_ACC_PUBLIC)
    PHP_ME(MyClass, setName,            NULL, ZEND_ACC_PUBLIC)
    PHP_ME(MyClass, helloWorld,         NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};


zend_module_entry myclass_module_entry = {
    STANDARD_MODULE_HEADER,
    "myclass",                       // your extension name
    NULL,                            // where you define your functions
    PHP_MINIT(myclass),               // for module initialization
    NULL, // PHP_MSHUTDOWN(myclass), // for module shutdown process
    NULL, // PHP_RINIT(myclass)      // for request initialization
    NULL, // PHP_RSHUTDOWN(myclass)  // for reqeust shutdown process
    NULL, // PHP_MINFO(myclass),     // for providing module information
    "0.1",
    STANDARD_MODULE_PROPERTIES
};

PHP_MINIT_FUNCTION(myclass)
{
    zend_class_entry tmp_ce;
    INIT_CLASS_ENTRY(tmp_ce, "MyClass", myclass_functions);
    myclass_ce = zend_register_internal_class(&tmp_ce TSRMLS_CC);
    return SUCCESS;
}

PHP_METHOD(MyClass, __construct)
{
    char *name = NULL;
    int name_len;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|", &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }
    zend_update_property_stringl(myclass_ce, getThis(), "name", sizeof("name") - 1, name, name_len TSRMLS_CC);
}

PHP_METHOD(MyClass, getName)
{
    zval *name = NULL;
    if (zend_parse_parameters_none() == FAILURE) {
        RETURN_FALSE;
    }
    name = zend_read_property(myclass_ce, getThis(), "name", sizeof("name") - 1, 1 TSRMLS_CC);
    RETURN_STRING(Z_STRVAL_P(name), 1);
}

PHP_METHOD(MyClass, setName)
{
    char *name = NULL;
    int name_len;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|", &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }
    zend_update_property_stringl(myclass_ce, getThis(), "name", sizeof("name") - 1, name, name_len TSRMLS_CC);
}

PHP_METHOD(MyClass, helloWorld)
{
    if (zend_parse_parameters_none() == FAILURE) {
        RETURN_FALSE;
    }

    RETURN_STRING("Hello World", 1);
}

