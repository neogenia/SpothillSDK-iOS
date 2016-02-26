//
//  DBActualCampaign.h
//  Spothill
//
//  Created by Martin Krivus on 02/11/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SpothillSDKDBSpot.h"
#import "SpothillSDKDBEntity.h"

@class SpothillSDKDBSpot;

@interface SpothillSDKDBNearbyCampaign : SpothillSDKDBEntity

@property (nonatomic, retain) NSDecimalNumber * entityId;
@property (nonatomic, retain) NSData * data;
@property (nonatomic, retain) NSDate * showFrom;
@property (nonatomic, retain) NSDate * showUntil;

@property (nonatomic, strong) NSSet *spot;
@end

@interface SpothillSDKDBNearbyCampaign (CoreDataGeneratedAccessors)

- (void)addSpotObject:(SpothillSDKDBSpot *)value;
- (void)removeSpotObject:(SpothillSDKDBSpot *)value;
- (void)addSpot:(NSSet *)values;
- (void)removeSpot:(NSSet *)values;

@end
