//
//  SpothillSDKCache.h
//  Spothill
//
//  Created by Martin Krivus on 04/12/15.
//  Copyright © 2015 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpothillSDKCampaignListTypes.h"


@interface SpothillSDKCache : NSObject

+ (instancetype)sharedInstance;

// returns data for list type from cache only
- (NSArray *)dataForListType:(SpothillSDKCampaignListType)listType;

// returns data in completion for list type, if force is NO the cache is used, otherwise
// it loads list from server
- (void)reloadListWithId:(SpothillSDKCampaignListType)listId
                   force:(BOOL)force
          withCompletion:(void (^)(NSArray *data, SpothillSDKCampaignListType listId))completion;

@end
