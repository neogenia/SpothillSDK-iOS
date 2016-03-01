//
//  SpothillDB.h
//  Spothill
//
//  Created by Martin Krivus on 02/11/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SpothillSDKCampaignListTypes.h"


// notifications

// when ignored property of SpothillSDKIgnoreableEntity subclasses changes
extern NSString * const cSpothillSDKEntityIgnoredChanged;
// when reminder property of SpothillSDKCampaign class changes
extern NSString * const cSpothillSDKBackendReminderChanged;
// when favourite property of SpothillSDKCampaign class changes
extern NSString * const cSpothillSDKBackendFavouriteChanged;
// after all users data is wiped out
extern NSString * const cSpothillSDKBackendUserDidLogout;
// after user logged in
extern NSString * const cSpothillSDKBackendUserDidLogin;

// when new unknown beacon is ranged and campaigns will load from server
extern NSString * const cSpothillSDKNewNearbyCampaingsWillLoad;
// when new nearby campaigns are loaded and might be used from cache
extern NSString * const cSpothillSDKNewNearbyCampaingsDidLoad;

// did enter beacon region
extern NSString *const cSpothillSDKDidEnterBeaconRegionNotification;
// did exit from range of spothill beacons
extern NSString *const cSpothillSDKDidExitBeaconRegionNotification;


// SDK found new beacon, that is not stored in database
extern NSString * const cSpothillSDKNewBeaconFoundNotification;
// userInfo key for CLBeacon instance within cSpothillSDKNewBeaconFoundNotification
extern NSString * const cSpothillSDKNewBeaconUserInfoKey;

// when nearbyBeacons property of SpothillSDKBeaconManager changes
extern NSString * const cSpothillSDKNearbyBeaconsUpdatedNotification;


// when user taps on a local notification and the SDK decides the app should display detail of campaign itself
extern NSString * const cSpothillSDKNotificationCampaignDetailShouldOpen;
// used as a userInfo key within cSpothillSDKNotificationCampaignDetailShouldOpen notification
extern NSString * const cSpothillSDKNotificationCampaignIdKeyName;



@class SpothillSDKCache;
@class SpothillSDKBeaconManager;
@class SpothillSDKBackend;

@interface SpothillSDKManager : NSObject

// stores data from server that don't need to be reloaded
@property (strong, nonatomic, readonly) SpothillSDKCache *cache;
// service that listens to nearby ibeacons and allows testing of beacon ranging in simulator
@property (strong, nonatomic, readonly) SpothillSDKBeaconManager *beaconManager;
// connection to spothill backend
@property (strong, nonatomic, readonly) SpothillSDKBackend *backend;

+ (instancetype)sharedInstance;

// app should resend any local notification that is received, so SDK can decide if it should open detail of campaign
- (void)didReceiveLocalNotification:(UILocalNotification *)notification;


@end
