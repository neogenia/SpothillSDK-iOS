//
//  SpothillSDKEntitySetters.h
//  Spothill
//
//  Created by Martin Krivus on 19/12/15.
//  Copyright © 2015 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SpothillSDKEntities.h"


@interface SpothillSDKSpot (Setters)
@property (strong, nonatomic) CLBeacon *beacon;
@property (strong, nonatomic) NSMutableArray    *groupCampaigns;
@property (strong, nonatomic) NSMutableArray    *campaigns;
@property (strong, nonatomic) SpothillSDKSpotNotification  *spotNotification;
@property (assign, nonatomic) NSTimeInterval    ignore;
@end


@interface SpothillSDKProvider (Setters)
@property (strong, nonatomic) NSNumber *providerId;
@property (strong, nonatomic) NSString *title;
@end


@interface SpothillSDKIgnoreableEntity (Setters)
@property (strong, nonatomic) NSDate *ignored;
@end


@interface SpothillSDKCategory (Setters)
@property (strong, nonatomic) NSNumber *categoryId;
@property (strong, nonatomic) NSString *title;
@end


@interface SpothillSDKGroupCampaign (Setters)
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSNumber *campaignId;
@property (nonatomic, assign) BOOL allowDetail;
@end


@interface SpothillSDKCampaign (Setters)
@property (strong, nonatomic) NSNumber *type;
@property (strong, nonatomic) NSString *image;
@property (strong, nonatomic) NSString *title;
@property (strong, nonatomic) NSString *desc;
@property (strong, nonatomic) NSNumber *campaignId;
@property (strong, nonatomic) NSNumber *providerId;
@property (strong, nonatomic) NSNumber *categoryId;
@property (strong, nonatomic) NSNumber *remaining;
@property (strong, nonatomic) NSDate *dateTo;
@property (strong, nonatomic) NSDate *favourite;
@property (strong, nonatomic) NSDate *reminder;
@property (strong, nonatomic) NSNumber *delay;
@property (strong, nonatomic) NSNumber *showDistance;
@property (strong, nonatomic) NSNumber *event;
@property (assign, nonatomic) SpothillSDKCampaignEventType eventType;
@property (strong, nonatomic) NSDate *shown;
@property (strong, nonatomic) NSString *notificationTitle;
@property (strong, nonatomic) SpothillSDKProvider *provider;
@property (strong, nonatomic) SpothillSDKCategory *category;
@property (strong, nonatomic) UILocalNotification *notificationForCampaign;
@end


@interface SpothillSDKSpotNotification (Setters)
@property (strong, nonatomic) NSString *title;
@property (strong, nonatomic) NSNumber *notificationId;
@end


@interface SpothillSDKServerEntity (Setters)
@property (strong, nonatomic) NSMutableDictionary *dataDictionary;
@property (strong, nonatomic) NSDate *downloadDate;
@end
