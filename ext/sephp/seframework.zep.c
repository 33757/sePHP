
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
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(SePHP_SeFramework) {

	ZEPHIR_REGISTER_CLASS(SePHP, SeFramework, sephp, seframework, sephp_seframework_method_entry, 0);

	zend_declare_property_null(sephp_seframework_ce, SL("className"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(sephp_seframework_ce, SL("funcName"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(sephp_seframework_ce, SL("params"), ZEND_ACC_PRIVATE);

	zend_declare_property_string(sephp_seframework_ce, SL("rootPath"), "../", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("actionPath"), "Action", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("modelPath"), "Model", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("commonPath"), "Common", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("confPath"), "Conf", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("defaultAction"), "Index", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("defaultFunc"), "index", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("defaultRouter"), "", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("actionClassSuffix"), "Action", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("actionFuncSuffix"), "", ZEND_ACC_PUBLIC);

	zend_declare_property_string(sephp_seframework_ce, SL("classSuffix"), ".class.php", ZEND_ACC_PUBLIC);

	zend_declare_property_null(sephp_seframework_ce, SL("includePath"), ZEND_ACC_PUBLIC);

	zend_declare_property_bool(sephp_seframework_ce, SL("enablePrettyUrl"), 1, ZEND_ACC_PUBLIC);

	sephp_seframework_ce->create_object = zephir_init_properties_SePHP_SeFramework;
	return SUCCESS;

}

PHP_METHOD(SePHP_SeFramework, __construct) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rootPath_param = NULL, _1, _2, _3$$4;
	zval rootPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rootPath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &rootPath_param);

	if (!rootPath_param) {
		ZEPHIR_INIT_VAR(&rootPath);
		ZVAL_STRING(&rootPath, "");
	} else {
		zephir_get_strval(&rootPath, rootPath_param);
	}


	_0 = !ZEPHIR_IS_STRING(&rootPath, "");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(&rootPath, "");
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "ROOT_PATH");
	ZEPHIR_CALL_FUNCTION(&_2, "defined", NULL, 1, &_1);
	zephir_check_call_status();
	if (_0) {
		zephir_update_property_zval(this_ptr, SL("rootPath"), &rootPath);
	} else if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_GET_CONSTANT(&_3$$4, "ROOT_PATH");
		zephir_update_property_zval(this_ptr, SL("rootPath"), &_3$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_setpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_setdefaultrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_SeFramework, _setPath) {

	zval _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("rootPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("actionPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &_0, "", &_1);
	zephir_update_property_zval(this_ptr, SL("actionPath"), &_2);
	zephir_read_property(&_3, this_ptr, SL("rootPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("modelPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSV(&_5, &_3, "", &_4);
	zephir_update_property_zval(this_ptr, SL("modelPath"), &_5);
	zephir_read_property(&_6, this_ptr, SL("rootPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, SL("commonPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VSV(&_8, &_6, "", &_7);
	zephir_update_property_zval(this_ptr, SL("commonPath"), &_8);
	zephir_read_property(&_9, this_ptr, SL("rootPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_10, this_ptr, SL("confPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_VSV(&_11, &_9, "", &_10);
	zephir_update_property_zval(this_ptr, SL("confPath"), &_11);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_SeFramework, _setDefaultRouter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *action = NULL, action_sub, *func = NULL, func_sub, _0, _1$$5, _2$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &action, &func);

	if (!action) {
		action = &action_sub;
		ZEPHIR_INIT_VAR(action);
		ZVAL_STRING(action, "");
	}
	if (!func) {
		func = &func_sub;
		ZEPHIR_INIT_VAR(func);
		ZVAL_STRING(func, "");
	}


	if (!ZEPHIR_IS_STRING(action, "")) {
		zephir_update_property_zval(this_ptr, SL("defaultAction"), action);
	}
	if (!ZEPHIR_IS_STRING(func, "")) {
		zephir_update_property_zval(this_ptr, SL("defaultFunc"), func);
	}
	zephir_read_property(&_0, this_ptr, SL("enablePrettyUrl"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE(&_0)) {
		zephir_read_property(&_1$$5, this_ptr, SL("defaultAction"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$5, this_ptr, SL("defaultFunc"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_VSV(&_3$$5, &_1$$5, "/", &_2$$5);
		zephir_update_property_zval(this_ptr, SL("defaultRouter"), &_3$$5);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_SeFramework, prettyRouter) {

	zend_bool _6, _9, _13, _16, _3$$4, _28$$8, _29$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, k, i;
	zval _SERVER, _GET, _0$$3, agvArr, _1, arrLength, _5, agvArrLength, _7, _8, _10, _11, _14, _15, _17, _18, _20, _21, _22, _23, _24, _25, _26, _27, _2$$4, _4$$4, _12$$6, _19$$7, _30$$8, _31$$8, _32$$8, _33$$8, _34$$8, _35$$9, _36$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&agvArr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrLength);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&agvArrLength);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_SERVER, SL("_SERVER"));

	if (!(zephir_array_isset_string(&_SERVER, SL("PATH_INFO")))) {
		zephir_read_property(&_0$$3, this_ptr, SL("defaultRouter"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&_SERVER, SL("PATH_INFO"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_array_fetch_string(&_1, &_SERVER, SL("PATH_INFO"), PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 64);
	ZEPHIR_INIT_VAR(&agvArr);
	zephir_fast_explode_str(&agvArr, SL("/"), &_1, LONG_MAX);
	ZEPHIR_INIT_VAR(&arrLength);
	ZVAL_LONG(&arrLength, zephir_fast_count_int(&agvArr));
	k = 0;
	while (1) {
		if (!(ZEPHIR_GT_LONG(&arrLength, k))) {
			break;
		}
		zephir_array_fetch_long(&_2$$4, &agvArr, k, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 69);
		_3$$4 = Z_TYPE_P(&_2$$4) == IS_NULL;
		if (!(_3$$4)) {
			zephir_array_fetch_long(&_4$$4, &agvArr, k, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 69);
			_3$$4 = ZEPHIR_IS_STRING(&_4$$4, "");
		}
		if (_3$$4) {
			zephir_array_unset_long(&agvArr, k, PH_SEPARATE);
		}
		k++;
	}
	ZEPHIR_CALL_FUNCTION(&_5, "array_values", NULL, 2, &agvArr);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&agvArr, &_5);
	ZEPHIR_INIT_VAR(&agvArrLength);
	ZVAL_LONG(&agvArrLength, zephir_fast_count_int(&agvArr));
	_6 = !(zephir_array_isset_long(&agvArr, 0));
	if (!(_6)) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_array_fetch_long(&_8, &agvArr, 0, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 78);
		zephir_fast_trim(&_7, &_8, NULL , ZEPHIR_TRIM_BOTH);
		_6 = ZEPHIR_IS_STRING(&_7, "");
	}
	_9 = _6;
	if (!(_9)) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_array_fetch_long(&_11, &agvArr, 0, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 78);
		zephir_fast_trim(&_10, &_11, NULL , ZEPHIR_TRIM_BOTH);
		_9 = Z_TYPE_P(&_10) == IS_NULL;
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "Index");
		zephir_array_update_long(&agvArr, 0, &_12$$6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	_13 = !(zephir_array_isset_long(&agvArr, 1));
	if (!(_13)) {
		ZEPHIR_INIT_VAR(&_14);
		zephir_array_fetch_long(&_15, &agvArr, 1, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 81);
		zephir_fast_trim(&_14, &_15, NULL , ZEPHIR_TRIM_BOTH);
		_13 = ZEPHIR_IS_STRING(&_14, "");
	}
	_16 = _13;
	if (!(_16)) {
		ZEPHIR_INIT_VAR(&_17);
		zephir_array_fetch_long(&_18, &agvArr, 1, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 81);
		zephir_fast_trim(&_17, &_18, NULL , ZEPHIR_TRIM_BOTH);
		_16 = Z_TYPE_P(&_17) == IS_NULL;
	}
	if (_16) {
		ZEPHIR_INIT_VAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "index");
		zephir_array_update_long(&agvArr, 1, &_19$$7, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_INIT_VAR(&_20);
	zephir_array_fetch_long(&_21, &agvArr, 0, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 84);
	zephir_fast_trim(&_20, &_21, NULL , ZEPHIR_TRIM_BOTH);
	zephir_read_property(&_22, this_ptr, SL("actionClassSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_23);
	ZEPHIR_CONCAT_VV(&_23, &_20, &_22);
	zephir_update_property_zval(this_ptr, SL("className"), &_23);
	ZEPHIR_INIT_VAR(&_24);
	zephir_array_fetch_long(&_25, &agvArr, 1, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 85);
	zephir_fast_trim(&_24, &_25, NULL , ZEPHIR_TRIM_BOTH);
	zephir_read_property(&_26, this_ptr, SL("actionFuncSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_CONCAT_VV(&_27, &_24, &_26);
	zephir_update_property_zval(this_ptr, SL("funcName"), &_27);
	i = 2;
	while (1) {
		if (!(ZEPHIR_GT_LONG(&agvArrLength, i))) {
			break;
		}
		_28$$8 = zephir_array_isset_long(&agvArr, i);
		if (_28$$8) {
			_28$$8 = zephir_array_isset_long(&agvArr, (i + 1));
		}
		_29$$8 = _28$$8;
		if (_29$$8) {
			ZEPHIR_INIT_NVAR(&_30$$8);
			zephir_array_fetch_long(&_31$$8, &agvArr, i, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 89);
			ZEPHIR_INIT_NVAR(&_32$$8);
			ZVAL_STRING(&_32$$8, "/(^[a-zA-Z_]$)|(^[a-zA-Z_][a-zA-Z_0-9]+$)/");
			ZEPHIR_INIT_NVAR(&_33$$8);
			ZEPHIR_INIT_NVAR(&_34$$8);
			ZVAL_STRING(&_34$$8, "/(^[a-zA-Z_]$)|(^[a-zA-Z_][a-zA-Z_0-9]+$)/");
			zephir_preg_match(&_33$$8, &_34$$8, &_31$$8, &_30$$8, 0, 0 , 0 );
			_29$$8 = ZEPHIR_IS_LONG(&_33$$8, 1);
		}
		if (_29$$8) {
			zephir_array_fetch_long(&_35$$9, &agvArr, (i + 1), PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 90);
			ZEPHIR_OBS_NVAR(&_36$$9);
			zephir_array_fetch_long(&_36$$9, &agvArr, i, PH_NOISY, "sephp/SeFramework.zep", 90);
			zephir_array_update_zval(&_GET, &_36$$9, &_35$$9, PH_COPY | PH_SEPARATE);
		}
		i = (i + 2);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_SeFramework, argRouter) {

	zend_bool _7$$3, _15$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _GET, _0, _1, _2, _3, _4, _5, agvArr$$3, _6$$3, _8$$3, _16$$3, _9$$4, _10$$4, _11$$4, _12$$5, _13$$5, _14$$5, _17$$6, _18$$6, _19$$6, _20$$7, _21$$7, _22$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&agvArr$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));

	zephir_read_property(&_0, this_ptr, SL("defaultAction"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("actionClassSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("className"), &_2);
	zephir_read_property(&_3, this_ptr, SL("defaultFunc"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("actionFuncSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_3, &_4);
	zephir_update_property_zval(this_ptr, SL("funcName"), &_5);
	if (zephir_array_isset_string(&_GET, SL("r"))) {
		zephir_array_fetch_string(&_6$$3, &_GET, SL("r"), PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 103);
		ZEPHIR_INIT_VAR(&agvArr$$3);
		zephir_fast_explode_str(&agvArr$$3, SL("/"), &_6$$3, LONG_MAX);
		_7$$3 = zephir_array_isset_long(&agvArr$$3, 0);
		if (_7$$3) {
			ZEPHIR_OBS_VAR(&_8$$3);
			zephir_array_fetch_long(&_8$$3, &agvArr$$3, 0, PH_NOISY, "sephp/SeFramework.zep", 104);
			_7$$3 = !(ZEPHIR_IS_EMPTY(&_8$$3));
		}
		if (_7$$3) {
			zephir_array_fetch_long(&_9$$4, &agvArr$$3, 0, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 105);
			zephir_read_property(&_10$$4, this_ptr, SL("actionClassSuffix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_11$$4);
			ZEPHIR_CONCAT_VV(&_11$$4, &_9$$4, &_10$$4);
			zephir_update_property_zval(this_ptr, SL("className"), &_11$$4);
		} else {
			zephir_read_property(&_12$$5, this_ptr, SL("defaultAction"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_13$$5, this_ptr, SL("actionClassSuffix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_14$$5);
			ZEPHIR_CONCAT_VV(&_14$$5, &_12$$5, &_13$$5);
			zephir_update_property_zval(this_ptr, SL("className"), &_14$$5);
		}
		_15$$3 = zephir_array_isset_long(&agvArr$$3, 1);
		if (_15$$3) {
			ZEPHIR_OBS_VAR(&_16$$3);
			zephir_array_fetch_long(&_16$$3, &agvArr$$3, 1, PH_NOISY, "sephp/SeFramework.zep", 109);
			_15$$3 = !(ZEPHIR_IS_EMPTY(&_16$$3));
		}
		if (_15$$3) {
			zephir_array_fetch_long(&_17$$6, &agvArr$$3, 1, PH_NOISY | PH_READONLY, "sephp/SeFramework.zep", 110);
			zephir_read_property(&_18$$6, this_ptr, SL("actionFuncSuffix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_19$$6);
			ZEPHIR_CONCAT_VV(&_19$$6, &_17$$6, &_18$$6);
			zephir_update_property_zval(this_ptr, SL("funcName"), &_19$$6);
		} else {
			zephir_read_property(&_20$$7, this_ptr, SL("defaultFunc"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_21$$7, this_ptr, SL("actionFuncSuffix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_22$$7);
			ZEPHIR_CONCAT_VV(&_22$$7, &_20$$7, &_21$$7);
			zephir_update_property_zval(this_ptr, SL("funcName"), &_22$$7);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_SeFramework, router) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("enablePrettyUrl"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "prettyrouter", NULL, 3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "argrouter", NULL, 4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_SeFramework, run) {

	zend_class_entry *_18;
	zval _0, _1, _2, _3, _4, v, _5, *_6, _7, classSuffix, _14, _15, className, funcName, res, _16, _17, _8$$3, _10$$3, _12$$4, _13$$4, _19$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&classSuffix);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&funcName);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_19$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "router", NULL, 5);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("includePath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("commonPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("actionPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("modelPath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("confPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 6, &_0, &_1, &_2, &_3, &_4);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("includePath"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "sephp/SeFramework.zep", 137);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _6);
			ZEPHIR_CALL_FUNCTION(&_8$$3, "get_include_path", &_9, 7);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$3);
			ZEPHIR_CONCAT_VSV(&_10$$3, &_8$$3, ":", &v);
			ZEPHIR_CALL_FUNCTION(NULL, "set_include_path", &_11, 8, &_10$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&v, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_12$$4, "get_include_path", &_9, 7);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZEPHIR_CONCAT_VSV(&_13$$4, &_12$$4, ":", &v);
				ZEPHIR_CALL_FUNCTION(NULL, "set_include_path", &_11, 8, &_13$$4);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	zephir_read_property(&_14, this_ptr, SL("classSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&classSuffix, &_14);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_INIT_NVAR(&_15);
	zephir_create_closure_ex(&_15, NULL, sephp_0__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(sephp_0__closure_ce, ZEND_STRL("classSuffix"), &classSuffix);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 9, &_15);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&className, &_14);
	zephir_read_property(&_14, this_ptr, SL("funcName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&funcName, &_14);
	ZEPHIR_INIT_VAR(&_16);
	zephir_fetch_safe_class(&_17, &className);
	_18 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_17), Z_STRLEN_P(&_17), ZEND_FETCH_CLASS_AUTO);
	if(!_18) {
		RETURN_MM_NULL();
	}
	object_init_ex(&_16, _18);
	if (zephir_has_constructor(&_16)) {
		ZEPHIR_CALL_METHOD(NULL, &_16, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_ZVAL(&res, &_16, &funcName, NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&res) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_19$$5);
		zephir_json_encode(&_19$$5, &res, 0 );
		zend_print_zval(&_19$$5, 0);
	} else {
		zend_print_zval(&res, 0);
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_SePHP_SeFramework(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("includePath"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("includePath"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

