#import "../duktape.h"

#ifndef DUKTAPE_H_INCLUDED_
#define DUKTAPE_H_INCLUDED_
#define DUK_SINGLE_FILE
#ifndef DUK_API_PUBLIC_H_INCLUDED_
#define DUK_API_PUBLIC_H_INCLUDED_
#ifdef __cplusplus
#endif
#undef DUK_API_VARIADIC_MACROS
#ifdef DUK_USE_VARIADIC_MACROS
#define DUK_API_VARIADIC_MACROS
#endif
#undef DUK_VERSION
extern const int DUK_VERSION;

#undef DUK_GIT_COMMIT
extern const char* DUK_GIT_COMMIT;

#undef DUK_GIT_DESCRIBE
extern const char* DUK_GIT_DESCRIBE;

#undef DUK_GIT_BRANCH
extern const char* DUK_GIT_BRANCH;

#undef DUK_DEBUG_PROTOCOL_VERSION
extern const int DUK_DEBUG_PROTOCOL_VERSION;

#undef DUK_INVALID_INDEX
extern const int DUK_INVALID_INDEX;

#undef DUK_VARARGS
extern const int DUK_VARARGS;

#undef DUK_API_ENTRY_STACK
extern const int DUK_API_ENTRY_STACK;

#undef DUK_TYPE_MIN
extern const int DUK_TYPE_MIN;

#undef DUK_TYPE_NONE
extern const int DUK_TYPE_NONE;

#undef DUK_TYPE_UNDEFINED
extern const int DUK_TYPE_UNDEFINED;

#undef DUK_TYPE_NULL
extern const int DUK_TYPE_NULL;

#undef DUK_TYPE_BOOLEAN
extern const int DUK_TYPE_BOOLEAN;

#undef DUK_TYPE_NUMBER
extern const int DUK_TYPE_NUMBER;

#undef DUK_TYPE_STRING
extern const int DUK_TYPE_STRING;

#undef DUK_TYPE_OBJECT
extern const int DUK_TYPE_OBJECT;

#undef DUK_TYPE_BUFFER
extern const int DUK_TYPE_BUFFER;

#undef DUK_TYPE_POINTER
extern const int DUK_TYPE_POINTER;

#undef DUK_TYPE_LIGHTFUNC
extern const int DUK_TYPE_LIGHTFUNC;

#undef DUK_TYPE_MAX
extern const int DUK_TYPE_MAX;

#undef DUK_TYPE_MASK_NONE
extern const int DUK_TYPE_MASK_NONE;

#undef DUK_TYPE_MASK_UNDEFINED
extern const int DUK_TYPE_MASK_UNDEFINED;

#undef DUK_TYPE_MASK_NULL
extern const int DUK_TYPE_MASK_NULL;

#undef DUK_TYPE_MASK_BOOLEAN
extern const int DUK_TYPE_MASK_BOOLEAN;

#undef DUK_TYPE_MASK_NUMBER
extern const int DUK_TYPE_MASK_NUMBER;

#undef DUK_TYPE_MASK_STRING
extern const int DUK_TYPE_MASK_STRING;

#undef DUK_TYPE_MASK_OBJECT
extern const int DUK_TYPE_MASK_OBJECT;

#undef DUK_TYPE_MASK_BUFFER
extern const int DUK_TYPE_MASK_BUFFER;

#undef DUK_TYPE_MASK_POINTER
extern const int DUK_TYPE_MASK_POINTER;

#undef DUK_TYPE_MASK_LIGHTFUNC
extern const int DUK_TYPE_MASK_LIGHTFUNC;

#undef DUK_TYPE_MASK_THROW
extern const int DUK_TYPE_MASK_THROW;

#undef DUK_HINT_NONE
extern const int DUK_HINT_NONE;

#undef DUK_HINT_STRING
extern const int DUK_HINT_STRING;

#undef DUK_HINT_NUMBER
extern const int DUK_HINT_NUMBER;

#undef DUK_ENUM_INCLUDE_NONENUMERABLE
extern const int DUK_ENUM_INCLUDE_NONENUMERABLE;

#undef DUK_ENUM_INCLUDE_INTERNAL
extern const int DUK_ENUM_INCLUDE_INTERNAL;

#undef DUK_ENUM_OWN_PROPERTIES_ONLY
extern const int DUK_ENUM_OWN_PROPERTIES_ONLY;

