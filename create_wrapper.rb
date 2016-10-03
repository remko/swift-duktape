#!/usr/bin/env ruby

SOURCE_INCLUDE_FILE=ARGV[0]
TARGET_INCLUDE_FILE=ARGV[1]
TARGET_SOURCE_FILE=ARGV[2]
TEST_SOURCE_FILE=ARGV[3]

MACROS = {
	"duk_eval_file" => ["void", "duk_context *ctx, const char *path"],
	"duk_eval_file_noresult" => ["void", "duk_context *ctx, const char *path"],
	"duk_peval_file" => ["void", "duk_context *ctx, const char *path"],
	"duk_peval_file_noresult" => ["void", "duk_context *ctx, const char *path"],
	"duk_compile_file" => ["void", "duk_context *ctx, duk_uint_t flags, const char *path"],
	"duk_pcompile_file" => ["void", "duk_context *ctx, duk_uint_t flags, const char *path"],
	"duk_safe_to_string" => ["const char*", "duk_context *ctx, duk_idx_t index"],
	"duk_create_heap_default" => ["duk_context*"],
	"duk_error_va" => ["void", "duk_context *ctx, duk_errcode_t err_code, const char *fmt, va_list ap"],
	"duk_push_error_object_va" => ["duk_idx_t", "duk_context *ctx, duk_errcode_t err_code, const char *fmt, va_list ap"],
	"duk_push_thread" => ["duk_idx_t", "duk_context *ctx"],
	"duk_push_thread_new_globalenv" => ["duk_idx_t", "duk_context *ctx"],
	"duk_push_string_file" => ["const char*", "duk_context *ctx, const char* path"],
	"duk_push_buffer" => ["const void*", "duk_context *ctx, duk_size_t size, duk_bool_t dynamic"],
	"duk_push_fixed_buffer" => ["const void*", "duk_context *ctx, duk_size_t size"],
	"duk_push_dynamic_buffer" => ["const void*", "duk_context *ctx, duk_size_t size"],
	"duk_push_external_buffer" => ["void", "duk_context *ctx"],
	"duk_require_type_mask" => ["void", "duk_context *ctx, duk_idx_t index, duk_uint_t mask"],
	"duk_require_object_coercible" => ["void", "duk_context *ctx, duk_idx_t index"],
	"duk_require_callable" => ["void", "duk_context *ctx, duk_idx_t index"],
	"duk_xmove_top" => ["void", "duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count"],
	"duk_xcopy_top" => ["void", "duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count"],
	"duk_to_buffer" => ["const void*", "duk_context *ctx, duk_idx_t index, duk_size_t *out_size"],
	"duk_to_fixed_buffer" => ["const void*", "duk_context *ctx, duk_idx_t index, duk_size_t *out_size"],
	"duk_to_dynamic_buffer" => ["const void*", "duk_context *ctx, duk_idx_t index, duk_size_t *out_size"],
	"duk_dump_context_stdout" => ["void", "duk_context *ctx"],
	"duk_dump_context_stderr" => ["void", "duk_context *ctx"],
	"duk_eval" => ["void", "duk_context *ctx"],
	"duk_eval_noresult" => ["void", "duk_context *ctx"],
	"duk_peval" => ["void", "duk_context *ctx"],
	"duk_peval_noresult" => ["void", "duk_context *ctx"],
	"duk_compile" => ["void", "duk_context *ctx, duk_uint_t flags"],
	"duk_pcompile" => ["void", "duk_context *ctx, duk_uint_t flags"],
	"duk_eval_string" => ["void", "duk_context *ctx, const char* src"],
	"duk_eval_string_noresult" => ["void", "duk_context *ctx, const char* src"],
	"duk_peval_string" => ["void", "duk_context *ctx, const char* src"],
	"duk_peval_string_noresult" => ["void", "duk_context *ctx, const char* src"],
	"duk_eval_lstring" => ["void", "duk_context *ctx, const char* buf, duk_size_t len"],
	"duk_eval_lstring_noresult" => ["void", "duk_context *ctx, const char* buf, duk_size_t len"],
	"duk_peval_lstring" => ["void", "duk_context *ctx, const char* buf, duk_size_t len"],
	"duk_peval_lstring_noresult" => ["void", "duk_context *ctx, const char* buf, duk_size_t len"],
	"duk_compile_string" => ["void", "duk_context *ctx, duk_uint_t flags, const char* src"],
	"duk_pcompile_string" => ["void", "duk_context *ctx, duk_uint_t flags, const char* src"],
	"duk_compile_lstring" => ["void", "duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len"],
	"duk_pcompile_lstring" => ["void", "duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len"],
	"duk_compile_lstring_filename" => ["void", "duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len"],
	"duk_pcompile_lstring_filename" => ["void", "duk_context *ctx, duk_uint_t flags, const char* buf, duk_size_t len"],
	"duk_compile_string_filename" => ["void", "duk_context *ctx, duk_uint_t flags, const char* src"],
	"duk_pcompile_string_filename" => ["void", "duk_context *ctx, duk_uint_t flags, const char* src"],
	"duk_debugger_attach" => ["void", "duk_context *ctx, duk_debug_read_function read_cb, duk_debug_write_function write_cb, duk_debug_peek_function peek_cb, duk_debug_read_flush_function read_flush_cb, duk_debug_write_flush_function write_flush_cb, duk_debug_detached_function detached_cb, void *udata"],
	"duk_is_callable" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_primitive" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_object_coercible" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_error" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_eval_error" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_range_error" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_reference_error" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_syntax_error" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_type_error" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
	"duk_is_uri_error" => ["duk_bool_t", "duk_context *ctx, duk_idx_t index"],
}

