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
- (void)talkChainReceivedNotification:(NSDictionary*)notification view:(UIView*)view;

@end

@interface TalkChain : NSObject

@property (nonatomic, strong) id<TalkChainDelegate> delegate;

/** 
    Launch the TalkChain UI
 
    @param key - App key provided at signup.
    @param delegate - Delegate to receive callbacks.
*/

+ (id)launchWithAPIKey:(NSString*)key delegate:(id<TalkChainDelegate>)delegate;

/**
    The recommended UX is to let the user manually close TalkChain via the built-in close button,
    which ends the session, closes the UI and triggers talkChainSessionEnded. TalkChain will maintain 
    a live connection to listen for and relay notifications, such as Direct Messages to the delegate.
 
    Stop will manually close the TalkChain UI (if presented) and stop all listeners.
 
    We recommend calling this only on application:didReceiveMemoryWarning.
*/

+ (void)stop;

@end
