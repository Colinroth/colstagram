//
//  MediaTableViewCell.h
//  Colstagram
//
//  Created by Colin M. Roth on 4/21/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>


@class Media, MediaTableViewCell;

@protocol MediaTableViewCellDelgate <NSObject>

-(void) cell:(MediaTableViewCell *)cell didTapImageView: (UIImageView *)imageView;
-(void) cell:(MediaTableViewCell *)cell didLongPressImageView:(UIImageView *)imageView;
-(void) cellDidPressLikeButton: (MediaTableViewCell *)cell;

@end

@interface MediaTableViewCell : UITableViewCell
@property (nonatomic, strong) Media *mediaItem;
@property (nonatomic, weak) id <MediaTableViewCellDelgate> delegate;

+ (CGFloat) heightForMediaItem:(Media *)mediaItem width:(CGFloat)width;

@end

