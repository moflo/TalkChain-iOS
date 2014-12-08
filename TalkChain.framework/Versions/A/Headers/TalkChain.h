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

/*
    Launch the TalkChain UI
 
    @param key - App key provided at signup.
    @param token - Apple push notification token.
    @param delegate - Delegate to receive callbacks.
*/

+ (id)launchWithAPIKey:(NSString*)key token:(NSString*)token delegate:(id<TalkChainDelegate>)delegate;

/*
    Stop TalkChain
 
    The recommended UX is to let the user manually close TalkChain via the built-in close button,
    which ends the session, closes the UI and triggers talkChainSessionEnded. TalkChain will maintain 
    a live connection to listen for and relay notifications, such as Direct Messages to the delegate.
 
    Stop will manually close the TalkChain UI (if presented) and stop all listeners.
 
    We recommend calling this only on application:didReceiveMemoryWarning.
*/

+ (void)stop;

/*
    Customize App Colors
 
    @param primary - Launch screen background, navigation header, and refresh AI color (should closely match your custom header image.)
    @param secondary - Header text color.
    @param highlight - UITableViewCell selected color.
    @param accent - Assorted accents, Karma score background and UISwitch tint color.
    @param border - UITextField and UITextView border color.
 
 */

+ (void)configureColorsWithPrimary:(UIColor*)primary
              secondary:(UIColor*)secondary
              highlight:(UIColor*)highlight
                 accent:(UIColor*)accent
                 border:(UIColor*)border;


@end
