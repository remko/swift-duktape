#include "include/CDuktape.h"

#ifndef DUKTAPE_H_INCLUDED__
#define DUKTAPE_H_INCLUDED__
#define DUK_SINGLE_FILE
#ifndef DUK_API_PUBLIC_H_INCLUDED__
#define DUK_API_PUBLIC_H_INCLUDED__
#ifdef __cplusplus
#endif
#undef DUK_API_VARIADIC_MACROS
#ifdef DUK_USE_VARIADIC_MACROS
#define DUK_API_VARIADIC_MACROS
#endif
const int DUK_VERSION = 10501L;

const char* DUK_GIT_COMMIT = "2cc76e9ff1f64869e1146ad7317d8cbe33bbd27e";

const char* DUK_GIT_DESCRIBE = "v1.5.1";

const char* DUK_GIT_BRANCH = "HEAD";

const int DUK_DEBUG_PROTOCOL_VERSION = 1;

const int DUK_INVALID_INDEX = DUK_IDX_MIN;

const int DUK_VARARGS = ((duk_int_t) (-1));

const int DUK_API_ENTRY_STACK = 64;

const int DUK_TYPE_MIN = 0;

const int DUK_TYPE_NONE = 0    /* no value, e.g. invalid index */;

const int DUK_TYPE_UNDEFINED = 1    /* Ecmascript undefined */;

const int DUK_TYPE_NULL = 2    /* Ecmascript null */;

const int DUK_TYPE_BOOLEAN = 3    /* Ecmascript boolean: 0 or 1 */;

const int DUK_TYPE_NUMBER = 4    /* Ecmascript number: double */;

const int DUK_TYPE_STRING = 5    /* Ecmascript string: CESU-8 / extended UTF-8 encoded */;

const int DUK_TYPE_OBJECT = 6    /* Ecmascript object: includes objects, arrays, functions, threads */;

const int DUK_TYPE_BUFFER = 7    /* fixed or dynamic, garbage collected byte buffer */;

const int DUK_TYPE_POINTER = 8    /* raw void pointer */;

const int DUK_TYPE_LIGHTFUNC = 9    /* lightweight function pointer */;

const int DUK_TYPE_MAX = 9;

const int DUK_TYPE_MASK_NONE = (1 << DUK_TYPE_NONE);

const int DUK_TYPE_MASK_UNDEFINED = (1 << DUK_TYPE_UNDEFINED);

const int DUK_TYPE_MASK_NULL = (1 << DUK_TYPE_NULL);

const int DUK_TYPE_MASK_BOOLEAN = (1 << DUK_TYPE_BOOLEAN);

const int DUK_TYPE_MASK_NUMBER = (1 << DUK_TYPE_NUMBER);

const int DUK_TYPE_MASK_STRING = (1 << DUK_TYPE_STRING);

const int DUK_TYPE_MASK_OBJECT = (1 << DUK_TYPE_OBJECT);

const int DUK_TYPE_MASK_BUFFER = (1 << DUK_TYPE_BUFFER);

const int DUK_TYPE_MASK_POINTER = (1 << DUK_TYPE_POINTER);

const int DUK_TYPE_MASK_LIGHTFUNC = (1 << DUK_TYPE_LIGHTFUNC);

const int DUK_TYPE_MASK_THROW = (1 << 10)  /* internal flag value: throw if mask doesn't match */;

const int DUK_HINT_NONE = 0    ;

const int DUK_HINT_STRING = 1    /* prefer string */;

const int DUK_HINT_NUMBER = 2    /* prefer number */;

const int DUK_ENUM_INCLUDE_NONENUMERABLE = (1 << 0)    /* enumerate non-numerable properties in addition to enumerable */;

const int DUK_ENUM_INCLUDE_INTERNAL = (1 << 1)    /* enumerate internal properties (regardless of enumerability) */;

const int DUK_ENUM_OWN_PROPERTIES_ONLY = (1 << 2)    /* don't walk prototype chain, only check own properties */;

