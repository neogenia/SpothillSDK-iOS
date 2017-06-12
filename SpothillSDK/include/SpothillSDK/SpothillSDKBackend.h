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
#import "SpothillSDKBeacon.h"
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

typedef NS_ENUM(NSUInteger, SpothillSDKBackendEnvironment) {
    SpothillSDKBackendEnvironmentProduction,
    SpothillSDKBackendEnvironmentBeta
};


@interface SpothillSDKBackend : NSObject

// stored after successful login or registration
@property (nonatomic, readonly) NSString * userHash;

// this is value identifing app that uses this SDK, should be provided by Neogenia s.r.o.
@property (strong, nonatomic) NSString * providerHash;

/*
    You can choose between https://beta.spothill.com and https://spothill.com servers.
    Set this value to SpothillSDKBackendEnvironmentBeta during development.
    User is signed off and cSpothillSDKBackendUserDidLogout notification is sent when
    you set environment property to a value that differs from the previous one.
 
    Defaults to SpothillSDKBackendEnvironmentProduction
 */
@property (assign, nonatomic) SpothillSDKBackendEnvironment environment;

// There you can specifi dubhomain of the https://spothill you must add the .com or other at the and of the subdomain
@property (nonatomic, strong) NSString *subdomain;


+ (instancetype)sharedInstance;

// returns YES after successful registration
- (BOOL)isLoggedIn;
- (void)logout;

// get spot representation for beacon, spot contains campaigns and groupCampaigns
- (void)getSpotForBeacon:(SpothillSDKBeacon *)beacon completion:(void (^)(SpothillSDKSpot *spot))completion;
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

// registration of user, this method can skip the activation process
- (void)registerUserWithData:(NSDictionary *)data
                 loginMethod:(LoginMethod)loginMethod
              skipActivation:(BOOL)skip
                  completion:(void (^)(BOOL success, NSInteger statusCode))completion;

// This is for virtual registration of user, so it can be paired with server actions
// and his data. Successful completion of this is mandatory before any other backend calls
// It uses LoginMethodSkipLogin register method.
- (void)registerAnonymousUserWithCompletion:(void (^)(BOOL success, NSInteger statusCode))completion;

// update profile data for user
- (void)setupUserProfileWithData:(NSDictionary *)data
                      completion:(void (^)(BOOL success, NSInteger statusCode))completion;

// checks for updates on server of SpothillSDKSpot instances, campaigns or group campaigns can be changed on server side
- (void)checkForUpdatedSpotsWithCompletion:(void (^)(NSArray<SpothillSDKBeacon *> *spots))completion;

/**
 *  Send spot log file from path
 *
 *  @param  completion
 *  @param  filename        NSString
 *  @param  path            NSString
 */
- (void) sendSpotLogFile:(NSString *)path filename:(NSString *)filename withCompletion:(void (^)(BOOL success))completion;
@end
