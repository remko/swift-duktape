@_exported import CDuktape

func duk_error(_ ctx: OpaquePointer!, _ code: duk_errcode_t, _ fmt: String, _ args: CVarArg...)  {
	withVaList(args) { va_list in
		duk_error_va(ctx, code, fmt, va_list)
	}
}

func duk_push_error_object(_ ctx: OpaquePointer!, _ code: duk_errcode_t, _ fmt: String, _ args: CVarArg...) -> duk_idx_t {
	return withVaList(args) { va_list in
		return duk_push_error_object_va(ctx, code, fmt, va_list)
	}
}
