
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_SEPHP_H
#define PHP_SEPHP_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_SEPHP_NAME        "sephp"
#define PHP_SEPHP_VERSION     "0.0.1"
#define PHP_SEPHP_EXTNAME     "sephp"
#define PHP_SEPHP_AUTHOR      "Phalcon Team"
#define PHP_SEPHP_ZEPVERSION  "0.12.17-$Id$"
#define PHP_SEPHP_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(sephp)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(sephp)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(sephp)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(sephp, v)
#else
	#define ZEPHIR_GLOBAL(v) (sephp_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_sephp_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(sephp_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(sephp_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def sephp_globals
#define zend_zephir_globals_def zend_sephp_globals

extern zend_module_entry sephp_module_entry;
#define phpext_sephp_ptr &sephp_module_entry

#endif
