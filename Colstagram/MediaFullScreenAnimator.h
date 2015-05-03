//
//  MediaFullScreenAnimator.h
//  Colstagram
//
//  Created by Colin M. Roth on 5/3/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface MediaFullScreenAnimator : NSObject <UIViewControllerAnimatedTransitioning>

@property (nonatomic, assign) BOOL presenting;
@property (nonatomic, weak) UIImageView *cellImageView;

//- (IBAction)tellFriend:(id)sender;

@end
