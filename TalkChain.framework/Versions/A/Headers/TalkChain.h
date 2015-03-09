//
//  TalkChain.h
//  TalkChain
//
//  Created by Charles Chase on 8/30/14.
//  Copyright (c) 2014 AFTY, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TalkChainCredentials.h"

@protocol TalkChainDelegate <NSObject>

@optional

- (void)talkChainIsReady;
- (void)talkChainSessionStarted;
- (void)talkChainError:(NSString*)error;
- (void)talkChainViewStateChanged:(BOOL)visible;
- (void)talkChainReceivedNotification:(NSInteger)badge;
- (void)talkChainCredentialsUpdated:(TalkChainCredentials*)credentials;

@end

@interface TalkChain : NSObject

@property (nonatomic, strong) id<TalkChainDelegate> delegate;
@property (nonatomic, strong) NSString *APNSToken;
@property (nonatomic, strong) TalkChainCredentials *credentials;
@property (nonatomic, strong) UIViewController *rootViewController;

/*  Singleton */

+ (id)sharedManager;


/*
    Initialize TalkChain
 
    @param key - API key provided by Affinity Networks
    @param delegate - Optional delegate
*/

- (void)initWithAPIKey:(NSString*)key delegate:(id<TalkChainDelegate>)delegate;


/*  Start a TalkChain session, create a user account (for first-time users) and listen for notifications. */

- (void)startSession;


/*  Open the TalkChain UI */

- (void)presentUI;


/*
    Open the TalkChain UI from a specific root view controller.
 
    We recommend using to top most root controller, as the UI
    has a built-in UINavigationController and UITabBarController.
 
    If unsure how to use, call presentUI instead.
*/

- (void)presentUIFromRootViewController:(UIViewController*)rootViewController;


/*
    Stop TalkChain and close the UI
 
    We recommend calling this only on memory warnings. Otherwise, allow the
    user to close the UI using normal navigation.
*/

- (void)stop;


/*
    Customize App Colors

    @param primary - Launch screen background and assorted controls
    @param secondary - Used throughout as a bold text color
    @param highlight - UITableViewCell selected color
    @param accent - Assorted accents, Karma score background and UISwitch tint color
    @param header - Navigation header color
*/

+ (void)configureColorsWithPrimary:(UIColor*)primary
              secondary:(UIColor*)secondary
              highlight:(UIColor*)highlight
                 accent:(UIColor*)accent
                 header:(UIColor*)header;


/*  Allow Guest Accounts - Default NO */

+ (void)allowGuestAccounts:(BOOL)allow;

@end