#undef DUK_ENUM_ARRAY_INDICES_ONLY
extern const int DUK_ENUM_ARRAY_INDICES_ONLY;

#undef DUK_ENUM_SORT_ARRAY_INDICES
extern const int DUK_ENUM_SORT_ARRAY_INDICES;

#undef DUK_ENUM_NO_PROXY_BEHAVIOR
extern const int DUK_ENUM_NO_PROXY_BEHAVIOR;

#undef DUK_COMPILE_EVAL
extern const int DUK_COMPILE_EVAL;

#undef DUK_COMPILE_FUNCTION
extern const int DUK_COMPILE_FUNCTION;

#undef DUK_COMPILE_STRICT
extern const int DUK_COMPILE_STRICT;

#undef DUK_COMPILE_SAFE
extern const int DUK_COMPILE_SAFE;

#undef DUK_COMPILE_NORESULT
extern const int DUK_COMPILE_NORESULT;

#undef DUK_COMPILE_NOSOURCE
extern const int DUK_COMPILE_NOSOURCE;

#undef DUK_COMPILE_STRLEN
extern const int DUK_COMPILE_STRLEN;

#undef DUK_COMPILE_NOFILENAME
extern const int DUK_COMPILE_NOFILENAME;

#undef DUK_DEFPROP_WRITABLE
extern const int DUK_DEFPROP_WRITABLE;

#undef DUK_DEFPROP_ENUMERABLE
extern const int DUK_DEFPROP_ENUMERABLE;

#undef DUK_DEFPROP_CONFIGURABLE
extern const int DUK_DEFPROP_CONFIGURABLE;

#undef DUK_DEFPROP_HAVE_WRITABLE
extern const int DUK_DEFPROP_HAVE_WRITABLE;

#undef DUK_DEFPROP_HAVE_ENUMERABLE
extern const int DUK_DEFPROP_HAVE_ENUMERABLE;

#undef DUK_DEFPROP_HAVE_CONFIGURABLE
extern const int DUK_DEFPROP_HAVE_CONFIGURABLE;

#undef DUK_DEFPROP_HAVE_VALUE
extern const int DUK_DEFPROP_HAVE_VALUE;

#undef DUK_DEFPROP_HAVE_GETTER
extern const int DUK_DEFPROP_HAVE_GETTER;

#undef DUK_DEFPROP_HAVE_SETTER
extern const int DUK_DEFPROP_HAVE_SETTER;

#undef DUK_DEFPROP_FORCE
extern const int DUK_DEFPROP_FORCE;

#undef DUK_DEFPROP_SET_WRITABLE
extern const int DUK_DEFPROP_SET_WRITABLE;

#undef DUK_DEFPROP_CLEAR_WRITABLE
extern const int DUK_DEFPROP_CLEAR_WRITABLE;

#undef DUK_DEFPROP_SET_ENUMERABLE
extern const int DUK_DEFPROP_SET_ENUMERABLE;

#undef DUK_DEFPROP_CLEAR_ENUMERABLE
extern const int DUK_DEFPROP_CLEAR_ENUMERABLE;

#undef DUK_DEFPROP_SET_CONFIGURABLE
extern const int DUK_DEFPROP_SET_CONFIGURABLE;

#undef DUK_DEFPROP_CLEAR_CONFIGURABLE
extern const int DUK_DEFPROP_CLEAR_CONFIGURABLE;

#undef DUK_THREAD_NEW_GLOBAL_ENV
extern const int DUK_THREAD_NEW_GLOBAL_ENV;

#undef DUK_STRING_PUSH_SAFE
extern const int DUK_STRING_PUSH_SAFE;

#undef DUK_ERR_NONE
extern const int DUK_ERR_NONE;

#undef DUK_ERR_UNIMPLEMENTED_ERROR
extern const int DUK_ERR_UNIMPLEMENTED_ERROR;

#undef DUK_ERR_UNSUPPORTED_ERROR
extern const int DUK_ERR_UNSUPPORTED_ERROR;

#undef DUK_ERR_INTERNAL_ERROR
extern const int DUK_ERR_INTERNAL_ERROR;

#undef DUK_ERR_ALLOC_ERROR
extern const int DUK_ERR_ALLOC_ERROR;

#undef DUK_ERR_ASSERTION_ERROR
extern const int DUK_ERR_ASSERTION_ERROR;

