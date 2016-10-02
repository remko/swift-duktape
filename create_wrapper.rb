#!/usr/bin/env ruby

SOURCE_INCLUDE_FILE=ARGV[0]
TARGET_INCLUDE_FILE=ARGV[1]
TARGET_SOURCE_FILE=ARGV[2]
TEST_SOURCE_FILE=ARGV[3]

MACROS = {
	"duk_eval_file_noresult" => ["void", "duk_context *ctx, const char *path"],
	"duk_eval_string" => ["void", "duk_context *ctx, const char *src"],
	"duk_safe_to_string" => ["const char*", "duk_context *ctx, duk_idx_t index"],
	"duk_create_heap_default" => ["duk_context*"],
	"duk_error_va" => ["void", "duk_context *ctx, duk_errcode_t err_code, const char *fmt, va_list ap"],
	"duk_xmove_top" => ["void", "duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count"],
	"duk_xcopy_top" => ["void", "duk_context *to_ctx, duk_context *from_ctx, duk_idx_t count"],
	"duk_dump_context_stdout" => ["void", "duk_context *ctx"],
	"duk_dump_context_stderr" => ["void", "duk_context *ctx"],
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
@testable import CDuktape

class CompletenessTests: XCTestCase {
  func testAllMacros() {
EOF

def handle_macro(name, params, value, target_include, target_source, test_source)
	return if IGNORES.include?(name)
	if value.match(/\/*/) && !value.match(/\*\//)
		value = value.gsub(/\/\*.*/, '')
	end

	# Special cases
	if params.nil?
		type = DEFINES[name]
		type = "const int" if not type
		target_include << "#undef #{name}\n"
		target_include << "extern " << type << " " << name << ";\n\n"
		target_source << type << " " << name << " = " << value << ";\n\n"
		test_source << "_ = #{name}\n"
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
		test_source << "_ = #{name}\n"
	else
		puts("MISSING MACRO #{name}")
	end
	# test_source << "_ = #{name}\n"
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
