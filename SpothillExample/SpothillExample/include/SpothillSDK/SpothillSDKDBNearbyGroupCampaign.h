//
//  DBActualGroupCampaign.h
//  Spothill
//
//  Created by Martin Krivus on 02/11/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "SpothillSDKDBSpot.h"


@interface SpothillSDKDBNearbyGroupCampaign : SpothillSDKDBEntity

@property (nonatomic, retain) NSDecimalNumber * entityId;
@property (nonatomic, retain) NSData * data;
@property (nonatomic, retain) NSSet *spot;

@end

@interface SpothillSDKDBNearbyGroupCampaign (CoreDataGeneratedAccessors)

- (void)addSpotObject:(SpothillSDKDBSpot *)value;
- (void)removeSpotObject:(SpothillSDKDBSpot *)value;
- (void)addSpot:(NSSet *)values;
- (void)removeSpot:(NSSet *)values;

@end
