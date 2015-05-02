//
//  DataSource.h
//  Colstagram
//
//  Created by Colin M. Roth on 4/20/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Media;

@interface DataSource : NSObject

+(instancetype) sharedInstance;
@property (nonatomic, strong, readonly) NSArray *mediaItems;

- (void) deleteMediaItem:(Media *)item;

@end
