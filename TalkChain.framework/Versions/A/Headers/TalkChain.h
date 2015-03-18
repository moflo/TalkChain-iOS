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


/* 
    Get Discussion Details
 
    @param uniqueId - Your unique identifier (the same one you used for openDiscussion.)
*/

- (void)getDiscussion:(NSString*)uniqueId success:(void (^)(NSDictionary *discussion))success failure:(void (^)(NSString *error))failure;


/*
    Open a Discussion
 
    @param uniqueId - The local unique identifier, such as the id of an article, game or song
    @param name - The discussion name
    @param contentSummary - Optional content summary
    @param contentURL - Optional external content link
    @param imageURL - Optional image resource, used as the discussion background

    If the discussion exists, we'll open it. Otherwise we'll create a new one.
 
    Providing an imageURL is not required but considered polite.
*/

- (void)openDiscussion:(NSString *)uniqueId name:(NSString*)name contentSummary:(NSString*)contentSummary contentURL:(NSString*)contentURL imageURL:(NSString*)imageURL;

@end
