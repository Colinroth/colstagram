//
//  DataSource.h
//  Colstagram
//
//  Created by Colin M. Roth on 4/20/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Media;

typedef void (^NewItemCompletionBlock)(NSError *error);

@interface DataSource : NSObject

+(instancetype) sharedInstance;
@property (nonatomic, strong, readonly) NSArray *mediaItems;

- (void) deleteMediaItem:(Media *)item;

-(void) requestNewItemsWithCompletionHandler:(NewItemCompletionBlock)completionHandler;
-(void) requestOldItemswithCompletitonHandler: (NewItemCompletionBlock)completionHandler;

@end
