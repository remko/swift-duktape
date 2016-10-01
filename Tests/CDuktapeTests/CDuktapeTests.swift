import XCTest
@testable import CDuktape

class CDuktapeTests: XCTestCase {
  func testEvalString() {
    let ctx = duk_create_heap(nil, nil, nil, nil, nil)
    duk_eval_string(ctx, "'foo' + 'bar'")
    let result = String(validatingUTF8:duk_to_string(ctx, -1)!)!
    duk_pop(ctx)
    duk_destroy_heap(ctx)
    XCTAssertEqual(result, "foobar")
  }

  func testEvalString2() {
    let ctx = duk_create_heap_default()
    defer { duk_destroy_heap(ctx) }
    duk_eval_string(ctx, "5 + 6")
    let result = String(validatingUTF8:duk_to_string(ctx, -1)!)!
    duk_pop(ctx)
    XCTAssertEqual(result, "11")
  }

  func testSafeCall() {
    let ctx = duk_create_heap(nil, nil, nil, nil, nil);
    let ret = duk_safe_call(ctx, { (_ ctx: OpaquePointer?) -> duk_ret_t in
      duk_eval_string(ctx, "'foo' + 'bar'")
      return 1
    }, 0, 1);
    let result = String(validatingUTF8:duk_to_string(ctx, -1)!)!
    duk_pop(ctx);
    duk_destroy_heap(ctx);
    XCTAssertEqual(ret, DUK_EXEC_SUCCESS)
    XCTAssertEqual(result, "foobar")
  }

  func testSafeCall_Fail() {
    let ctx = duk_create_heap(nil, nil, nil, nil, nil);
    let ret = duk_safe_call(ctx, { (_ ctx: OpaquePointer?) -> duk_ret_t in
      duk_eval_string(ctx, "function f() { throw 'My Error'; } f()")
      return 1
    }, 0, 1);
    let result = String(validatingUTF8:duk_to_string(ctx, -1)!)!
    duk_pop(ctx);
    duk_destroy_heap(ctx);
    XCTAssertEqual(ret, DUK_EXEC_ERROR)
    XCTAssertEqual(result, "My Error")
  }


  static var allTests : [(String, (CDuktapeTests) -> () throws -> Void)] {
    return [
      ("testEvalString", testEvalString),
      ("testSafeCall", testSafeCall),
      ("testSafeCall_Fail", testSafeCall_Fail),
    ]
  }
}