const int DUK_ENUM_ARRAY_INDICES_ONLY = (1 << 3)    /* only enumerate array indices */;

const int DUK_ENUM_SORT_ARRAY_INDICES = (1 << 4)    /* sort array indices, use with DUK_ENUM_ARRAY_INDICES_ONLY */;

const int DUK_ENUM_NO_PROXY_BEHAVIOR = (1 << 5)    /* enumerate a proxy object itself without invoking proxy behavior */;

const int DUK_COMPILE_EVAL = (1 << 3)    /* compile eval code (instead of global code) */;

const int DUK_COMPILE_FUNCTION = (1 << 4)    /* compile function code (instead of global code) */;

const int DUK_COMPILE_STRICT = (1 << 5)    /* use strict (outer) context for global, eval, or function code */;

const int DUK_COMPILE_SAFE = (1 << 6)    /* (internal) catch compilation errors */;

const int DUK_COMPILE_NORESULT = (1 << 7)    /* (internal) omit eval result */;

const int DUK_COMPILE_NOSOURCE = (1 << 8)    /* (internal) no source string on stack */;

const int DUK_COMPILE_STRLEN = (1 << 9)    /* (internal) take strlen() of src_buffer (avoids double evaluation in macro) */;

const int DUK_COMPILE_NOFILENAME = (1 << 10)    /* (internal) no filename on stack */;

const int DUK_DEFPROP_WRITABLE = (1 << 0)    /* set writable (effective if DUK_DEFPROP_HAVE_WRITABLE set) */;

const int DUK_DEFPROP_ENUMERABLE = (1 << 1)    /* set enumerable (effective if DUK_DEFPROP_HAVE_ENUMERABLE set) */;

const int DUK_DEFPROP_CONFIGURABLE = (1 << 2)    /* set configurable (effective if DUK_DEFPROP_HAVE_CONFIGURABLE set) */;

const int DUK_DEFPROP_HAVE_WRITABLE = (1 << 3)    /* set/clear writable */;

const int DUK_DEFPROP_HAVE_ENUMERABLE = (1 << 4)    /* set/clear enumerable */;

const int DUK_DEFPROP_HAVE_CONFIGURABLE = (1 << 5)    /* set/clear configurable */;

const int DUK_DEFPROP_HAVE_VALUE = (1 << 6)    /* set value (given on value stack) */;

const int DUK_DEFPROP_HAVE_GETTER = (1 << 7)    /* set getter (given on value stack) */;

const int DUK_DEFPROP_HAVE_SETTER = (1 << 8)    /* set setter (given on value stack) */;

const int DUK_DEFPROP_FORCE = (1 << 9)    /* force change if possible, may still fail for e.g. virtual properties */;

const int DUK_DEFPROP_SET_WRITABLE = (DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_WRITABLE);

const int DUK_DEFPROP_CLEAR_WRITABLE = DUK_DEFPROP_HAVE_WRITABLE;

const int DUK_DEFPROP_SET_ENUMERABLE = (DUK_DEFPROP_HAVE_ENUMERABLE | DUK_DEFPROP_ENUMERABLE);

const int DUK_DEFPROP_CLEAR_ENUMERABLE = DUK_DEFPROP_HAVE_ENUMERABLE;

const int DUK_DEFPROP_SET_CONFIGURABLE = (DUK_DEFPROP_HAVE_CONFIGURABLE | DUK_DEFPROP_CONFIGURABLE);

const int DUK_DEFPROP_CLEAR_CONFIGURABLE = DUK_DEFPROP_HAVE_CONFIGURABLE;

const int DUK_THREAD_NEW_GLOBAL_ENV = (1 << 0)    /* create a new global environment */;

const int DUK_STRING_PUSH_SAFE = (1 << 0)    /* no error if file does not exist */;

const int DUK_ERR_NONE = 0    /* no error (e.g. from duk_get_error_code()) */;

const int DUK_ERR_UNIMPLEMENTED_ERROR = 50   /* UnimplementedError */  /* XXX: replace with TypeError? */;