#undef DUK_ERR_API_ERROR
extern const int DUK_ERR_API_ERROR;

#undef DUK_ERR_UNCAUGHT_ERROR
extern const int DUK_ERR_UNCAUGHT_ERROR;

#undef DUK_ERR_ERROR
extern const int DUK_ERR_ERROR;

#undef DUK_ERR_EVAL_ERROR
extern const int DUK_ERR_EVAL_ERROR;

#undef DUK_ERR_RANGE_ERROR
extern const int DUK_ERR_RANGE_ERROR;

#undef DUK_ERR_REFERENCE_ERROR
extern const int DUK_ERR_REFERENCE_ERROR;

#undef DUK_ERR_SYNTAX_ERROR
extern const int DUK_ERR_SYNTAX_ERROR;

#undef DUK_ERR_TYPE_ERROR
extern const int DUK_ERR_TYPE_ERROR;

#undef DUK_ERR_URI_ERROR
extern const int DUK_ERR_URI_ERROR;

#undef DUK_RET_UNIMPLEMENTED_ERROR
extern const int DUK_RET_UNIMPLEMENTED_ERROR;

#undef DUK_RET_UNSUPPORTED_ERROR
extern const int DUK_RET_UNSUPPORTED_ERROR;

#undef DUK_RET_INTERNAL_ERROR
extern const int DUK_RET_INTERNAL_ERROR;

#undef DUK_RET_ALLOC_ERROR
extern const int DUK_RET_ALLOC_ERROR;

#undef DUK_RET_ASSERTION_ERROR
extern const int DUK_RET_ASSERTION_ERROR;

#undef DUK_RET_API_ERROR
extern const int DUK_RET_API_ERROR;

#undef DUK_RET_UNCAUGHT_ERROR
extern const int DUK_RET_UNCAUGHT_ERROR;

#undef DUK_RET_ERROR
extern const int DUK_RET_ERROR;

#undef DUK_RET_EVAL_ERROR
extern const int DUK_RET_EVAL_ERROR;

#undef DUK_RET_RANGE_ERROR
extern const int DUK_RET_RANGE_ERROR;

#undef DUK_RET_REFERENCE_ERROR
extern const int DUK_RET_REFERENCE_ERROR;

#undef DUK_RET_SYNTAX_ERROR
extern const int DUK_RET_SYNTAX_ERROR;

#undef DUK_RET_TYPE_ERROR
extern const int DUK_RET_TYPE_ERROR;

#undef DUK_RET_URI_ERROR
extern const int DUK_RET_URI_ERROR;

#undef DUK_EXEC_SUCCESS
extern const int DUK_EXEC_SUCCESS;

#undef DUK_EXEC_ERROR
extern const int DUK_EXEC_ERROR;

#undef DUK_LOG_TRACE
extern const int DUK_LOG_TRACE;

#undef DUK_LOG_DEBUG
extern const int DUK_LOG_DEBUG;

#undef DUK_LOG_INFO
extern const int DUK_LOG_INFO;

#undef DUK_LOG_WARN
extern const int DUK_LOG_WARN;

#undef DUK_LOG_ERROR
extern const int DUK_LOG_ERROR;

#undef DUK_LOG_FATAL
extern const int DUK_LOG_FATAL;

#ifndef DUK_API_VARIADIC_MACROS
#endif
#undef duk_create_heap_default
duk_context* duk_create_heap_default();
#ifdef DUK_API_VARIADIC_MACROS
#else
#endif
#undef duk_error_va
void duk_error_va(duk_context *ctx, duk_errcode_t err_code, const char *fmt, va_list ap);
#undef duk_xmove_top
void duk_xmove_top(duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count);
#undef duk_xcopy_top
void duk_xcopy_top(duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count);
#undef duk_push_string_file
const char* duk_push_string_file(duk_context *ctx, const char* path);
#undef duk_push_thread
duk_idx_t duk_push_thread(duk_context *ctx);
#undef duk_push_thread_new_globalenv
duk_idx_t duk_push_thread_new_globalenv(duk_context *ctx);
#ifdef DUK_API_VARIADIC_MACROS
#else
#endif
#undef duk_push_error_object_va
duk_idx_t duk_push_error_object_va(duk_context *ctx, duk_errcode_t err_code, const char *fmt, va_list ap);
#undef DUK_BUF_FLAG_DYNAMIC
extern const int DUK_BUF_FLAG_DYNAMIC;

