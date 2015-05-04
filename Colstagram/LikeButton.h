//
//  LikeButton.h
//  Colstagram
//
//  Created by Colin M. Roth on 5/4/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, LikeState) {
    LikeStateNotLiked = 0,
    LikeStateLiking =  1,
    LikeStateLiked = 2,
    likeStateUnliking = 3
};

@interface LikeButton : UIButton

@property (nonatomic, assign) LikeState likeButtonState;

@end
