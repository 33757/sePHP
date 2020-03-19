
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/require.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(SePHP_View) {

	ZEPHIR_REGISTER_CLASS(SePHP, View, sephp, view, sephp_view_method_entry, 0);

	zend_declare_property_null(sephp_view_ce, SL("templatePath"), ZEND_ACC_PUBLIC);

	return SUCCESS;

}

PHP_METHOD(SePHP_View, __construct) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tpl_param = NULL, _1, _2, _3$$4, _4$$4, _5$$5;
	zval tpl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tpl);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &tpl_param);

	if (!tpl_param) {
		ZEPHIR_INIT_VAR(&tpl);
		ZVAL_STRING(&tpl, "");
	} else {
		zephir_get_strval(&tpl, tpl_param);
	}


	_0 = !ZEPHIR_IS_STRING(&tpl, "");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(&tpl, "");
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "ROOT_PATH");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 1, &_1);
	zephir_check_call_status();
	if (_0) {
		zephir_update_property_zval(this_ptr, SL("templatePath"), &tpl);
	} else if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_GET_CONSTANT(&_3$$4, "ROOT_PATH");
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_VS(&_4$$4, &_3$$4, "/Template");
		zephir_update_property_zval(this_ptr, SL("templatePath"), &_4$$4);
	} else {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "");
		zephir_update_property_zval(this_ptr, SL("templatePath"), &_5$$5);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_View, assign) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key, key_sub, *value, value_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/(^[a-zA-Z_]$)|(^[a-zA-Z_][a-zA-Z_0-9]+$)/");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/(^[a-zA-Z_]$)|(^[a-zA-Z_][a-zA-Z_0-9]+$)/");
	zephir_preg_match(&_2, &_3, key, &_0, 0, 0 , 0 );
	if (ZEPHIR_IS_LONG(&_2, 1)) {
		zephir_update_property_zval_zval(this_ptr, key, value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_View, _fetch) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *template_param = NULL, finalFile, _0, _1;
	zval template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&finalFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &template_param);

	if (!template_param) {
		ZEPHIR_INIT_VAR(&template);
		ZVAL_STRING(&template, "");
	} else {
		zephir_get_strval(&template, template_param);
	}


	ZEPHIR_INIT_VAR(&finalFile);
	ZVAL_STRING(&finalFile, "");
	zephir_read_property(&_0, this_ptr, SL("templatePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&finalFile);
	ZEPHIR_CONCAT_VSV(&finalFile, &_0, "/", &template);
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 10, &finalFile);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 11);
		zephir_check_call_status();
		if (zephir_require_zval(&finalFile) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 12);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETURN_MM_BOOL(0);
	}

}

PHP_METHOD(SePHP_View, display) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *template_param = NULL, content, _0$$4;
	zval template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &template_param);

	if (!template_param) {
		ZEPHIR_INIT_VAR(&template);
		ZVAL_STRING(&template, "");
	} else {
		zephir_get_strval(&template, template_param);
	}


	ZEPHIR_CALL_METHOD(&content, this_ptr, "_fetch", NULL, 0, &template);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		zend_print_zval(&content, 0);
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "Template does not exist");
		ZEPHIR_MM_RESTORE();
		zephir_exit(&_0$$4);
	}
	ZEPHIR_MM_RESTORE();

}

