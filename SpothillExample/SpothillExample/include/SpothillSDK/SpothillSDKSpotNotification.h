//
//  SpotNotification.h
//  Spothill
//
//  Created by Martin Krivus on 18/08/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpothillSDKServerEntity.h"

@interface SpothillSDKSpotNotification : SpothillSDKServerEntity

@property (strong, nonatomic, readonly) NSString *title;
@property (strong, nonatomic, readonly) NSNumber *notificationId;

@end
