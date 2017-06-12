//
//  UserProfile.h
//  Spothill
//
//  Created by Martin Krivus on 17/11/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const cUserProfileDidChange;

@interface SpothillSDKUserProfile : NSObject

@property (strong, nonatomic) NSDictionary *profileData;

+ (instancetype)sharedInstance;
- (void)save;
- (void)addProfileData:(NSDictionary *)data;

@end
