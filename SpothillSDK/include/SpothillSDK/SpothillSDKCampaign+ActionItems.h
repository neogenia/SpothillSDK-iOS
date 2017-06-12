//
//  Campaign+ActionItems.h
//  Spothill
//
//  Created by Martin Krivus on 06/10/15.
//  Copyright © 2015 Martin Krivus. All rights reserved.
//

#import "SpothillSDKCampaign.h"


@interface SpothillSDKCampaignActionItem : NSObject

@property (strong, nonatomic, readonly) UIImage *icon;
@property (strong, nonatomic, readonly) UIColor *color;

@end


@interface SpothillSDKCampaign (ActionItems)

- (NSArray *)actionItems;

@end