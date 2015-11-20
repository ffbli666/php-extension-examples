PHP_ARG_ENABLE(swap, whether to enable swap extension support, 
  [--enable-swap Enable swap extension support])

if test $PHP_SWAP != "no"; then
    PHP_NEW_EXTENSION(swap, php_swap.c, $ext_shared)
fi
