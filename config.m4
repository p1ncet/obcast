PHP_ARG_ENABLE(obcast, whether to enable Object casting support,
[ --enable-obcast Enable Object Casting support])

if test "$PHP_OBCAST" = "yes"; then
	AC_DEFINE(HAVE_OBCAST, 1, [Whether you have Object Casting])
	PHP_NEW_EXTENSION(obcast, obcast.c, $ext_shared)
fi
