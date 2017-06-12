//
//  SpothillSDKCampaignListTypes.h
//  Spothill
//
//  Created by Martin Krivus on 04/12/15.
//  Copyright © 2015 Martin Krivus. All rights reserved.
//

#ifndef SpothillSDKCampaignListTypes_h
#define SpothillSDKCampaignListTypes_h

typedef NS_ENUM(int, SpothillSDKCampaignListType) {
    
    // these are loaded from database
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
};

#endif /* SpothillSDKCampaignListTypes_h */
