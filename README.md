# swift-duktape: Duktape bindings for Swift

Call and embed JavaScript in Swift using the [Duktape](http://duktape.org)
JavaScript engine. Works on macOs and Linux.

To see it in action, have a look at [this Universal React+Swift app](https://el-tramo.be/react-swift-example/).

Currently, only a low-level binding is provided. These bindings are a
direct mapping of the complete [Duktape API](http://duktape.org/api.html). A more idiomatic
API may be implemented later.

## Usage

Put this package as a dependency in your `Package.swift`:
    
      dependencies: [
        .Package(url: "https://github.com/remko/swift-duktape.git", majorVersion: 0, minor: 2)
      ],
    
and import it in the source files where you want to use it:

    import Duktape
    

## Examples

### Simple Evaluation

    import Duktape

    let ctx = duk_create_heap_default()
    defer { duk_destroy_heap(ctx) }

    duk_eval_string(ctx, "5 + 6")

    let result = String(validatingUTF8:duk_safe_to_string(ctx, -1)!)!
    print(result) // Prints '11'
    duk_pop(ctx)

### Safe Evaluation

    let ctx = duk_create_heap_default()
    defer { duk_destroy_heap(ctx) }

    // You can use a closure instead of a callback
    let ret = duk_safe_call(ctx, { ctx in
      duk_eval_string(ctx, "myFunctionCall()")
      return 1
    }, 0, 1);
    let result = String(validatingUTF8:duk_safe_to_string(ctx, -1)!)!
    if ret == DUK_EXEC_SUCCESS {
        print("Success: \(result)")
    }
    else {
        print("Error: \(result)")
    }

    duk_pop(ctx);

