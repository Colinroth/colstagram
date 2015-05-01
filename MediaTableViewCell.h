//
//  MediaTableViewCell.h
//  Colstagram
//
//  Created by Colin M. Roth on 4/21/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Media;
@interface MediaTableViewCell : UITableViewCell
@property (nonatomic, strong) Media *mediaItem;

+ (CGFloat) heightForMediaItem:(Media *)mediaItem width:(CGFloat)width;

@end

