//
//  SpothillSDKCache.h
//  Spothill
//
//  Created by Martin Krivus on 04/12/15.
//  Copyright © 2015 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpothillSDKCampaignListTypes.h"

@class SpothillSDKServerEntity;

@interface SpothillSDKCache : NSObject

+ (instancetype)sharedInstance;

/* returns data for list type from cache only
 // 
 CampaignListTypeNearbyGroupCampaigns = -1,
 CampaignListTypeNearbyCampaigns = 0,
 
 // these are loaded from server
 CampaignListTypeReminder = 1,
 CampaignListTypeFavouriteCampaign = 2,
 CampaignListTypeHistoryAll = 3,
 CampaignListTypeIgnoredCategories = 4,
 CampaignListTypeIgnoredProviders = 5,
 CampaignListTypeHistoryDay = 6,
 CampaignListTypeHistoryWeek = 7,
 CampaignListTypeHistoryIgnored = 8,
 CampaignListTypeFavouriteProviders = 9,
*/
- (NSArray *)dataForListType:(SpothillSDKCampaignListType)listType;

/**
 *  Clear cached history entities
 */
- (void)campaignBlockedChanged;

// returns data in completion for list type, if force is NO the cache is used, otherwise
// it loads list from server
- (void)reloadListWithId:(SpothillSDKCampaignListType)listId
                   force:(BOOL)force
          withCompletion:(void (^)(NSArray *data, SpothillSDKCampaignListType listId))completion;

@end
