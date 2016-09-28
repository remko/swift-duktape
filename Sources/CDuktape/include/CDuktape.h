#import "../duktape.h"

#undef duk_safe_to_string
const char* duk_safe_to_string(duk_context *ctx, duk_idx_t index);
#undef duk_eval_string
void duk_eval_string(duk_context *ctx, const char *src);
#undef duk_eval_file_noresult
void duk_eval_file_noresult(duk_context *ctx, const char *path);
