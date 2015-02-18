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

- (IBAction)launchTalkChain:(id)sender {
    
    [[TalkChain sharedManager] presentUI];
}

@end
