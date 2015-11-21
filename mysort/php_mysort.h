#ifndef _PHP_MYSORT_H
  #define _PHP_MYSORT_H
  #ifdef HAVE_CONFIG_H
  #include "config.h"
#endif
#ifdef ZTS
  #include <TSRM.h>
#endif

#include <php.h>

extern zend_module_entry mysort_module_entry;

void _swap(zval *za, zval *zb);
PHP_FUNCTION(swap);
PHP_FUNCTION(mysort);


#endif
