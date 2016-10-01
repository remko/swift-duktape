#!/usr/bin/env ruby

SOURCE_INCLUDE_FILE=ARGV[0]
TARGET_INCLUDE_FILE=ARGV[1]
TARGET_SOURCE_FILE=ARGV[2]

MACROS = {
 "duk_eval_file_noresult" => ["void", "duk_context *ctx, const char *path"],
 "duk_eval_string" => ["void", "duk_context *ctx, const char *src"],
 "duk_safe_to_string" => ["const char*", "duk_context *ctx, duk_idx_t index"],
 "duk_create_heap_default" => ["duk_context*"],
}

target_include =<<EOF
#import "../duktape.h"

EOF

target_source =<<EOF
#include "include/CDuktape.h"

EOF

def handle_macro(name, params, value, target_include, target_source)
	macro = MACROS[name]
	if macro
		target_include << "#undef #{name}\n"
		target_include << macro[0] << " " << name << "(" << (macro[1] || "") << ");\n"

		target_source << macro[0] << " " << name << "(" << (macro[1] || "") << ") {\n"
		if macro[0] != "void"
			target_source << "return ";
		end
		target_source << value << ";\n"
		target_source << "}\n\n"
	end
end

current_macro_name = nil
current_macro_params = nil
current_macro_value = nil
File.open(SOURCE_INCLUDE_FILE).each do |line|
	if not current_macro_name.nil?
		current_macro_value << " " + line.gsub(/\\\s*$/, "")
		if not line.match(/\\\s*$/)
			handle_macro(current_macro_name, current_macro_params, current_macro_value, target_include, target_source)
			current_macro_name = nil
		end
	else
		if x = line.match(/#define\s+([^\(\s]+)\s+(.*)/)
			current_macro_name = x[1]
			current_macro_params = nil
			current_macro_value = x[2].gsub(/\\\s*$/, "")
			if not line.match(/\\\s+$/)
				handle_macro(current_macro_name, current_macro_params, current_macro_value, target_include, target_source)
				current_macro_name = nil
			end
		elsif x = line.match(/#define\s+([^\(\s]+)(\([^\)]*\))\s+(.*)/)
			current_macro_name = x[1]
			current_macro_params = x[2]
			current_macro_value = x[3].gsub(/\\\s*$/, "")
			if not line.match(/\\\s*$/)
				handle_macro(current_macro_name, current_macro_params, current_macro_value, target_include, target_source)
				current_macro_name = nil
			end
		end
	end
end

File.open(TARGET_INCLUDE_FILE, "w") { |f| f.write(target_include) }
File.open(TARGET_SOURCE_FILE, "w") { |f| f.write(target_source) }
