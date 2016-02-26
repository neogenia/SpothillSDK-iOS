//
//  SpothillBackend.h
//  Spothill
//
//  Created by Martin Krivus on 08/06/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SpothillSDK.h"

#import "SpothillSDKCampaignListTypes.h"
#import "SpothillSDKEntitySetters.h"
#import "SpothillSDKManager.h"

@import CoreLocation;


// login methods
typedef enum {
    LoginMethodRegister,
    LoginMethodSkipLogin,
    LoginMethodLogin,
    LoginMethodTokenLogin
} LoginMethod;

typedef void (^listCompletionBlock)(NSMutableArray *campaigns, NSMutableArray *providers, NSMutableArray *categories);
typedef void (^campaignListCompletionBlock)(NSMutableArray *campaigns);
typedef void (^categoriesListCompletionBlock)(NSMutableArray *categories);
typedef void (^providersListCompletionBlock)(NSMutableArray *providers);

@interface UpdatedSpot : NSObject

@property (strong, nonatomic) NSNumber *minor;
@property (strong, nonatomic) NSNumber *major;
@property (nonatomic, strong) NSUUID * proximityUUID;
@property (nonatomic, assign) CLLocationAccuracy accuracy;

@end

@interface SpothillSDKBackend : NSObject

// stored after successful login or registration
@property (nonatomic, readonly) NSString * userHash;

// this is value identifing app that uses this SDK, should be provided by Neogenia s.r.o.
@property (strong, nonatomic) NSString * providerHash;

+ (instancetype)sharedInstance;

// returns YES after successful registration
- (BOOL)isLoggedIn;
- (void)logout;

// get spot representation for beacon, spot contains campaigns and groupCampaigns
- (void)getSpotForBeacon:(CLBeacon *)beacon completion:(void (^)(SpothillSDKSpot *spot))completion;
// this is request used in webview that allows to open webpage representing the campaign detail
- (NSMutableURLRequest *)requestCampaignDetailForCampaignId:(NSNumber *)campaignId;

// switch reminder value for campaign
- (void)toggleReminderForCampaign:(SpothillSDKCampaign *)campaign   completion:(void (^)(BOOL success))completion;
// switch favourite value for campaign
- (void)toggleFavouriteForCampaign:(SpothillSDKCampaign *)campaign  completion:(void (^)(BOOL success))completion;
// switch ignore values for different entities
- (void)toggleIgnoreCampaign:(SpothillSDKCampaign *)campaign        completion:(void (^)(BOOL success))completion;
- (void)toggleIgnoreCategory:(SpothillSDKCategory *)category        completion:(void (^)(BOOL success))completion;
- (void)toggleIgnoreProvider:(SpothillSDKProvider *)provider        completion:(void (^)(BOOL success))completion;

// different lists, CampaignListTypeNearbyGroupCampaigns and CampaignListTypeNearbyCampaigns are not supported, they should be loaded from SpothillSDKBackend.sharedInstance.cache
- (void)getListWithId:(SpothillSDKCampaignListType)listId
           completion:(listCompletionBlock)completion;

// registration of user
- (void)registerUserWithData:(NSDictionary *)data
                 loginMethod:(LoginMethod)loginMethod
                  completion:(void (^)(BOOL success, NSInteger statusCode))completion;

// this is for virtual registration of user, so it can be paired with server actions
// and his data - successful completion of this is mandatory before any other backend calls
// this uses LoginMethodSkipLogin register method
- (void)registerAnonymousUserWithCompletion:(void (^)(BOOL success, NSInteger statusCode))completion;

// update profile data for user
- (void)setupUserProfileWithData:(NSDictionary *)data
                      completion:(void (^)(BOOL success, NSInteger statusCode))completion;

// checks for updates on server of SpothillSDKSpot instances, campaigns or group campaigns can be changed on server side
- (void)checkForUpdatedSpotsWithCompletion:(void (^)(NSArray *spots))completion;


@end
