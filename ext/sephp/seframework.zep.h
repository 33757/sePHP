
extern zend_class_entry *sephp_seframework_ce;

ZEPHIR_INIT_CLASS(SePHP_SeFramework);

PHP_METHOD(SePHP_SeFramework, __construct);
PHP_METHOD(SePHP_SeFramework, _setPath);
PHP_METHOD(SePHP_SeFramework, _setDefaultRouter);
PHP_METHOD(SePHP_SeFramework, prettyRouter);
PHP_METHOD(SePHP_SeFramework, argRouter);
PHP_METHOD(SePHP_SeFramework, router);
PHP_METHOD(SePHP_SeFramework, run);
zend_object *zephir_init_properties_SePHP_SeFramework(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_seframework___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rootPath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, rootPath)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_seframework__setdefaultrouter, 0, 0, 0)
	ZEND_ARG_INFO(0, action)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sephp_seframework_method_entry) {
	PHP_ME(SePHP_SeFramework, __construct, arginfo_sephp_seframework___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SePHP_SeFramework, _setPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_SeFramework, _setDefaultRouter, arginfo_sephp_seframework__setdefaultrouter, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_SeFramework, prettyRouter, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(SePHP_SeFramework, argRouter, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(SePHP_SeFramework, router, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(SePHP_SeFramework, run, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
