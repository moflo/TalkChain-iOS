//
//  TalkChain.h
//  TalkChain
//
//  Created by Charles Chase on 8/30/14.
//  Copyright (c) 2014 AFTY, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol TalkChainDelegate <NSObject>

@optional

- (void)talkChainSessionEnded;

@end

@interface TalkChain : NSObject

@property (nonatomic, strong) id<TalkChainDelegate> delegate;

+ (id)launchWithAPIKey:(NSString*)key delegate:(id<TalkChainDelegate>)delegate;

@end
