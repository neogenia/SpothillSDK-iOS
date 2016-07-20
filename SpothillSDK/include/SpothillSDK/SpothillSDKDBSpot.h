//
//  DBSpot.h
//  Spothill
//
//  Created by Martin Krivus on 02/11/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "SpothillSDKDBEntity.h"

@class CLBeacon;
@class SpothillSDKBeacon;

@interface SpothillSDKDBSpot : SpothillSDKDBEntity

@property (nonatomic, retain) NSNumber * major;
@property (nonatomic, retain) NSNumber * minor;
@property (nonatomic, retain) NSString * proximityUUID;

@property (nonatomic, retain) NSNumber * minimumAccuracy;

@property (nonatomic, retain) NSDate * firstVisitTime;
@property (nonatomic, retain) NSDate * lastVisitTime;
@property (nonatomic, retain) NSDate * nextDownloadTime;

- (BOOL)isEqualToBeacon:(SpothillSDKBeacon *)beacon;

@end

