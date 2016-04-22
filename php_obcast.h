#ifndef PHP_OBCAST_H
#define PHP_OBCAST_H 1

#define PHP_OBCAST_VERSION "1.0"

extern PHPAPI zend_class_entry *obcast_ce_Boolable;
extern zend_module_entry obcast_module_entry;

#define phpext_obcast_ptr &obcast_module_entry

static int obcast_object_cast(zval *readobj, zval *writeobj, int type);
static zend_object *obcast_object_new(zend_class_entry *class_type);
static int obcast_implemented(zend_class_entry *interface, zend_class_entry *ce TSRMLS_DC);

PHP_MINIT_FUNCTION(obcast_init);

#endif
