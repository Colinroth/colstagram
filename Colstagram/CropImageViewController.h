//
//  CropImageViewController.h
//  Colstagram
//
//  Created by Colin M. Roth on 6/30/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//


#import "MediaFullScreenViewController.h"

@class CropImageViewController;

@protocol CropImageViewControllerDelegate <NSObject>

-(void) cropControllerFinishedWithImage: (UIImage *) croppedImage;

@end

@interface CropImageViewController : MediaFullScreenViewController

-(instancetype) initWithImage: (UIImage *) sourceImage;

@property (nonatomic, weak) NSObject <CropImageViewControllerDelegate> *delegate;

@end
