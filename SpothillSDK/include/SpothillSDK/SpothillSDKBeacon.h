//
//  SpothillSDKBeacon.h
//  SpothillSDK
//
//  Created by Martin Krivus on 19/07/16.
//  Copyright © 2016 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SpothillSDKBeacon : NSObject

@property (nonatomic) NSNumber *minor;
@property (nonatomic) NSNumber *major;
@property (nonatomic) NSUUID * proximityUUID;
@property (nonatomic) CLLocationAccuracy accuracy;

+ (SpothillSDKBeacon *)spothillBeaconForCLBeacon:(CLBeacon *)beacon;

@end
