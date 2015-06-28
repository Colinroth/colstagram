//
//  ComposeCommentView.h
//  Colstagram
//
//  Created by Colin M. Roth on 6/28/15.
//  Copyright (c) 2015 iamcolinroth. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ComposeCommentView;

@protocol ComposeCommentViewDelegate <NSObject>

-(void) commentViewDidPressButton: (ComposeCommentView *) sender;
-(void) commentView: (ComposeCommentView *) sender textDidChange: (NSString *)text;
-(void) commentViewWillStartEditing:(ComposeCommentView *) sender;

@end

@interface ComposeCommentView : UIView

@property (nonatomic, weak) NSObject <ComposeCommentViewDelegate> *delegate;
@property (nonatomic, assign) BOOL isWritingComment;
@property (nonatomic, strong) NSString *text;

-(void) stopComposingComment;

@end
