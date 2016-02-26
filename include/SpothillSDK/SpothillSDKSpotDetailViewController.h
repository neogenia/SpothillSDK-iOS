//
//  SpothillSDKSpotDetailViewController.h
//  Spothill
//
//  Created by Martin Krivus on 09/06/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SpothillSDKCampaign;
@class SpothillSDKGroupCampaign;

@interface SpothillSDKSpotDetailViewController : UIViewController

+ (instancetype)spotDetailViewControllerWithCampaignId:(NSNumber *)campaignId;
+ (instancetype)spotDetailViewControllerWithCampaign:(SpothillSDKCampaign *)campaign;
+ (instancetype)spotDetailViewControllerWithGroupCampaign:(SpothillSDKGroupCampaign *)groupCampaign;

@end
