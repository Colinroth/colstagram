//
//  UIImage+ImageUtilities.m
//  Colstagram
//
//  Created by Colin M. Roth on 6/29/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import "UIImage+ImageUtilities.h"

@implementation UIImage (ImageUtilities)

-(UIImage *) imageWithFixedOrientation {
    if (self.imageOrientation == UIImageOrientationUp) return [self copy];
    
    CGAffineTransform transform = CGAffineTransformIdentity;
    
    switch (self.imageOrientation) {
        case UIImageOrientationDown:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width, self.size.height);
            transform = CGAffineTransformRotate(transform, M_PI);
            break;
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width, 0);
            transform = CGAffineTransformRotate(transform, M_PI_2);
            break;
         
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform, 0, self.size.width);
            transform = CGAffineTransformRotate(transform, -M_PI_2);
            break;
        default:
            break;
    }
    
    switch (self.imageOrientation) {
        case UIImageOrientationUpMirrored:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.width, 0);
            transform = CGAffineTransformScale(transform, -1, 1);
            break;
            
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform, self.size.height, 0);
            transform = CGAffineTransformScale(transform, -1, 1);
            break;
        case UIImageOrientationUp:
        case UIImageOrientationDown:
        case UIImageOrientationLeft:
        case UIImageOrientationRight:
            break;
    }
    
    CGFloat scaleFactor = self.scale;
    
    CGContextRef ctx = CGBitmapContextCreate(NULL,
                                             self.size.width * scaleFactor,
                                             self.size.height *scaleFactor,
                                             CGImageGetBitsPerComponent(self.CGImage),
                                             0,
                                             CGImageGetColorSpace(self.CGImage), CGImageGetBitmapInfo(self.CGImage));
    
    CGContextScaleCTM(ctx, scaleFactor, scaleFactor);
    
    CGContextConcatCTM(ctx, transform);
    switch (self.imageOrientation) {
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            CGContextDrawImage(ctx, CGRectMake(0, 0, self.size.height, self.size.width), self.CGImage);
            break;
            
        default:
            CGContextDrawImage(ctx, CGRectMake(0, 0, self.size.width, self.size.height), self.CGImage);
            break;
    }
    
    CGImageRef cgimg = CGBitmapContextCreateImage(ctx);
    UIImage *img = [UIImage imageWithCGImage:cgimg scale:scaleFactor orientation:UIImageOrientationUp];
    CGContextRelease(ctx);
    CGImageRelease(cgimg);
    return img;
}

- (UIImage *) imageResizedToMatchAspectRatioOfSize:(CGSize)size {
    CGFloat horizontalRatio = size.width / self.size.width;
    CGFloat verticalRatio = size.height / self.size.height;
    CGFloat ratio = MAX(horizontalRatio, verticalRatio);
    CGSize newSize = CGSizeMake(self.size.width * ratio * self.scale, self.size.height * ratio * self.scale);
    
    CGRect newRect = CGRectIntegral(CGRectMake(0, 0, newSize.width, newSize.height));
    CGImageRef imageRef = self.CGImage;
    
    CGContextRef ctx = CGBitmapContextCreate(NULL,
                                             newRect.size.width,
                                             newRect.size.height,
                                             CGImageGetBitsPerComponent(self.CGImage), 0, CGImageGetColorSpace(self.CGImage), CGImageGetBitmapInfo(self.CGImage));
    CGContextDrawImage(ctx, newRect, imageRef);
    
    CGImageRef newImageRef = CGBitmapContextCreateImage(ctx);
    UIImage *newImage = [UIImage imageWithCGImage:newImageRef scale:self.scale orientation:UIImageOrientationUp];
    
    
    CGContextRelease(ctx);
    CGImageRelease(newImageRef);
    
    return newImage;
}

-(UIImage *) imageCroppedtoRect:(CGRect)cropRect {
    cropRect.size.width *= self.scale;
    cropRect.size.height *= self.scale;
    cropRect.origin.x *= self.scale;
    cropRect.origin.y *= self.scale;
    
    CGImageRef imageRef = CGImageCreateWithImageInRect(self.CGImage, cropRect);
    UIImage *image = [UIImage imageWithCGImage:imageRef scale:self.scale orientation:self.imageOrientation];
    CGImageRelease(imageRef);
    return image;
}

@end
