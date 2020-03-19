
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(SePHP_Common_Rsa) {

	ZEPHIR_REGISTER_CLASS(SePHP\\Common, Rsa, sephp, common_rsa, sephp_common_rsa_method_entry, 0);

	zend_declare_property_null(sephp_common_rsa_ce, SL("publicKey"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(sephp_common_rsa_ce, SL("privateKey"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(sephp_common_rsa_ce, SL("keyLen"), ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_string(sephp_common_rsa_ce, SL("CHAR_SET"), "UTF-8");

	zephir_declare_class_constant_string(sephp_common_rsa_ce, SL("BASE_64_FORMAT"), "UrlSafeNoPadding");

	zephir_declare_class_constant_long(sephp_common_rsa_ce, SL("RSA_ALGORITHM_KEY_TYPE"), 0);

	zephir_declare_class_constant_long(sephp_common_rsa_ce, SL("RSA_ALGORITHM_SIGN"), 7);

	return SUCCESS;

}

PHP_METHOD(SePHP_Common_Rsa, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pubKey, pubKey_sub, *priKey = NULL, priKey_sub, __$null, pubId, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pubKey_sub);
	ZVAL_UNDEF(&priKey_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&pubId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pubKey, &priKey);

	if (!priKey) {
		priKey = &priKey_sub;
		priKey = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("publicKey"), pubKey);
	zephir_update_property_zval(this_ptr, SL("privateKey"), priKey);
	zephir_read_property(&_0, this_ptr, SL("publicKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&pubId, "openssl_get_publickey", NULL, 13, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "openssl_pkey_get_details", NULL, 14, &pubId);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &_1, SL("bits"), PH_NOISY | PH_READONLY, "sephp/common/Rsa.zep", 20);
	zephir_update_property_zval(this_ptr, SL("keyLen"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(SePHP_Common_Rsa, createKeys) {

	zval config;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *keySize_param = NULL, _0, res, privateKey, publicKeyDetail, publicKey;
	zend_long keySize, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&privateKey);
	ZVAL_UNDEF(&publicKeyDetail);
	ZVAL_UNDEF(&publicKey);
	ZVAL_UNDEF(&config);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &keySize_param);

	if (!keySize_param) {
		keySize = 2048;
	} else {
		keySize = zephir_get_intval(keySize_param);
	}


	ZEPHIR_INIT_VAR(&config);
	zephir_create_array(&config, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, keySize);
	zephir_array_update_string(&config, SL("private_key_bits"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&config, SL("private_key_type"), 0);
	ZEPHIR_CALL_FUNCTION(&res, "openssl_pkey_new", NULL, 15, &config);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&privateKey);
	ZVAL_STRING(&privateKey, "");
	ZEPHIR_MAKE_REF(&privateKey);
	ZEPHIR_CALL_FUNCTION(NULL, "openssl_pkey_export", NULL, 16, &res, &privateKey);
	ZEPHIR_UNREF(&privateKey);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&publicKeyDetail, "openssl_pkey_get_details", NULL, 14, &res);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&publicKey);
	zephir_array_fetch_string(&publicKey, &publicKeyDetail, SL("key"), PH_NOISY, "sephp/common/Rsa.zep", 33);
	zephir_create_array(return_value, 2, 0);
	zephir_array_update_string(return_value, SL("public_key"), &publicKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("private_key"), &privateKey, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Rsa, publicEncrypt) {

	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, partLen;
	zval *data, data_sub, encrypted, _0, parts, _1, encryptedTemp, part, _key, *_2, _3, _6$$3, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&encryptedTemp);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_key);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&encrypted);
	ZVAL_STRING(&encrypted, "");
	zephir_read_property(&_0, this_ptr, SL("keyLen"), PH_NOISY_CC | PH_READONLY);
	partLen = (long) ((zephir_safe_div_zval_long(&_0, 8) - (double) (11)));
	ZVAL_LONG(&_1, partLen);
	ZEPHIR_CALL_FUNCTION(&parts, "str_split", NULL, 17, data, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&encryptedTemp);
	ZVAL_STRING(&encryptedTemp, "");
	ZEPHIR_INIT_VAR(&part);
	ZVAL_STRING(&part, "");
	ZEPHIR_INIT_VAR(&_key);
	ZVAL_STRING(&_key, "");
	zephir_is_iterable(&parts, 0, "sephp/common/Rsa.zep", 55);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&_key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&_key, _5);
			} else {
				ZVAL_LONG(&_key, _4);
			}
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _2);
			ZEPHIR_INIT_NVAR(&encryptedTemp);
			ZVAL_STRING(&encryptedTemp, "");
			zephir_read_property(&_6$$3, this_ptr, SL("publicKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_MAKE_REF(&encryptedTemp);
			ZEPHIR_CALL_FUNCTION(NULL, "openssl_public_encrypt", &_7, 18, &part, &encryptedTemp, &_6$$3);
			ZEPHIR_UNREF(&encryptedTemp);
			zephir_check_call_status();
			zephir_concat_self(&encrypted, &encryptedTemp);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_key, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&encryptedTemp);
				ZVAL_STRING(&encryptedTemp, "");
				zephir_read_property(&_8$$4, this_ptr, SL("publicKey"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&encryptedTemp);
				ZEPHIR_CALL_FUNCTION(NULL, "openssl_public_encrypt", &_7, 18, &part, &encryptedTemp, &_8$$4);
				ZEPHIR_UNREF(&encryptedTemp);
				zephir_check_call_status();
				zephir_concat_self(&encrypted, &encryptedTemp);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&_key);
	ZEPHIR_RETURN_CALL_SELF("url_safe_base64_encode", NULL, 0, &encrypted);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Rsa, privateDecrypt) {

	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, partLen;
	zval *encrypted_param = NULL, decrypted, _0, base64Decoded, parts, _1, _key, part, decryptedTemp, *_2, _3, _6$$3, _8$$4;
	zval encrypted;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&decrypted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&base64Decoded);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_key);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&decryptedTemp);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encrypted_param);

	zephir_get_strval(&encrypted, encrypted_param);


	ZEPHIR_INIT_VAR(&decrypted);
	ZVAL_STRING(&decrypted, "");
	zephir_read_property(&_0, this_ptr, SL("keyLen"), PH_NOISY_CC | PH_READONLY);
	partLen = (long) (zephir_safe_div_zval_long(&_0, 8));
	ZEPHIR_CALL_SELF(&base64Decoded, "url_safe_base64_decode", NULL, 0, &encrypted);
	zephir_check_call_status();
	ZVAL_LONG(&_1, partLen);
	ZEPHIR_CALL_FUNCTION(&parts, "str_split", NULL, 17, &base64Decoded, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&parts, 0, "sephp/common/Rsa.zep", 74);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&_key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&_key, _5);
			} else {
				ZVAL_LONG(&_key, _4);
			}
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _2);
			ZEPHIR_INIT_NVAR(&decryptedTemp);
			ZVAL_STRING(&decryptedTemp, "");
			zephir_read_property(&_6$$3, this_ptr, SL("privateKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_MAKE_REF(&decryptedTemp);
			ZEPHIR_CALL_FUNCTION(NULL, "openssl_private_decrypt", &_7, 19, &part, &decryptedTemp, &_6$$3);
			ZEPHIR_UNREF(&decryptedTemp);
			zephir_check_call_status();
			zephir_concat_self(&decrypted, &decryptedTemp);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_key, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&decryptedTemp);
				ZVAL_STRING(&decryptedTemp, "");
				zephir_read_property(&_8$$4, this_ptr, SL("privateKey"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&decryptedTemp);
				ZEPHIR_CALL_FUNCTION(NULL, "openssl_private_decrypt", &_7, 19, &part, &decryptedTemp, &_8$$4);
				ZEPHIR_UNREF(&decryptedTemp);
				zephir_check_call_status();
				zephir_concat_self(&decrypted, &decryptedTemp);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&_key);
	RETURN_CCTOR(&decrypted);

}

