#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "zend_interfaces.h"
#include "php_obcast.h"

#ifdef COMPILE_DL_OBCAST
ZEND_GET_MODULE(obcast)
#endif

PHPAPI zend_class_entry *obcast_ce_Boolable;

ZEND_BEGIN_ARG_INFO(arginfo_boolable_to_boolean, 0)
ZEND_END_ARG_INFO()

static zend_object_handlers obcast_object_handlers;

static const zend_function_entry obcast_funcs_Boolable[] = {
	ZEND_ABSTRACT_ME(Boolable, __toBoolean, arginfo_boolable_to_boolean)
	PHP_FE_END
};

static int obcast_object_cast(zval *in, zval *out, int type) {
	if (type == _IS_BOOL) {
		zval tmp;
		zend_call_method_with_0_params(in, NULL, NULL, "__toBoolean", &tmp);
		ZVAL_BOOL(out, i_zend_is_true(&tmp));
		return SUCCESS;
	} else {
		return std_object_handlers.cast_object(in, out, type);
	}
}

static zend_object *obcast_object_new(zend_class_entry *ce) {
	zend_object *object;
	object = zend_objects_new(ce);
	object_properties_init(object, ce);
	object->handlers = &obcast_object_handlers;
	return object;
}

static int obcast_implemented(zend_class_entry *interface, zend_class_entry *ce TSRMLS_DC) {
    if (ce->create_object != NULL) {
        zend_error(E_ERROR, "Boolable interface can only be used on userland classes");
    }
    ce->create_object = obcast_object_new;
    return SUCCESS;
}

PHP_MINIT_FUNCTION(obcast_init) {
	memcpy(&obcast_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	obcast_object_handlers.cast_object = obcast_object_cast;
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Boolable", obcast_funcs_Boolable);
	ce.interface_gets_implemented = obcast_implemented;
	obcast_ce_Boolable = zend_register_internal_interface(&ce);
	return SUCCESS;
}

zend_module_entry obcast_module_entry = {
  STANDARD_MODULE_HEADER,
  "obcast",
  NULL,
  PHP_MINIT(obcast_init),
  NULL,
  NULL,
  NULL,
  NULL,
  PHP_OBCAST_VERSION,
  STANDARD_MODULE_PROPERTIES
};
