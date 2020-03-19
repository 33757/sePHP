
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(sephp_0__closure) {

	ZEPHIR_REGISTER_CLASS(sephp, 0__closure, sephp, 0__closure, sephp_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(sephp_0__closure_ce, SL("classSuffix"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(sephp_0__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval cName;
	zval classSuffix, *cName_param = NULL, fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classSuffix);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&cName);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&classSuffix, sephp_0__closure_ce, SL("classSuffix"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &cName_param);

	zephir_get_strval(&cName, cName_param);


	ZEPHIR_INIT_VAR(&fileName);
	ZEPHIR_CONCAT_VV(&fileName, &cName, &classSuffix);
	if (zephir_require_zval(&fileName) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

