
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(SePHP_Common_Utils) {

	ZEPHIR_REGISTER_CLASS(SePHP\\Common, Utils, sephp, common_utils, sephp_common_utils_method_entry, 0);

	zend_declare_property_string(sephp_common_utils_ce, SL("aesKey"), "TME_CRYPT_KEY", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	zend_declare_property_string(sephp_common_utils_ce, SL("aesIv"), "1234567890123456", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(SePHP_Common_Utils, payEncrypt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *input, input_sub, aesKey, _0, _1, aesIv, _4, _6, _7, _3$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&aesKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&aesIv);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZEPHIR_INIT_VAR(&aesKey);
	ZVAL_STRING(&aesKey, "");
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "TME_CRYPT_KEY");
	ZEPHIR_CALL_FUNCTION(&_1, "defined", &_2, 1, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_NVAR(&aesKey);
		ZEPHIR_GET_CONSTANT(&aesKey, "TME_CRYPT_KEY");
	} else {
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_read_static_property_ce(&_3$$4, sephp_common_utils_ce, SL("aesKey"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&aesKey, &_3$$4);
	}
	ZEPHIR_INIT_VAR(&aesIv);
	ZVAL_STRING(&aesIv, "");
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "TME_CRYPT_IV");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", &_2, 1, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_NVAR(&aesIv);
		ZEPHIR_GET_CONSTANT(&aesIv, "TME_CRYPT_IV");
	} else {
		ZEPHIR_OBS_VAR(&_5$$6);
		zephir_read_static_property_ce(&_5$$6, sephp_common_utils_ce, SL("aesIv"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&aesIv, &_5$$6);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "AES-128-CBC");
	ZVAL_LONG(&_6, 1);
	ZEPHIR_CALL_FUNCTION(&_7, "openssl_encrypt", NULL, 26, input, &_0, &aesKey, &_6, &aesIv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 24, &_7);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Utils, payDecrypt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *input, input_sub, aesKey, _0, _1, aesIv, _4, _6, _7, _3$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&aesKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&aesIv);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZEPHIR_INIT_VAR(&aesKey);
	ZVAL_STRING(&aesKey, "");
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "TME_CRYPT_KEY");
	ZEPHIR_CALL_FUNCTION(&_1, "defined", &_2, 1, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_NVAR(&aesKey);
		ZEPHIR_GET_CONSTANT(&aesKey, "TME_CRYPT_KEY");
	} else {
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_read_static_property_ce(&_3$$4, sephp_common_utils_ce, SL("aesKey"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&aesKey, &_3$$4);
	}
	ZEPHIR_INIT_VAR(&aesIv);
	ZVAL_STRING(&aesIv, "");
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "TME_CRYPT_IV");
	ZEPHIR_CALL_FUNCTION(&_4, "defined", &_2, 1, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_NVAR(&aesIv);
		ZEPHIR_GET_CONSTANT(&aesIv, "TME_CRYPT_IV");
	} else {
		ZEPHIR_OBS_VAR(&_5$$6);
		zephir_read_static_property_ce(&_5$$6, sephp_common_utils_ce, SL("aesIv"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(&aesIv, &_5$$6);
	}
	ZEPHIR_CALL_FUNCTION(&_6, "base64_decode", NULL, 25, input);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "AES-128-CBC");
	ZVAL_LONG(&_7, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_decrypt", NULL, 27, &_6, &_0, &aesKey, &_7, &aesIv);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Utils, randomCode) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number;
	zval *length = NULL, length_sub, *typeStr = NULL, typeStr_sub, codeArr, randomStr, codeType, chars, _8, _9, _key$$3, cType$$3, *_0$$3, _1$$3, _4$$5, _5$$5, _6$$7, _7$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&typeStr_sub);
	ZVAL_UNDEF(&codeArr);
	ZVAL_UNDEF(&randomStr);
	ZVAL_UNDEF(&codeType);
	ZVAL_UNDEF(&chars);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_key$$3);
	ZVAL_UNDEF(&cType$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &length, &typeStr);

	if (!length) {
		length = &length_sub;
		ZEPHIR_INIT_VAR(length);
		ZVAL_LONG(length, 8);
	}
	if (!typeStr) {
		typeStr = &typeStr_sub;
		ZEPHIR_INIT_VAR(typeStr);
		ZVAL_STRING(typeStr, "an");
	}


	ZEPHIR_INIT_VAR(&codeArr);
	zephir_create_array(&codeArr, 3, 0);
	add_assoc_stringl_ex(&codeArr, SL("a"), SL("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	add_assoc_stringl_ex(&codeArr, SL("n"), SL("0123456789"));
	add_assoc_stringl_ex(&codeArr, SL("s"), SL("#$%@*-_"));
	ZEPHIR_INIT_VAR(&randomStr);
	ZVAL_STRING(&randomStr, "");
	ZEPHIR_CALL_FUNCTION(&codeType, "str_split", NULL, 17, typeStr);
	zephir_check_call_status();
	if (Z_TYPE_P(&codeType) == IS_ARRAY) {
		zephir_is_iterable(&codeType, 0, "sephp/common/Utils.zep", 62);
		if (Z_TYPE_P(&codeType) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&codeType), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&_key$$3);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&_key$$3, _3$$3);
				} else {
					ZVAL_LONG(&_key$$3, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&cType$$3);
				ZVAL_COPY(&cType$$3, _0$$3);
				if (zephir_array_isset(&codeArr, &cType$$3)) {
					zephir_array_fetch(&_4$$5, &codeArr, &cType$$3, PH_NOISY | PH_READONLY, "sephp/common/Utils.zep", 59);
					ZEPHIR_INIT_NVAR(&_5$$5);
					ZEPHIR_CONCAT_VV(&_5$$5, &randomStr, &_4$$5);
					ZEPHIR_CPY_WRT(&randomStr, &_5$$5);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &codeType, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &codeType, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&_key$$3, &codeType, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&cType$$3, &codeType, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_array_isset(&codeArr, &cType$$3)) {
						zephir_array_fetch(&_6$$7, &codeArr, &cType$$3, PH_NOISY | PH_READONLY, "sephp/common/Utils.zep", 59);
						ZEPHIR_INIT_NVAR(&_7$$7);
						ZEPHIR_CONCAT_VV(&_7$$7, &randomStr, &_6$$7);
						ZEPHIR_CPY_WRT(&randomStr, &_7$$7);
					}
				ZEPHIR_CALL_METHOD(NULL, &codeType, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&cType$$3);
		ZEPHIR_INIT_NVAR(&_key$$3);
	}
	ZEPHIR_CALL_FUNCTION(&chars, "str_shuffle", NULL, 28, &randomStr);
	zephir_check_call_status();
	number = 0;
	if (ZEPHIR_GT_LONG(length, (zephir_fast_strlen_ev(&chars) - 1))) {
		number = (zephir_fast_strlen_ev(&chars) - 1);
	} else {
		number = zephir_get_numberval(length);
	}
	ZVAL_LONG(&_8, 0);
	ZVAL_LONG(&_9, number);
	zephir_substr(return_value, &chars, 0 , zephir_get_intval(&_9), 0);
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Utils, returnArray) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *code, code_sub, *message = NULL, message_sub, *data = NULL, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &code, &message, &data);

	if (!message) {
		message = &message_sub;
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "");
	}
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}


	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("code"), code, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("message"), message, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("data"), data, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Utils, returnJson) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, *message = NULL, message_sub, *data = NULL, data_sub, res, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &code, &message, &data);

	if (!message) {
		message = &message_sub;
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "");
	}
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}


	ZEPHIR_CALL_SELF(&res, "returnarray", NULL, 0, code, message, data);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 256);
	zephir_json_encode(return_value, &res, zephir_get_intval(&_0) );
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Utils, outputJson) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, *message = NULL, message_sub, *data = NULL, data_sub, *doDie = NULL, doDie_sub, __$true, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&doDie_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &code, &message, &data, &doDie);

	if (!message) {
		message = &message_sub;
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "");
	}
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}
	if (!doDie) {
		doDie = &doDie_sub;
		doDie = &__$true;
	}


	ZEPHIR_CALL_SELF(&_0, "returnjson", NULL, 0, code, message, data);
	zephir_check_call_status();
	zend_print_zval(&_0, 0);
	if (ZEPHIR_IS_TRUE(doDie)) {
		ZVAL_LONG(&_1$$3, 0);
		ZEPHIR_MM_RESTORE();
		zephir_exit(&_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

