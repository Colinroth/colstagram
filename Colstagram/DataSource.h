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

extern NSString *const ImageFinishedNotification;

+(instancetype) sharedInstance;
@property (nonatomic, strong, readonly) NSArray *mediaItems;
@property (nonatomic, strong, readonly) NSString *accessToken;

- (void) deleteMediaItem:(Media *)item;

-(void) requestNewItemsWithCompletionHandler:(NewItemCompletionBlock)completionHandler;
-(void) requestOldItemswithCompletitonHandler: (NewItemCompletionBlock)completionHandler;

-(void) downloadImageForMediaItem: (Media *)mediaItem;

-(void) toggleLikeOnMediaItem:(Media *)mediaItem;
-(void) commentOnMediaItem: (Media *)mediaItem withCommentText:(NSString *)commentText;

+(NSString *) instagramClientID;

@end
