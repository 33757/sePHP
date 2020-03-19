
extern zend_class_entry *sephp_0__closure_ce;

ZEPHIR_INIT_CLASS(sephp_0__closure);

PHP_METHOD(sephp_0__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_0__closure___invoke, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cName)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sephp_0__closure_method_entry) {
	PHP_ME(sephp_0__closure, __invoke, arginfo_sephp_0__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
