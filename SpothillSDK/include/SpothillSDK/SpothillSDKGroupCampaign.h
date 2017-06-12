//
//  GroupCampain.h
//  Spothill
//
//  Created by Martin Krivus on 18/08/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import "SpothillSDKServerEntity.h"

@interface SpothillSDKGroupCampaign : SpothillSDKServerEntity

@property (nonatomic, strong, readonly) NSString *type;
@property (nonatomic, strong, readonly) NSString *title;
@property (nonatomic, strong, readonly) NSNumber *campaignId;
@property (nonatomic, assign, readonly) BOOL allowDetail;

- (UIImage *)labelImageForType;

@end
