import XCTest
@testable import DuktapeTests

XCTMain([
	testCase(APITests.allTests),
	testCase(CompletenessTests.allTests)
])
