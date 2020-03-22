
extern zend_class_entry *sephp_common_utils_ce;

ZEPHIR_INIT_CLASS(SePHP_Common_Utils);

PHP_METHOD(SePHP_Common_Utils, payEncrypt);
PHP_METHOD(SePHP_Common_Utils, payDecrypt);
PHP_METHOD(SePHP_Common_Utils, privateKeyEncryption);
PHP_METHOD(SePHP_Common_Utils, privateKeyDecryption);
PHP_METHOD(SePHP_Common_Utils, publicKeyEncryption);
PHP_METHOD(SePHP_Common_Utils, publicKeyDecryption);
PHP_METHOD(SePHP_Common_Utils, mPrivateKeyEncryption);
PHP_METHOD(SePHP_Common_Utils, mPublicKeyDecryption);
PHP_METHOD(SePHP_Common_Utils, randomCode);
PHP_METHOD(SePHP_Common_Utils, returnArray);
PHP_METHOD(SePHP_Common_Utils, returnJson);
PHP_METHOD(SePHP_Common_Utils, outputJson);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_payencrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_paydecrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_privatekeyencryption, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, keyArray)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_privatekeydecryption, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, keyArray)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_publickeyencryption, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, keyArray)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_publickeydecryption, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, keyArray)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_mprivatekeyencryption, 0, 0, 3)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_INFO(0, map)
	ZEND_ARG_INFO(0, keyArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_mpublickeydecryption, 0, 0, 3)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_INFO(0, map)
	ZEND_ARG_INFO(0, keyArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_randomcode, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, typeStr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_returnarray, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_returnjson, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_utils_outputjson, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, doDie)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sephp_common_utils_method_entry) {
	PHP_ME(SePHP_Common_Utils, payEncrypt, arginfo_sephp_common_utils_payencrypt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, payDecrypt, arginfo_sephp_common_utils_paydecrypt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, privateKeyEncryption, arginfo_sephp_common_utils_privatekeyencryption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, privateKeyDecryption, arginfo_sephp_common_utils_privatekeydecryption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, publicKeyEncryption, arginfo_sephp_common_utils_publickeyencryption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, publicKeyDecryption, arginfo_sephp_common_utils_publickeydecryption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, mPrivateKeyEncryption, arginfo_sephp_common_utils_mprivatekeyencryption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, mPublicKeyDecryption, arginfo_sephp_common_utils_mpublickeydecryption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, randomCode, arginfo_sephp_common_utils_randomcode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, returnArray, arginfo_sephp_common_utils_returnarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, returnJson, arginfo_sephp_common_utils_returnjson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Utils, outputJson, arginfo_sephp_common_utils_outputjson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
