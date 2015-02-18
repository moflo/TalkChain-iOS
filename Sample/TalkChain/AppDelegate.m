//
//  AppDelegate.m
//  TalkChain
//
//  Created by Charles Chase on 2/17/15.
//  Copyright (c) 2015 AFTY, LLC. All rights reserved.
//

#import "AppDelegate.h"

#warning THIS KEY IS FOR TESTING ONLY

#define kApiKey @"543db9aa14aa8ec9020000b4"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [[TalkChain sharedManager] initWithAPIKey:kApiKey delegate:self];
    
    return YES;
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    [[TalkChain sharedManager] startSession];
}


#pragma mark - TalkChain Delegate

- (void)talkChainIsReady
{
    NSLog(@"TALKCHAIN [info] Ready");
}

- (void)talkChainSessionStarted
{
    NSLog(@"TALKCHAIN [info] Session Started");
}

- (void)talkChainReceivedNotification:(NSInteger)badge
{
    NSLog(@"TALKCHAIN [info] Notification Received : %ld", (long)badge);
}

- (void)talkChainCredentialsUpdated:(TalkChainCredentials *)credentials
{
    NSLog(@"TALKCHAIN [info] Credentials Updated: %@",credentials);
}

- (void)talkChainViewStateChanged:(BOOL)visible
{
    NSLog(@"TALKCHAIN [info] UI is %@", visible ? @"Visible" : @"Hidden");
}

- (void)talkChainError:(NSString *)error
{
    NSLog(@"%@",error);
}

@end
