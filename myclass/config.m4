PHP_ARG_ENABLE(myclass, whether to enable myclass extension support,
  [--enable-myclass Enable myclass extension support])

if test $PHP_MYCLASS != "no"; then
    PHP_NEW_EXTENSION(myclass, php_myclass.c, $ext_shared)
fi