PHP_METHOD(SePHP_Common_Rsa, privateEncrypt) {

	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, partLen;
	zval *data, data_sub, encrypted, _0, parts, _1, _key, part, encryptedTemp, *_2, _3, _6$$3, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_key);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&encryptedTemp);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&encrypted);
	ZVAL_STRING(&encrypted, "");
	zephir_read_property(&_0, this_ptr, SL("keyLen"), PH_NOISY_CC | PH_READONLY);
	partLen = (long) ((zephir_safe_div_zval_long(&_0, 8) - (double) (11)));
	ZVAL_LONG(&_1, partLen);
	ZEPHIR_CALL_FUNCTION(&parts, "str_split", NULL, 17, data, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&parts, 0, "sephp/common/Rsa.zep", 93);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&_key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&_key, _5);
			} else {
				ZVAL_LONG(&_key, _4);
			}
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _2);
			ZEPHIR_INIT_NVAR(&encryptedTemp);
			ZVAL_STRING(&encryptedTemp, "");
			zephir_read_property(&_6$$3, this_ptr, SL("privateKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_MAKE_REF(&encryptedTemp);
			ZEPHIR_CALL_FUNCTION(NULL, "openssl_private_encrypt", &_7, 20, &part, &encryptedTemp, &_6$$3);
			ZEPHIR_UNREF(&encryptedTemp);
			zephir_check_call_status();
			zephir_concat_self(&encrypted, &encryptedTemp);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_key, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&encryptedTemp);
				ZVAL_STRING(&encryptedTemp, "");
				zephir_read_property(&_8$$4, this_ptr, SL("privateKey"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&encryptedTemp);
				ZEPHIR_CALL_FUNCTION(NULL, "openssl_private_encrypt", &_7, 20, &part, &encryptedTemp, &_8$$4);
				ZEPHIR_UNREF(&encryptedTemp);
				zephir_check_call_status();
				zephir_concat_self(&encrypted, &encryptedTemp);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&_key);
	ZEPHIR_RETURN_CALL_SELF("url_safe_base64_encode", NULL, 0, &encrypted);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Rsa, publicDecrypt) {

	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, partLen;
	zval *encrypted_param = NULL, decrypted, _0, base64Decoded, parts, _1, _key, part, decryptedTemp, *_2, _3, _6$$3, _8$$4;
	zval encrypted;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&decrypted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&base64Decoded);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_key);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&decryptedTemp);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encrypted_param);

	zephir_get_strval(&encrypted, encrypted_param);


	ZEPHIR_INIT_VAR(&decrypted);
	ZVAL_STRING(&decrypted, "");
	zephir_read_property(&_0, this_ptr, SL("keyLen"), PH_NOISY_CC | PH_READONLY);
	partLen = (long) (zephir_safe_div_zval_long(&_0, 8));
	ZEPHIR_CALL_SELF(&base64Decoded, "url_safe_base64_decode", NULL, 0, &encrypted);
	zephir_check_call_status();
	ZVAL_LONG(&_1, partLen);
	ZEPHIR_CALL_FUNCTION(&parts, "str_split", NULL, 17, &base64Decoded, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&parts, 0, "sephp/common/Rsa.zep", 112);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parts), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&_key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&_key, _5);
			} else {
				ZVAL_LONG(&_key, _4);
			}
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _2);
			ZEPHIR_INIT_NVAR(&decryptedTemp);
			ZVAL_STRING(&decryptedTemp, "");
			zephir_read_property(&_6$$3, this_ptr, SL("publicKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_MAKE_REF(&decryptedTemp);
			ZEPHIR_CALL_FUNCTION(NULL, "openssl_public_decrypt", &_7, 21, &part, &decryptedTemp, &_6$$3);
			ZEPHIR_UNREF(&decryptedTemp);
			zephir_check_call_status();
			zephir_concat_self(&decrypted, &decryptedTemp);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_key, &parts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&decryptedTemp);
				ZVAL_STRING(&decryptedTemp, "");
				zephir_read_property(&_8$$4, this_ptr, SL("publicKey"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_MAKE_REF(&decryptedTemp);
				ZEPHIR_CALL_FUNCTION(NULL, "openssl_public_decrypt", &_7, 21, &part, &decryptedTemp, &_8$$4);
				ZEPHIR_UNREF(&decryptedTemp);
				zephir_check_call_status();
				zephir_concat_self(&decrypted, &decryptedTemp);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	ZEPHIR_INIT_NVAR(&_key);
	RETURN_CCTOR(&decrypted);

}

PHP_METHOD(SePHP_Common_Rsa, sign) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, signStr, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&signStr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&signStr);
	ZVAL_STRING(&signStr, "");
	zephir_read_property(&_0, this_ptr, SL("privateKey"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 7);
	ZEPHIR_MAKE_REF(&signStr);
	ZEPHIR_CALL_FUNCTION(NULL, "openssl_sign", NULL, 22, data, &signStr, &_0, &_1);
	ZEPHIR_UNREF(&signStr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("url_safe_base64_encode", NULL, 0, &signStr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(SePHP_Common_Rsa, verify) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *signStr, signStr_sub, pubId, _0, res, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&signStr_sub);
	ZVAL_UNDEF(&pubId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data, &signStr);



	zephir_read_property(&_0, this_ptr, SL("publicKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&pubId, "openssl_get_publickey", NULL, 13, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_1, "url_safe_base64_decode", NULL, 0, signStr);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 7);
	ZEPHIR_CALL_FUNCTION(&res, "openssl_verify", NULL, 23, data, &_1, &pubId, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&res);

}

PHP_METHOD(SePHP_Common_Rsa, url_safe_base64_encode) {

	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "+");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "=");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "-");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(&_3, "base64_encode", NULL, 24, data);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_str_replace(&_1, &_0, &_2, &_3);
	RETURN_CCTOR(&_1);

}

PHP_METHOD(SePHP_Common_Rsa, url_safe_base64_decode) {

	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, base64, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&base64);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "+");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_VAR(&base64);
	zephir_fast_str_replace(&base64, &_0, &_2, data);
	ZEPHIR_RETURN_CALL_FUNCTION("base64_decode", NULL, 25, &base64);
	zephir_check_call_status();
	RETURN_MM();

}

