import XCTest
@testable import CDuktape

class CDuktapeTests: XCTestCase {
  func testExample() {
        let ctx = duk_create_heap(nil, nil, nil, nil, nil);
        duk_eval_string(ctx, "'foo' + 'bar'");
        let result = String(validatingUTF8:duk_to_string(ctx, -1)!)!
        duk_pop(ctx);
        duk_destroy_heap(ctx);
        XCTAssertEqual(result, "foobar")
  }


  static var allTests : [(String, (CDuktapeTests) -> () throws -> Void)] {
    return [
      ("testExample", testExample),
    ]
  }
}
