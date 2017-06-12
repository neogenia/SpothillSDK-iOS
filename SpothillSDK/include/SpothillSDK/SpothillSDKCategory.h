//
//  CampaignCategory.h
//  Spothill
//
//  Created by Martin Krivus on 03/10/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import "SpothillSDKIgnoreableEntity.h"

@interface SpothillSDKCategory : SpothillSDKIgnoreableEntity

@property (strong, nonatomic, readonly) NSNumber *categoryId;
@property (strong, nonatomic, readonly) NSString *title;

@end
