
extern zend_class_entry *sephp_common_rsa_ce;

ZEPHIR_INIT_CLASS(SePHP_Common_Rsa);

PHP_METHOD(SePHP_Common_Rsa, __construct);
PHP_METHOD(SePHP_Common_Rsa, createKeys);
PHP_METHOD(SePHP_Common_Rsa, publicEncrypt);
PHP_METHOD(SePHP_Common_Rsa, privateDecrypt);
PHP_METHOD(SePHP_Common_Rsa, privateEncrypt);
PHP_METHOD(SePHP_Common_Rsa, publicDecrypt);
PHP_METHOD(SePHP_Common_Rsa, sign);
PHP_METHOD(SePHP_Common_Rsa, verify);
PHP_METHOD(SePHP_Common_Rsa, url_safe_base64_encode);
PHP_METHOD(SePHP_Common_Rsa, url_safe_base64_decode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_rsa___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, keyArr)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_createkeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_createkeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keySize, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, keySize)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_publicencrypt, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_publicencrypt, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_privatedecrypt, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_privatedecrypt, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encrypted, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, encrypted)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_privateencrypt, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_privateencrypt, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_publicdecrypt, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_publicdecrypt, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encrypted, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, encrypted)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_sign, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_sign, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_common_rsa_verify, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, signStr)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_url_safe_base64_encode, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_url_safe_base64_encode, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_url_safe_base64_decode, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sephp_common_rsa_url_safe_base64_decode, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sephp_common_rsa_method_entry) {
	PHP_ME(SePHP_Common_Rsa, __construct, arginfo_sephp_common_rsa___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SePHP_Common_Rsa, createKeys, arginfo_sephp_common_rsa_createkeys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(SePHP_Common_Rsa, publicEncrypt, arginfo_sephp_common_rsa_publicencrypt, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_Common_Rsa, privateDecrypt, arginfo_sephp_common_rsa_privatedecrypt, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_Common_Rsa, privateEncrypt, arginfo_sephp_common_rsa_privateencrypt, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_Common_Rsa, publicDecrypt, arginfo_sephp_common_rsa_publicdecrypt, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_Common_Rsa, sign, arginfo_sephp_common_rsa_sign, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_Common_Rsa, verify, arginfo_sephp_common_rsa_verify, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_Common_Rsa, url_safe_base64_encode, arginfo_sephp_common_rsa_url_safe_base64_encode, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_Common_Rsa, url_safe_base64_decode, arginfo_sephp_common_rsa_url_safe_base64_decode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
