//
//  ImageLibraryViewController.h
//  Colstagram
//
//  Created by Colin M. Roth on 7/1/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ImageLibraryViewController;

@protocol ImageLibraryViewControllerDelegate <NSObject>

-(void) imageLibraryViewController:(ImageLibraryViewController *) imageLibraryViewController didCompleteWithImage:(UIImage *)image;

@end

@interface ImageLibraryViewController : UICollectionViewController

@property (nonatomic, weak) NSObject <ImageLibraryViewControllerDelegate> *delegate;

@end
