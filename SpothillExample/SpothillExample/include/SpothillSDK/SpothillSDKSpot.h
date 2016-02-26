//
//  Spot.h
//  Spothill
//
//  Created by Martin Krivus on 09/06/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpothillSDKServerEntity.h"

@class CLBeacon;
@class SpothillSDKSpotNotification;

@interface SpothillSDKSpot : SpothillSDKServerEntity

@property (strong, nonatomic, readonly) CLBeacon *beacon;

@property (strong, nonatomic, readonly) NSMutableArray    *groupCampaigns;
@property (strong, nonatomic, readonly) NSMutableArray    *campaigns;
@property (strong, nonatomic, readonly) SpothillSDKSpotNotification  *spotNotification;
@property (assign, nonatomic, readonly) NSTimeInterval    ignore;

@end
