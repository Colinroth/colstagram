//
//  CameraViewController.h
//  Colstagram
//
//  Created by Colin M. Roth on 6/28/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CameraViewController;

@protocol CameraViewControllerDelegate <NSObject>

-(void) cameraViewController:(CameraViewController *)cameraViewController didCompleteWithImage:(UIImage *) image;

@end

@interface CameraViewController : UIViewController

@property (nonatomic, weak) NSObject <CameraViewControllerDelegate> *delegate;

@end
