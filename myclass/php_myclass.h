#ifndef _PHP_MYCLASS_H
    #define _PHP_MYCLASS_H
    #ifdef HAVE_CONFIG_H
        #include "config.h"
    #endif
    #ifdef ZTS
        #include <TSRM.h>
    #endif

    #include <php.h>

    extern zend_module_entry myclass_module_entry;
    PHP_MINIT_FUNCTION(myclass);
    PHP_METHOD(MyClass, __construct);
    PHP_METHOD(MyClass, getName);
    PHP_METHOD(MyClass, setName);
    PHP_METHOD(MyClass, helloWorld);
#endif
