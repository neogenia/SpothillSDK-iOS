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

@property (nonatomic) NSString * providerHash;

+ (instancetype)sharedInstance;

- (NSMutableURLRequest *)createRequestWithApiCall:(NSString *)apiCall
                                       parameters:(NSDictionary *)parameters;
- (void)performRequest:(NSMutableURLRequest *)request
        withCompletion:(void (^)(NSURLResponse *response, id responseObject, NSError *error))completionHandler;

- (void)logout;
- (BOOL)isLoggedIn;

// spots
- (void)getSpotForBeacon:(CLBeacon *)beacon completion:(void (^)(SpothillSDKSpot *spot))completion;
- (NSMutableURLRequest *)requestCampaignDetailForCampaignId:(NSNumber *)campaignId;

// actions
- (void)toggleReminderForCampaign:(SpothillSDKCampaign *)campaign   completion:(void (^)(BOOL success))completion;
- (void)toggleFavouriteForCampaign:(SpothillSDKCampaign *)campaign  completion:(void (^)(BOOL success))completion;
- (void)toggleIgnoreCampaign:(SpothillSDKCampaign *)campaign        completion:(void (^)(BOOL success))completion;
- (void)toggleIgnoreCategory:(SpothillSDKCategory *)category        completion:(void (^)(BOOL success))completion;
- (void)toggleIgnoreProvider:(SpothillSDKProvider *)provider        completion:(void (^)(BOOL success))completion;

// lists
- (void)getListWithId:(SpothillSDKCampaignListType)listId
           completion:(listCompletionBlock)completion;

// registration
- (void)registerUserWithData:(NSDictionary *)data
                 loginMethod:(LoginMethod)loginMethod
                  completion:(void (^)(BOOL success, NSInteger statusCode))completion;

- (void)registerAnonymousUserWithCompletion:(void (^)(BOOL success, NSInteger statusCode))completion;

// setup
- (void)setupUserProfileWithData:(NSDictionary *)data
                      completion:(void (^)(BOOL success, NSInteger statusCode))completion;

- (void)checkForUpdatedSpotsWithCompletion:(void (^)(NSArray *spots))completion;


@end