const int DUK_ERR_UNSUPPORTED_ERROR = 51   /* UnsupportedError */    /* XXX: replace with TypeError? */;

const int DUK_ERR_INTERNAL_ERROR = 52   /* InternalError */       /* XXX: replace with plain Error? */;

const int DUK_ERR_ALLOC_ERROR = 53   /* AllocError */          /* XXX: replace with RangeError? */;

const int DUK_ERR_ASSERTION_ERROR = 54   /* AssertionError */      /* XXX: to be removed? */;

const int DUK_ERR_API_ERROR = 55   /* APIError */            /* XXX: replace with TypeError? */;

const int DUK_ERR_UNCAUGHT_ERROR = 56   /* UncaughtError */       /* XXX: to be removed? */;

const int DUK_ERR_ERROR = 100  /* Error */;

const int DUK_ERR_EVAL_ERROR = 101  /* EvalError */;

const int DUK_ERR_RANGE_ERROR = 102  /* RangeError */;

const int DUK_ERR_REFERENCE_ERROR = 103  /* ReferenceError */;

const int DUK_ERR_SYNTAX_ERROR = 104  /* SyntaxError */;

const int DUK_ERR_TYPE_ERROR = 105  /* TypeError */;

const int DUK_ERR_URI_ERROR = 106  /* URIError */;

const int DUK_RET_UNIMPLEMENTED_ERROR = (-DUK_ERR_UNIMPLEMENTED_ERROR);

const int DUK_RET_UNSUPPORTED_ERROR = (-DUK_ERR_UNSUPPORTED_ERROR);

const int DUK_RET_INTERNAL_ERROR = (-DUK_ERR_INTERNAL_ERROR);

const int DUK_RET_ALLOC_ERROR = (-DUK_ERR_ALLOC_ERROR);

const int DUK_RET_ASSERTION_ERROR = (-DUK_ERR_ASSERTION_ERROR);

const int DUK_RET_API_ERROR = (-DUK_ERR_API_ERROR);

const int DUK_RET_UNCAUGHT_ERROR = (-DUK_ERR_UNCAUGHT_ERROR);

const int DUK_RET_ERROR = (-DUK_ERR_ERROR);

const int DUK_RET_EVAL_ERROR = (-DUK_ERR_EVAL_ERROR);

const int DUK_RET_RANGE_ERROR = (-DUK_ERR_RANGE_ERROR);

const int DUK_RET_REFERENCE_ERROR = (-DUK_ERR_REFERENCE_ERROR);

const int DUK_RET_SYNTAX_ERROR = (-DUK_ERR_SYNTAX_ERROR);

const int DUK_RET_TYPE_ERROR = (-DUK_ERR_TYPE_ERROR);

const int DUK_RET_URI_ERROR = (-DUK_ERR_URI_ERROR);

const int DUK_EXEC_SUCCESS = 0;

const int DUK_EXEC_ERROR = 1;

const int DUK_LOG_TRACE = 0;

const int DUK_LOG_DEBUG = 1;

const int DUK_LOG_INFO = 2;

const int DUK_LOG_WARN = 3;

const int DUK_LOG_ERROR = 4;

const int DUK_LOG_FATAL = 5;

#ifndef DUK_API_VARIADIC_MACROS
#endif
duk_context* duk_create_heap_default() {
return  	duk_create_heap(NULL, NULL, NULL, NULL, NULL)
;
}

#ifdef DUK_API_VARIADIC_MACROS
#else
#endif
void duk_error_va(duk_context *ctx, duk_errcode_t err_code, const char *fmt, va_list ap) {
 	duk_error_va_raw((ctx), (duk_errcode_t) (err_code), (const char *) (DUK_FILE_MACRO), (duk_int_t) (DUK_LINE_MACRO), (fmt), (ap))
;
}

void duk_xmove_top(duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count) {
 	duk_xcopymove_raw((to_ctx), (from_ctx), (count), 0 /*is_copy*/)
;
}

