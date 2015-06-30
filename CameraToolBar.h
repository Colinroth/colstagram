//
//  CameraToolBar.h
//  Colstagram
//
//  Created by Colin M. Roth on 6/28/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CameraToolBar;

@protocol CameraToolbarDelegate <NSObject>

-(void) leftButtonPressedOnToolbar: (CameraToolBar *)toolbar;
-(void) rightButtonPressedOnToolbar: (CameraToolBar *)toolbar;
-(void) cameraButtonPressedOnToolbar: (CameraToolBar *)toolbar;

@end

@interface CameraToolBar : UIView

-(instancetype) initWithImageNames:(NSArray *)imageNames;

@property (nonatomic, weak) NSObject <CameraToolbarDelegate> *delegate;

@end
