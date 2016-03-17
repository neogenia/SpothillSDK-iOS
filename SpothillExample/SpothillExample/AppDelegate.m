//
//  AppDelegate.m
//  SpothillExample
//
//  Created by Martin Krivus on 09/02/16.
//  Copyright © 2016 Martin Krivus. All rights reserved.
//

#import "AppDelegate.h"


#import <SpothillSDK/SpothillSDK.h>


@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // app specific value provided by Neogenia s.r.o.
    SpothillSDKManager.sharedInstance.backend.providerHash = @"your provider hash";
    
    // change this value to production for release applications
    SpothillSDKManager.sharedInstance.backend.environment = SpothillSDKBackendEnvironmentBeta;
    
    if (!SpothillSDKManager.sharedInstance.backend.isLoggedIn) {
        [SpothillSDKManager.sharedInstance.backend registerAnonymousUserWithCompletion:^(BOOL success, NSInteger statusCode) {
            if (success) {
                // api can be used now
            } else {
                // you have to try again
            }
        }];
    }
    
    if (launchOptions[UIApplicationLaunchOptionsLocalNotificationKey]) {
        [self application:application didReceiveLocalNotification:launchOptions[UIApplicationLaunchOptionsLocalNotificationKey]];
    }
    
    [self registerForUserNotifications];
    
    return YES;
}

- (void)registerForUserNotifications {
    // this is for ios8+, ios7 allows local notifications without asking for permissions
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeSound categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
    }
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    [SpothillSDKManager.sharedInstance didReceiveLocalNotification:notification];
}

@end