#undef DUK_BUF_FLAG_EXTERNAL
extern const int DUK_BUF_FLAG_EXTERNAL;

#undef DUK_BUF_FLAG_NOZERO
extern const int DUK_BUF_FLAG_NOZERO;

#undef duk_push_buffer
const void* duk_push_buffer(duk_context *ctx, duk_size_t size, duk_bool_t dynamic);
#undef duk_push_fixed_buffer
const void* duk_push_fixed_buffer(duk_context *ctx, duk_size_t size);
#undef duk_push_dynamic_buffer
const void* duk_push_dynamic_buffer(duk_context *ctx, duk_size_t size);
#undef duk_push_external_buffer
void duk_push_external_buffer(duk_context *ctx);
#undef DUK_BUFOBJ_CREATE_ARRBUF
extern const int DUK_BUFOBJ_CREATE_ARRBUF;

#undef DUK_BUFOBJ_DUKTAPE_BUFFER
extern const int DUK_BUFOBJ_DUKTAPE_BUFFER;

#undef DUK_BUFOBJ_NODEJS_BUFFER
extern const int DUK_BUFOBJ_NODEJS_BUFFER;

#undef DUK_BUFOBJ_ARRAYBUFFER
extern const int DUK_BUFOBJ_ARRAYBUFFER;

#undef DUK_BUFOBJ_DATAVIEW
extern const int DUK_BUFOBJ_DATAVIEW;

#undef DUK_BUFOBJ_INT8ARRAY
extern const int DUK_BUFOBJ_INT8ARRAY;

#undef DUK_BUFOBJ_UINT8ARRAY
extern const int DUK_BUFOBJ_UINT8ARRAY;

#undef DUK_BUFOBJ_UINT8CLAMPEDARRAY
extern const int DUK_BUFOBJ_UINT8CLAMPEDARRAY;

#undef DUK_BUFOBJ_INT16ARRAY
extern const int DUK_BUFOBJ_INT16ARRAY;

#undef DUK_BUFOBJ_UINT16ARRAY
extern const int DUK_BUFOBJ_UINT16ARRAY;

#undef DUK_BUFOBJ_INT32ARRAY
extern const int DUK_BUFOBJ_INT32ARRAY;

#undef DUK_BUFOBJ_UINT32ARRAY
extern const int DUK_BUFOBJ_UINT32ARRAY;

#undef DUK_BUFOBJ_FLOAT32ARRAY
extern const int DUK_BUFOBJ_FLOAT32ARRAY;

#undef DUK_BUFOBJ_FLOAT64ARRAY
extern const int DUK_BUFOBJ_FLOAT64ARRAY;

#undef duk_is_callable
duk_bool_t duk_is_callable(duk_context *ctx, duk_idx_t index);
#undef duk_is_primitive
duk_bool_t duk_is_primitive(duk_context *ctx, duk_idx_t index);
#undef duk_is_object_coercible
duk_bool_t duk_is_object_coercible(duk_context *ctx, duk_idx_t index);
#undef duk_is_error
duk_bool_t duk_is_error(duk_context *ctx, duk_idx_t index);
#undef duk_is_eval_error
duk_bool_t duk_is_eval_error(duk_context *ctx, duk_idx_t index);
#undef duk_is_range_error
duk_bool_t duk_is_range_error(duk_context *ctx, duk_idx_t index);
#undef duk_is_reference_error
duk_bool_t duk_is_reference_error(duk_context *ctx, duk_idx_t index);
#undef duk_is_syntax_error
duk_bool_t duk_is_syntax_error(duk_context *ctx, duk_idx_t index);
#undef duk_is_type_error
duk_bool_t duk_is_type_error(duk_context *ctx, duk_idx_t index);
#undef duk_is_uri_error
duk_bool_t duk_is_uri_error(duk_context *ctx, duk_idx_t index);
#undef duk_require_type_mask
void duk_require_type_mask(duk_context *ctx, duk_idx_t index, duk_uint_t mask);
#undef duk_require_callable
void duk_require_callable(duk_context *ctx, duk_idx_t index);
#undef duk_require_object_coercible
void duk_require_object_coercible(duk_context *ctx, duk_idx_t index);
#undef DUK_BUF_MODE_FIXED
extern const int DUK_BUF_MODE_FIXED;

