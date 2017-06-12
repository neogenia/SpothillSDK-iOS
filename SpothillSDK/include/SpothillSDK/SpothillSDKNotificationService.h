//
//  SpothillSDKNotificationService.h
//  Spothill
//
//  Created by Martin Krivus on 07/10/15.
//  Copyright © 2015 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SpothillSDKCampaign.h"

@interface SpothillSDKNotificationService : NSObject

+ (void)scheduleNotificationForCampaign:(SpothillSDKCampaign*)campaign toFireDate:(NSDate *)fireDate;
+ (void)cancelLocalNotificationForCampaign:(SpothillSDKCampaign *)campaign;

@end
