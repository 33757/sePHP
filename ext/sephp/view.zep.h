
extern zend_class_entry *sephp_view_ce;

ZEPHIR_INIT_CLASS(SePHP_View);

PHP_METHOD(SePHP_View, __construct);
PHP_METHOD(SePHP_View, assign);
PHP_METHOD(SePHP_View, _fetch);
PHP_METHOD(SePHP_View, display);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_view___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tpl, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tpl)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_view_assign, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_view__fetch, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, template)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sephp_view_display, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, template)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sephp_view_method_entry) {
	PHP_ME(SePHP_View, __construct, arginfo_sephp_view___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SePHP_View, assign, arginfo_sephp_view_assign, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_View, _fetch, arginfo_sephp_view__fetch, ZEND_ACC_PUBLIC)
	PHP_ME(SePHP_View, display, arginfo_sephp_view_display, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
