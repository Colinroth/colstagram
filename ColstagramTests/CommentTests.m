//
//  CommentTests.m
//  Colstagram
//
//  Created by Colin M. Roth on 7/5/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XCTest/XCTest.h>
#import "Comment.h"

@interface CommentTests : XCTestCase

@end

@implementation CommentTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

-(void)testThatInitializationWorks {
    NSDictionary *sourceDictionary = @{@"id": @"8675309",
                                       @"text" : @"Sample Comment"};
    
    Comment *testComment = [[Comment alloc] initWithDictionary:sourceDictionary];
    
    XCTAssertEqualObjects(testComment.idNumber, sourceDictionary[@"id"], @"The ID number should be equal");
    XCTAssertEqualObjects(testComment.text, sourceDictionary[@"text"], @"The text should be equal");
}

@end
