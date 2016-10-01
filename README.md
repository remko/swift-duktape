# CDuktape: Low-level Duktape bindings for Swift

Call and embed JavaScript in Swift using the [Duktape](http://duktape.org)
JavaScript engine. Works on macOs and Linux.

To see it in action, have a look at [this Universal React+Swift app](https://el-tramo.be/react-swift-example/).

⚠️ This package currently only contains the functions I need from Duktape, and
is still unfinished: some macros still need to be transformed to proper
functions. If you are interested in using this and missing something, contact
[me](https://el-tramo.be).


## Example

    let ctx = duk_create_heap_default()
    defer { duk_destroy_heap(ctx) }

    duk_eval_string(ctx, "5 + 6")

    let result = String(validatingUTF8:duk_to_string(ctx, -1)!)!
    print(result) // Prints '11'
    duk_pop(ctx)
