//
//  ViewController.m
//  TalkChain
//
//  Created by Charles Chase on 2/17/15.
//  Copyright (c) 2015 AFTY, LLC. All rights reserved.
//

#import "ViewController.h"
#import <TalkChain/TalkChain.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    
    [super didReceiveMemoryWarning];
}

- (IBAction)presentUI:(id)sender {
    
    [[TalkChain sharedManager] presentUI];
}

- (IBAction)presentDiscussion:(id)sender {
    
#warning TO CREATE A NEW DISCUSSION, CHANGE THE UNIQUE_ID
    
    [[TalkChain sharedManager] openDiscussion:@"42074" name:@"TalkChain Discussion" contentSummary:nil contentURL:nil imageURL:nil];
}

- (IBAction)getDiscussion:(id)sender
{
    [[TalkChain sharedManager] getDiscussion:@"42074" success:^(NSDictionary *discussion) {
        
        NSLog(@"%@",discussion);
        
    } failure:^(NSString *error) {
        
        NSLog(@"%@",error);
    }];
}

@end