void duk_xcopy_top(duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count) {
 	duk_xcopymove_raw((to_ctx), (from_ctx), (count), 1 /*is_copy*/)
;
}

const char* duk_push_string_file(duk_context *ctx, const char* path) {
return  	duk_push_string_file_raw((ctx), (path), 0)
;
}

duk_idx_t duk_push_thread(duk_context *ctx) {
return  	duk_push_thread_raw((ctx), 0 /*flags*/)
;
}

duk_idx_t duk_push_thread_new_globalenv(duk_context *ctx) {
return  	duk_push_thread_raw((ctx), DUK_THREAD_NEW_GLOBAL_ENV /*flags*/)
;
}

#ifdef DUK_API_VARIADIC_MACROS
#else
#endif
duk_idx_t duk_push_error_object_va(duk_context *ctx, duk_errcode_t err_code, const char *fmt, va_list ap) {
return  	duk_push_error_object_va_raw((ctx), (err_code), (const char *) (DUK_FILE_MACRO), (duk_int_t) (DUK_LINE_MACRO), (fmt), (ap))
;
}

const int DUK_BUF_FLAG_DYNAMIC = (1 << 0)    /* internal flag: dynamic buffer */;

const int DUK_BUF_FLAG_EXTERNAL = (1 << 1)    /* internal flag: external buffer */;

const int DUK_BUF_FLAG_NOZERO = (1 << 2)    /* internal flag: don't zero allocated buffer */;

const void* duk_push_buffer(duk_context *ctx, duk_size_t size, duk_bool_t dynamic) {
return  	duk_push_buffer_raw((ctx), (size), (dynamic) ? DUK_BUF_FLAG_DYNAMIC : 0)
;
}

const void* duk_push_fixed_buffer(duk_context *ctx, duk_size_t size) {
return  	duk_push_buffer_raw((ctx), (size), 0 /*flags*/)
;
}

const void* duk_push_dynamic_buffer(duk_context *ctx, duk_size_t size) {
return  	duk_push_buffer_raw((ctx), (size), DUK_BUF_FLAG_DYNAMIC /*flags*/)
;
}

void duk_push_external_buffer(duk_context *ctx) {
 	((void) duk_push_buffer_raw((ctx), 0, DUK_BUF_FLAG_DYNAMIC | DUK_BUF_FLAG_EXTERNAL))
;
}

const int DUK_BUFOBJ_CREATE_ARRBUF = (1 << 4)  /* internal flag: create backing ArrayBuffer; keep in one byte */;

const int DUK_BUFOBJ_DUKTAPE_BUFFER = 0;

const int DUK_BUFOBJ_NODEJS_BUFFER = 1;

const int DUK_BUFOBJ_ARRAYBUFFER = 2;

