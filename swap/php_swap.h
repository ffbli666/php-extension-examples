#ifndef _PHP_SWAP_H
  #define _PHP_SWAP_H
  #ifdef HAVE_CONFIG_H
  #include "config.h"
#endif
#ifdef ZTS
  #include <TSRM.h>
#endif

#include <php.h>

extern zend_module_entry swap_module_entry;

//PHP_MINIT_FUNCTION(swap);
//PHP_MSHUTDOWN_FUNCTION(swap);
//PHP_MINFO_FUNCTION(swap);

PHP_FUNCTION(swap);


#endif
