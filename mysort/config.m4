PHP_ARG_ENABLE(mysort, whether to enable mysort extension support, 
  [--enable-mysort Enable mysort extension support])

if test $PHP_MYSORT != "no"; then
    PHP_NEW_EXTENSION(mysort, php_mysort.c, $ext_shared)
fi