#undef DUK_BUF_MODE_DYNAMIC
extern const int DUK_BUF_MODE_DYNAMIC;

#undef DUK_BUF_MODE_DONTCARE
extern const int DUK_BUF_MODE_DONTCARE;

#undef duk_to_buffer
const void* duk_to_buffer(duk_context *ctx, duk_idx_t index, duk_size_t *out_size);
#undef duk_to_fixed_buffer
const void* duk_to_fixed_buffer(duk_context *ctx, duk_idx_t index, duk_size_t *out_size);
#undef duk_to_dynamic_buffer
const void* duk_to_dynamic_buffer(duk_context *ctx, duk_idx_t index, duk_size_t *out_size);
#undef duk_safe_to_string
const char* duk_safe_to_string(duk_context *ctx, duk_idx_t index);
#undef duk_eval
void duk_eval(duk_context *ctx);
#undef duk_eval_noresult
void duk_eval_noresult(duk_context *ctx);
#undef duk_peval
void duk_peval(duk_context *ctx);
#undef duk_peval_noresult
void duk_peval_noresult(duk_context *ctx);
#undef duk_compile
void duk_compile(duk_context *ctx, duk_uint_t flags);
#undef duk_pcompile
void duk_pcompile(duk_context *ctx, duk_uint_t flags);
#undef duk_eval_string
void duk_eval_string(duk_context *ctx, const char* src);
#undef duk_eval_string_noresult
void duk_eval_string_noresult(duk_context *ctx, const char* src);
#undef duk_peval_string
void duk_peval_string(duk_context *ctx, const char* src);
#undef duk_peval_string_noresult
void duk_peval_string_noresult(duk_context *ctx, const char* src);
#undef duk_compile_string
void duk_compile_string(duk_context *ctx, duk_uint_t flags, const char* src);
#undef duk_compile_string_filename
void duk_compile_string_filename(duk_context *ctx, duk_uint_t flags, const char* src);
#undef duk_pcompile_string
void duk_pcompile_string(duk_context *ctx, duk_uint_t flags, const char* src);
#undef duk_pcompile_string_filename
void duk_pcompile_string_filename(duk_context *ctx, duk_uint_t flags, const char* src);
#undef duk_eval_lstring
void duk_eval_lstring(duk_context *ctx, const char* buf, duk_size_t len);
#undef duk_eval_lstring_noresult
void duk_eval_lstring_noresult(duk_context *ctx, const char* buf, duk_size_t len);
#undef duk_peval_lstring
void duk_peval_lstring(duk_context *ctx, const char* buf, duk_size_t len);
#undef duk_peval_lstring_noresult
void duk_peval_lstring_noresult(duk_context *ctx, const char* buf, duk_size_t len);
#undef duk_compile_lstring
void duk_compile_lstring(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len);
#undef duk_compile_lstring_filename
void duk_compile_lstring_filename(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len);
#undef duk_pcompile_lstring
void duk_pcompile_lstring(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len);
#undef duk_pcompile_lstring_filename
void duk_pcompile_lstring_filename(duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len);
#undef duk_eval_file
void duk_eval_file(duk_context *ctx, const char *path);
#undef duk_eval_file_noresult
void duk_eval_file_noresult(duk_context *ctx, const char *path);
#undef duk_peval_file
void duk_peval_file(duk_context *ctx, const char *path);
#undef duk_peval_file_noresult
void duk_peval_file_noresult(duk_context *ctx, const char *path);
#undef duk_compile_file
void duk_compile_file(duk_context *ctx, duk_uint_t flags, const char *path);
#undef duk_pcompile_file
void duk_pcompile_file(duk_context *ctx, duk_uint_t flags, const char *path);
#if defined(DUK_USE_FILE_IO)
#undef duk_dump_context_stdout
void duk_dump_context_stdout(duk_context *ctx);
#undef duk_dump_context_stderr
void duk_dump_context_stderr(duk_context *ctx);
#else  /* DUK_USE_FILE_IO */
#undef duk_dump_context_stdout
void duk_dump_context_stdout(duk_context *ctx);
#undef duk_dump_context_stderr
void duk_dump_context_stderr(duk_context *ctx);
#endif  /* DUK_USE_FILE_IO */
#undef duk_debugger_attach
void duk_debugger_attach(duk_context *ctx, duk_debug_read_function read_cb, duk_debug_write_function write_cb, duk_debug_peek_function peek_cb, duk_debug_read_flush_function read_flush_cb, duk_debug_write_flush_function write_flush_cb, duk_debug_detached_function detached_cb, void *udata);
#undef DUK_DATE_MSEC_SECOND
extern const int DUK_DATE_MSEC_SECOND;

