//
//  UIImage+ImageUtilities.h
//  Colstagram
//
//  Created by Colin M. Roth on 6/29/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (ImageUtilities)

-(UIImage *) imageWithFixedOrientation;
-(UIImage *) imageResizedToMatchAspectRatioOfSize:(CGSize)size;
-(UIImage *) imageCroppedtoRect:(CGRect)cropRect;

@end
