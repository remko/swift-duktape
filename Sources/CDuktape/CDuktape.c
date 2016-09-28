#include "include/CDuktape.h"

const char* duk_safe_to_string(duk_context *ctx, duk_idx_t index) {
return  	duk_safe_to_lstring((ctx), (index), NULL)
;
}

void duk_eval_string(duk_context *ctx, const char *src) {
 	((void) duk_eval_raw((ctx), (src), 0, 1 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NOSOURCE | DUK_COMPILE_STRLEN | DUK_COMPILE_NOFILENAME))
;
}

void duk_eval_file_noresult(duk_context *ctx, const char *path) {
 	((void) duk_push_string_file_raw((ctx), (path), 0),  	 (void) duk_push_string((ctx), (path)),  	 (void) duk_eval_raw((ctx), NULL, 0, 3 /*args*/ | DUK_COMPILE_EVAL | DUK_COMPILE_NORESULT))
;
}

