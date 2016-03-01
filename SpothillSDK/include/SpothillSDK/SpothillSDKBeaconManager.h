//
//  SpothillSDKBeaconManager.h
//  Spothill
//
//  Created by Martin Krivus on 25/05/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

// UUID of all spothill beacons
extern NSString * const kBeaconUUID; //  @"a1b2c3d4-aaaa-48d2-b060-d0c0d0c0d0c0"


@class SpothillSDKSpot;

@interface SpothillSDKBeaconManager : NSObject<CLLocationManagerDelegate>

// location manager used for beacon monitoring
@property (nonatomic, strong, readonly) CLLocationManager *locationManager;

// nearby beacons that are currently ranged
@property (nonatomic, strong, readonly) NSArray *nearbyBeacons;
// state of beacon region e.g. inside/outside/unknown
@property (nonatomic, assign, readonly) CLRegionState regionState;

// used for testing purposes, in simulator it can be used to initiate ranging of a beacon with desired parameters
- (void)testRangingOfBeaconWithMinor:(NSInteger)minor mayor:(NSInteger)mayor accuracy:(double)accuracy;

@end