IGNORES = %w(
	DUK_API_NORETURN
	duk_dump_context_filehandle
)

IMPLEMENTED_IN_WRAPPER = %w(
	duk_error
	duk_push_error_object
)

DEFINES = {
	"DUK_GIT_COMMIT" => "const char*",
	"DUK_GIT_DESCRIBE" => "const char*",
	"DUK_GIT_BRANCH" => "const char*",
	"DUK_DATE_MSEC_100M_DAYS" => "const double"
}

target_include =<<EOF
#import "../duktape.h"

EOF

target_source =<<EOF
#include "include/CDuktape.h"

EOF

test_source =<<EOF
import XCTest
@testable import Duktape

class CompletenessTests: XCTestCase {
  func testAllMacros() {
EOF

def handle_macro(name, params, value, target_include, target_source, test_source)
	return if IGNORES.include?(name)

	if value.match(/\/*/) && !value.match(/\*\//)
		value = value.gsub(/\/\*.*/, '')
	end

	# Special cases
	if IMPLEMENTED_IN_WRAPPER.include?(name)
		# Do nothing
	elsif params.nil?
		type = DEFINES[name]
		type = "const int" if not type
		target_include << "#undef #{name}\n"
		target_include << "extern " << type << " " << name << ";\n\n"
		target_source << type << " " << name << " = " << value << ";\n\n"
	# Macros
	elsif macro = MACROS[name]
		target_include << "#undef #{name}\n"
		target_include << macro[0] << " " << name << "(" << (macro[1] || "") << ");\n"

		target_source << macro[0] << " " << name << "(" << (macro[1] || "") << ") {\n"
		if macro[0] != "void"
			target_source << "return ";
		end
		target_source << value << ";\n"
		target_source << "}\n\n"
	end
	test_source << "_ = #{name}\n"
end

current_macro_name = nil
current_macro_params = nil
current_macro_value = nil
File.open(SOURCE_INCLUDE_FILE).each do |line|
	if line.match(/DUK_DBLUNION_H_INCLUDED/)
		target_include << "#endif"
		target_source << "#endif"
		break
	end
	if line.match(/^#(if|undef|elif|endif|else|define\s+[^\s]+\s*$)/)
		line = line
		target_include << line.gsub(/INCLUDED$/, "INCLUDED_")
		target_source << line.gsub(/INCLUDED$/, "INCLUDED__")
		next
	end
	# print(line) if line.match(/^#/)
	if not current_macro_name.nil?
		current_macro_value << " " + line.gsub(/\\\s*$/, "")
		if not line.match(/\\\s*$/)
			handle_macro(current_macro_name, current_macro_params, current_macro_value, target_include, target_source, test_source)
			current_macro_name = nil
		end
	else
		if x = line.match(/#define\s+([^\(\s]+)\s+(.*)/)
			current_macro_name = x[1]
			current_macro_params = nil
			current_macro_value = x[2].gsub(/\\\s*$/, "")
			if not line.match(/\\\s+$/)
				handle_macro(current_macro_name, current_macro_params, current_macro_value, target_include, target_source, test_source)
				current_macro_name = nil
			end
		elsif x = line.match(/#define\s+([^\(\s]+)(\([^\)]*\))\s+(.*)/)
			current_macro_name = x[1]
			current_macro_params = x[2]
			current_macro_value = x[3].gsub(/\\\s*$/, "")
			if not line.match(/\\\s*$/)
				handle_macro(current_macro_name, current_macro_params, current_macro_value, target_include, target_source, test_source)
				current_macro_name = nil
			end
		end
	end
end


test_source +=<<EOF
  }

  static var allTests : [(String, (CompletenessTests) -> () throws -> Void)] {
    return [
      ("testAllMacros", testAllMacros),
    ]
  }
}
EOF

File.open(TARGET_INCLUDE_FILE, "w") { |f| f.write(target_include) }
File.open(TARGET_SOURCE_FILE, "w") { |f| f.write(target_source) }
File.open(TEST_SOURCE_FILE, "w") { |f| f.write(test_source) }