const int DUK_BUFOBJ_DATAVIEW = (3 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_INT8ARRAY = (4 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_UINT8ARRAY = (5 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_UINT8CLAMPEDARRAY = (6 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_INT16ARRAY = (7 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_UINT16ARRAY = (8 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_INT32ARRAY = (9 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_UINT32ARRAY = (10 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_FLOAT32ARRAY = (11 | DUK_BUFOBJ_CREATE_ARRBUF);

const int DUK_BUFOBJ_FLOAT64ARRAY = (12 | DUK_BUFOBJ_CREATE_ARRBUF);

duk_bool_t duk_is_callable(duk_context *ctx, duk_idx_t index) {
return  	duk_is_function((ctx), (index))
;
}

duk_bool_t duk_is_primitive(duk_context *ctx, duk_idx_t index) {
return  	duk_check_type_mask((ctx), (index), DUK_TYPE_MASK_UNDEFINED |  	                                    DUK_TYPE_MASK_NULL |  	                                    DUK_TYPE_MASK_BOOLEAN |  	                                    DUK_TYPE_MASK_NUMBER |  	                                    DUK_TYPE_MASK_STRING |  	                                    DUK_TYPE_MASK_BUFFER |  	                                    DUK_TYPE_MASK_POINTER |  	                                    DUK_TYPE_MASK_LIGHTFUNC)
;
}

duk_bool_t duk_is_object_coercible(duk_context *ctx, duk_idx_t index) {
return  	duk_check_type_mask((ctx), (index), DUK_TYPE_MASK_BOOLEAN |  	                                    DUK_TYPE_MASK_NUMBER |  	                                    DUK_TYPE_MASK_STRING |  	                                    DUK_TYPE_MASK_OBJECT |  	                                    DUK_TYPE_MASK_BUFFER |  	                                    DUK_TYPE_MASK_POINTER |  	                                    DUK_TYPE_MASK_LIGHTFUNC)
;
}

duk_bool_t duk_is_error(duk_context *ctx, duk_idx_t index) {
return  	(duk_get_error_code((ctx), (index)) != 0)
;
}

duk_bool_t duk_is_eval_error(duk_context *ctx, duk_idx_t index) {
return  	(duk_get_error_code((ctx), (index)) == DUK_ERR_EVAL_ERROR)
;
}

duk_bool_t duk_is_range_error(duk_context *ctx, duk_idx_t index) {
return  	(duk_get_error_code((ctx), (index)) == DUK_ERR_RANGE_ERROR)
;
}

duk_bool_t duk_is_reference_error(duk_context *ctx, duk_idx_t index) {
return  	(duk_get_error_code((ctx), (index)) == DUK_ERR_REFERENCE_ERROR)
;
}

duk_bool_t duk_is_syntax_error(duk_context *ctx, duk_idx_t index) {
return  	(duk_get_error_code((ctx), (index)) == DUK_ERR_SYNTAX_ERROR)
;
}

duk_bool_t duk_is_type_error(duk_context *ctx, duk_idx_t index) {
return  	(duk_get_error_code((ctx), (index)) == DUK_ERR_TYPE_ERROR)
;
}

duk_bool_t duk_is_uri_error(duk_context *ctx, duk_idx_t index) {
return  	(duk_get_error_code((ctx), (index)) == DUK_ERR_URI_ERROR)
;
}

void duk_require_type_mask(duk_context *ctx, duk_idx_t index, duk_uint_t mask) {
 	((void) duk_check_type_mask((ctx), (index), (mask) | DUK_TYPE_MASK_THROW))
;
}

void duk_require_callable(duk_context *ctx, duk_idx_t index) {
 	duk_require_function((ctx), (index))
;
}

void duk_require_object_coercible(duk_context *ctx, duk_idx_t index) {
 	((void) duk_check_type_mask((ctx), (index), DUK_TYPE_MASK_BOOLEAN |  	                                            DUK_TYPE_MASK_NUMBER |  	                                            DUK_TYPE_MASK_STRING |  	                                            DUK_TYPE_MASK_OBJECT |  	                                            DUK_TYPE_MASK_BUFFER |  	                                            DUK_TYPE_MASK_POINTER |  	                                            DUK_TYPE_MASK_LIGHTFUNC |  	                                            DUK_TYPE_MASK_THROW))
;
}

const int DUK_BUF_MODE_FIXED = 0   /* internal: request fixed buffer result */;

const int DUK_BUF_MODE_DYNAMIC = 1   /* internal: request dynamic buffer result */;

const int DUK_BUF_MODE_DONTCARE = 2   /* internal: don't care about fixed/dynamic nature */;

const void* duk_to_buffer(duk_context *ctx, duk_idx_t index, duk_size_t *out_size) {
return  	duk_to_buffer_raw((ctx), (index), (out_size), DUK_BUF_MODE_DONTCARE)
;
}

const void* duk_to_fixed_buffer(duk_context *ctx, duk_idx_t index, duk_size_t *out_size) {
return  	duk_to_buffer_raw((ctx), (index), (out_size), DUK_BUF_MODE_FIXED)
;
}

const void* duk_to_dynamic_buffer(duk_context *ctx, duk_idx_t index, duk_size_t *out_size) {
return  	duk_to_buffer_raw((ctx), (index), (out_size), DUK_BUF_MODE_DYNAMIC)
;
}

const char* duk_safe_to_string(duk_context *ctx, duk_idx_t index) {
return  	duk_safe_to_lstring((ctx), (index), NULL)
;
}

void duk_eval(duk_context *ctx) {
 	((void) duk_eval_raw((ctx), NULL, 0, 2 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NOFILENAME))
;
}

void duk_eval_noresult(duk_context *ctx) {
 	((void) duk_eval_raw((ctx), NULL, 0, 2 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NORESULT | DUK_COMPILE_NOFILENAME))
;
}

void duk_peval(duk_context *ctx) {
 	(duk_eval_raw((ctx), NULL, 0, 2 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_SAFE | DUK_COMPILE_NOFILENAME))
;
}

void duk_peval_noresult(duk_context *ctx) {
 	(duk_eval_raw((ctx), NULL, 0, 2 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_SAFE | DUK_COMPILE_NORESULT | DUK_COMPILE_NOFILENAME))
;
}

void duk_compile(duk_context *ctx, duk_uint_t flags) {
 	((void) duk_compile_raw((ctx), NULL, 0, 3 /*args*/ | (flags)))
;
}

void duk_pcompile(duk_context *ctx, duk_uint_t flags) {
 	(duk_compile_raw((ctx), NULL, 0, 3 /*args*/ | (flags) | DUK_COMPILE_SAFE))
;
}

void duk_eval_string(duk_context *ctx, const char* src) {
 	((void) duk_eval_raw((ctx), (src), 0, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN | DUK_COMPILE_NOFILENAME))
;
}

void duk_eval_string_noresult(duk_context *ctx, const char* src) {
 	((void) duk_eval_raw((ctx), (src), 0, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN | DUK_COMPILE_NORESULT | DUK_COMPILE_NOFILENAME))
;
}

void duk_peval_string(duk_context *ctx, const char* src) {
 	(duk_eval_raw((ctx), (src), 0, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_SAFE | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN | DUK_COMPILE_NOFILENAME))
;
}

void duk_peval_string_noresult(duk_context *ctx, const char* src) {
 	(duk_eval_raw((ctx), (src), 0, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_SAFE | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN | DUK_COMPILE_NORESULT | DUK_COMPILE_NOFILENAME))
;
}

void duk_compile_string(duk_context *ctx, duk_uint_t flags, const char* src) {
 	((void) duk_compile_raw((ctx), (src), 0, 1 /*args*/ | (flags) | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN | DUK_COMPILE_NOFILENAME))
;
}

void duk_compile_string_filename(duk_context *ctx, duk_uint_t flags, const char* src) {
 	((void) duk_compile_raw((ctx), (src), 0, 2 /*args*/ | (flags) | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN))
;
}

void duk_pcompile_string(duk_context *ctx, duk_uint_t flags, const char* src) {
 	(duk_compile_raw((ctx), (src), 0, 1 /*args*/ | (flags) | DUK_COMPILE_SAFE | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN | DUK_COMPILE_NOFILENAME))
;
}

void duk_pcompile_string_filename(duk_context *ctx, duk_uint_t flags, const char* src) {
 	(duk_compile_raw((ctx), (src), 0, 2 /*args*/ | (flags) | DUK_COMPILE_SAFE | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN))
;
}

void duk_eval_lstring(duk_context *ctx, const char* buf, duk_size_t len) {
 	((void) duk_eval_raw((ctx), buf, len, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NOSOURCE | DUK_COMPILE_NOFILENAME))
;
}

void duk_eval_lstring_noresult(duk_context *ctx, const char* buf, duk_size_t len) {
 	((void) duk_eval_raw((ctx), buf, len, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NOSOURCE | DUK_COMPILE_NORESULT | DUK_COMPILE_NOFILENAME))
;
}

void duk_peval_lstring(duk_context *ctx, const char* buf, duk_size_t len) {
 	(duk_eval_raw((ctx), buf, len, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NOSOURCE | DUK_COMPILE_SAFE | DUK_COMPILE_NOFILENAME))
;
}

void duk_peval_lstring_noresult(duk_context *ctx, const char* buf, duk_size_t len) {
 	(duk_eval_raw((ctx), buf, len, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_SAFE | DUK_COMPILE_NOSOURCE | DUK_COMPILE_NORESULT | DUK_COMPILE_NOFILENAME))
;
}

void duk_compile_lstring(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len) {
 	((void) duk_compile_raw((ctx), buf, len, 1 /*args*/ | (flags) | DUK_COMPILE_NOSOURCE | DUK_COMPILE_NOFILENAME))
;
}

void duk_compile_lstring_filename(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len) {
 	((void) duk_compile_raw((ctx), buf, len, 2 /*args*/ | (flags) | DUK_COMPILE_NOSOURCE))
;
}

void duk_pcompile_lstring(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len) {
 	(duk_compile_raw((ctx), buf, len, 1 /*args*/ | (flags) | DUK_COMPILE_SAFE | DUK_COMPILE_NOSOURCE | DUK_COMPILE_NOFILENAME))
;
}

void duk_pcompile_lstring_filename(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len) {
 	(duk_compile_raw((ctx), buf, len, 2 /*args*/ | (flags) | DUK_COMPILE_SAFE | DUK_COMPILE_NOSOURCE))
;
}

void duk_eval_file(duk_context *ctx, const char *path) {
 	((void) duk_push_string_file_raw((ctx), (path), 0),  	 (void) duk_push_string((ctx), (path)),  	 (void) duk_eval_raw((ctx), NULL, 0, 3 /*args*/ | DUK_COMPILE_EVAL))
;
}

void duk_eval_file_noresult(duk_context *ctx, const char *path) {
 	((void) duk_push_string_file_raw((ctx), (path), 0),  	 (void) duk_push_string((ctx), (path)),  	 (void) duk_eval_raw((ctx), NULL, 0, 3 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NORESULT))
;
}

void duk_peval_file(duk_context *ctx, const char *path) {
 	((void) duk_push_string_file_raw((ctx), (path), DUK_STRING_PUSH_SAFE),  	 (void) duk_push_string((ctx), (path)),  	 duk_eval_raw((ctx), NULL, 0, 3 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_SAFE))
;
}

void duk_peval_file_noresult(duk_context *ctx, const char *path) {
 	((void) duk_push_string_file_raw((ctx), (path), DUK_STRING_PUSH_SAFE),  	 (void) duk_push_string((ctx), (path)),  	 duk_eval_raw((ctx), NULL, 0, 3 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_SAFE | DUK_COMPILE_NORESULT))
;
}

void duk_compile_file(duk_context *ctx, duk_uint_t flags, const char *path) {
 	((void) duk_push_string_file_raw((ctx), (path), 0),  	 (void) duk_push_string((ctx), (path)),  	 (void) duk_compile_raw((ctx), NULL, 0, 3 /*args*/ | (flags)))
;
}

void duk_pcompile_file(duk_context *ctx, duk_uint_t flags, const char *path) {
 	((void) duk_push_string_file_raw((ctx), (path), DUK_STRING_PUSH_SAFE),  	 (void) duk_push_string((ctx), (path)),  	 duk_compile_raw((ctx), NULL, 0, 3 /*args*/ | (flags) | DUK_COMPILE_SAFE))
;
}

#if defined(DUK_USE_FILE_IO)
void duk_dump_context_stdout(duk_context *ctx) {
 	duk_dump_context_filehandle((ctx), DUK_STDOUT)
;
}

void duk_dump_context_stderr(duk_context *ctx) {
 	duk_dump_context_filehandle((ctx), DUK_STDERR)
;
}

#else  /* DUK_USE_FILE_IO */
void duk_dump_context_stdout(duk_context *ctx) {
((void) 0);
}

void duk_dump_context_stderr(duk_context *ctx) {
((void) 0);
}

#endif  /* DUK_USE_FILE_IO */
void duk_debugger_attach(duk_context *ctx, duk_debug_read_function read_cb, duk_debug_write_function write_cb, duk_debug_peek_function peek_cb, duk_debug_read_flush_function read_flush_cb, duk_debug_write_flush_function write_flush_cb, duk_debug_detached_function detached_cb, void *udata) {
 	duk_debugger_attach_custom((ctx), (read_cb), (write_cb), (peek_cb), (read_flush_cb), (write_flush_cb),  	                           NULL, (detached_cb), (udata))
;
}

const int DUK_DATE_MSEC_SECOND = 1000L;

const int DUK_DATE_MSEC_MINUTE = (60L * 1000L);

const int DUK_DATE_MSEC_HOUR = (60L * 60L * 1000L);

const int DUK_DATE_MSEC_DAY = (24L * 60L * 60L * 1000L);

const double DUK_DATE_MSEC_100M_DAYS = (8.64e15);

const int DUK_DATE_MSEC_100M_DAYS_LEEWAY = (8.64e15 + 24 * 3600e3);

const int DUK_DATE_MIN_ECMA_YEAR = (-271821L);

const int DUK_DATE_MAX_ECMA_YEAR = 275760L;

const int DUK_DATE_IDX_YEAR = 0  /* year */;

const int DUK_DATE_IDX_MONTH = 1  /* month: 0 to 11 */;

const int DUK_DATE_IDX_DAY = 2  /* day within month: 0 to 30 */;

const int DUK_DATE_IDX_HOUR = 3;

const int DUK_DATE_IDX_MINUTE = 4;

const int DUK_DATE_IDX_SECOND = 5;

const int DUK_DATE_IDX_MILLISECOND = 6;

const int DUK_DATE_IDX_WEEKDAY = 7  /* weekday: 0 to 6, 0=sunday, 1=monday, etc */;

const int DUK_DATE_IDX_NUM_PARTS = 8;

const int DUK_DATE_FLAG_NAN_TO_ZERO = (1 << 0)  /* timeval breakdown: internal time value NaN -> zero */;

const int DUK_DATE_FLAG_NAN_TO_RANGE_ERROR = (1 << 1)  /* timeval breakdown: internal time value NaN -> RangeError (toISOString) */;

const int DUK_DATE_FLAG_ONEBASED = (1 << 2)  /* timeval breakdown: convert month and day-of-month parts to one-based (default is zero-based) */;

const int DUK_DATE_FLAG_EQUIVYEAR = (1 << 3)  /* timeval breakdown: replace year with equivalent year in the [1971,2037] range for DST calculations */;

const int DUK_DATE_FLAG_LOCALTIME = (1 << 4)  /* convert time value to local time */;

const int DUK_DATE_FLAG_SUB1900 = (1 << 5)  /* getter: subtract 1900 from year when getting year part */;

const int DUK_DATE_FLAG_TOSTRING_DATE = (1 << 6)  /* include date part in string conversion result */;

const int DUK_DATE_FLAG_TOSTRING_TIME = (1 << 7)  /* include time part in string conversion result */;

const int DUK_DATE_FLAG_TOSTRING_LOCALE = (1 << 8)  /* use locale specific formatting if available */;

const int DUK_DATE_FLAG_TIMESETTER = (1 << 9)  /* setter: call is a time setter (affects hour, min, sec, ms); otherwise date setter (affects year, month, day-in-month) */;

const int DUK_DATE_FLAG_YEAR_FIXUP = (1 << 10) /* setter: perform 2-digit year fixup (00...99 -> 1900...1999) */;

const int DUK_DATE_FLAG_SEP_T = (1 << 11) /* string conversion: use 'T' instead of ' ' as a separator */;

const int DUK_DATE_FLAG_VALUE_SHIFT = 12        /* additional values begin at bit 12 */;

#if defined(DUK_USE_ROM_OBJECTS) && defined(DUK_USE_HEAPPTR16)
#endif
#ifdef __cplusplus
#endif
#endif  /* DUK_API_PUBLIC_H_INCLUDED */
#endif