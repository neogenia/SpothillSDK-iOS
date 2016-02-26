//
//  Campaign.h
//  Spothill
//
//  Created by Martin Krivus on 18/08/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpothillSDKIgnoreableEntity.h"


@class SpothillSDKProvider;
@class SpothillSDKCategory;


typedef enum {
    SpothillSDKCampaignEventTypeEnter,
    SpothillSDKCampaignEventTypeExit,
    SpothillSDKCampaignEventTypeStay,
} SpothillSDKCampaignEventType;

@interface SpothillSDKCampaign : SpothillSDKIgnoreableEntity

@property (strong, nonatomic, readonly) NSNumber *type;
@property (strong, nonatomic, readonly) NSString *image;
@property (strong, nonatomic, readonly) NSString *title;
@property (strong, nonatomic, readonly) NSString *desc;
@property (strong, nonatomic, readonly) NSNumber *campaignId;
@property (strong, nonatomic, readonly) NSNumber *providerId;
@property (strong, nonatomic, readonly) NSNumber *categoryId;
@property (strong, nonatomic, readonly) NSNumber *remaining;
@property (strong, nonatomic, readonly) NSDate *dateTo;
@property (strong, nonatomic, readonly) NSDate *favourite;
@property (strong, nonatomic, readonly) NSDate *reminder;
@property (strong, nonatomic, readonly) NSNumber *delay;
@property (strong, nonatomic, readonly) NSNumber *showDistance;

@property (strong, nonatomic, readonly) NSNumber *event;
@property (assign, nonatomic, readonly) SpothillSDKCampaignEventType eventType;

@property (strong, nonatomic, readonly) NSDate *shown;
@property (strong, nonatomic, readonly) NSString *notificationTitle;
@property (strong, nonatomic, readonly) SpothillSDKProvider *provider;
@property (strong, nonatomic, readonly) SpothillSDKCategory *category;

@property (strong, nonatomic, readonly) UILocalNotification *notificationForCampaign;

- (BOOL)isIgnored;

- (NSURL *)imageURL;
- (UIImage *)labelHalfImageForType;
- (NSString *)shareText;

- (void)toggleReminderWithCompletion:(void (^)(BOOL success))completion;
- (void)toggleFavouriteWithCompletion:(void (^)(BOOL success))completion;

@end


