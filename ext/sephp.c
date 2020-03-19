
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "sephp.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *sephp_0__closure_ce;
zend_class_entry *sephp_common_rsa_ce;
zend_class_entry *sephp_common_utils_ce;
zend_class_entry *sephp_seframework_ce;
zend_class_entry *sephp_view_ce;

ZEND_DECLARE_MODULE_GLOBALS(sephp)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(sephp)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(SePHP_Common_Rsa);
	ZEPHIR_INIT(SePHP_Common_Utils);
	ZEPHIR_INIT(SePHP_SeFramework);
	ZEPHIR_INIT(SePHP_View);
	ZEPHIR_INIT(sephp_0__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(sephp)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_sephp_globals *sephp_globals TSRMLS_DC)
{
	sephp_globals->initialized = 0;

	/* Cache Enabled */
	sephp_globals->cache_enabled = 1;

	/* Recursive Lock */
	sephp_globals->recursive_lock = 0;

	/* Static cache */
	memset(sephp_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_sephp_globals *sephp_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(sephp)
{
	zend_sephp_globals *sephp_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	sephp_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(sephp_globals_ptr);
	zephir_initialize_memory(sephp_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(sephp)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(sephp)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SEPHP_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SEPHP_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SEPHP_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SEPHP_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SEPHP_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(sephp)
{
	php_zephir_init_globals(sephp_globals);
	php_zephir_init_module_globals(sephp_globals);
}

static PHP_GSHUTDOWN_FUNCTION(sephp)
{
	
}


zend_function_entry php_sephp_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_sephp_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry sephp_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_sephp_deps,
	PHP_SEPHP_EXTNAME,
	php_sephp_functions,
	PHP_MINIT(sephp),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(sephp),
#else
	NULL,
#endif
	PHP_RINIT(sephp),
	PHP_RSHUTDOWN(sephp),
	PHP_MINFO(sephp),
	PHP_SEPHP_VERSION,
	ZEND_MODULE_GLOBALS(sephp),
	PHP_GINIT(sephp),
	PHP_GSHUTDOWN(sephp),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(sephp),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SEPHP
ZEND_GET_MODULE(sephp)
#endif