#undef DUK_DATE_MSEC_MINUTE
extern const int DUK_DATE_MSEC_MINUTE;

#undef DUK_DATE_MSEC_HOUR
extern const int DUK_DATE_MSEC_HOUR;

#undef DUK_DATE_MSEC_DAY
extern const int DUK_DATE_MSEC_DAY;

#undef DUK_DATE_MSEC_100M_DAYS
extern const double DUK_DATE_MSEC_100M_DAYS;

#undef DUK_DATE_MSEC_100M_DAYS_LEEWAY
extern const int DUK_DATE_MSEC_100M_DAYS_LEEWAY;

#undef DUK_DATE_MIN_ECMA_YEAR
extern const int DUK_DATE_MIN_ECMA_YEAR;

#undef DUK_DATE_MAX_ECMA_YEAR
extern const int DUK_DATE_MAX_ECMA_YEAR;

#undef DUK_DATE_IDX_YEAR
extern const int DUK_DATE_IDX_YEAR;

#undef DUK_DATE_IDX_MONTH
extern const int DUK_DATE_IDX_MONTH;

#undef DUK_DATE_IDX_DAY
extern const int DUK_DATE_IDX_DAY;

#undef DUK_DATE_IDX_HOUR
extern const int DUK_DATE_IDX_HOUR;

#undef DUK_DATE_IDX_MINUTE
extern const int DUK_DATE_IDX_MINUTE;

#undef DUK_DATE_IDX_SECOND
extern const int DUK_DATE_IDX_SECOND;

#undef DUK_DATE_IDX_MILLISECOND
extern const int DUK_DATE_IDX_MILLISECOND;

#undef DUK_DATE_IDX_WEEKDAY
extern const int DUK_DATE_IDX_WEEKDAY;

#undef DUK_DATE_IDX_NUM_PARTS
extern const int DUK_DATE_IDX_NUM_PARTS;

#undef DUK_DATE_FLAG_NAN_TO_ZERO
extern const int DUK_DATE_FLAG_NAN_TO_ZERO;

#undef DUK_DATE_FLAG_NAN_TO_RANGE_ERROR
extern const int DUK_DATE_FLAG_NAN_TO_RANGE_ERROR;

#undef DUK_DATE_FLAG_ONEBASED
extern const int DUK_DATE_FLAG_ONEBASED;

#undef DUK_DATE_FLAG_EQUIVYEAR
extern const int DUK_DATE_FLAG_EQUIVYEAR;

#undef DUK_DATE_FLAG_LOCALTIME
extern const int DUK_DATE_FLAG_LOCALTIME;

#undef DUK_DATE_FLAG_SUB1900
extern const int DUK_DATE_FLAG_SUB1900;

#undef DUK_DATE_FLAG_TOSTRING_DATE
extern const int DUK_DATE_FLAG_TOSTRING_DATE;

#undef DUK_DATE_FLAG_TOSTRING_TIME
extern const int DUK_DATE_FLAG_TOSTRING_TIME;

#undef DUK_DATE_FLAG_TOSTRING_LOCALE
extern const int DUK_DATE_FLAG_TOSTRING_LOCALE;

#undef DUK_DATE_FLAG_TIMESETTER
extern const int DUK_DATE_FLAG_TIMESETTER;

#undef DUK_DATE_FLAG_YEAR_FIXUP
extern const int DUK_DATE_FLAG_YEAR_FIXUP;

#undef DUK_DATE_FLAG_SEP_T
extern const int DUK_DATE_FLAG_SEP_T;

#undef DUK_DATE_FLAG_VALUE_SHIFT
extern const int DUK_DATE_FLAG_VALUE_SHIFT;

#if defined(DUK_USE_ROM_OBJECTS) && defined(DUK_USE_HEAPPTR16)
#endif
#ifdef __cplusplus
#endif
#endif  /* DUK_API_PUBLIC_H_INCLUDED */
#endif