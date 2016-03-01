//
//  Provider.h
//  Spothill
//
//  Created by Martin Krivus on 14/06/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpothillSDKIgnoreableEntity.h"

@interface SpothillSDKProvider : SpothillSDKIgnoreableEntity

@property (strong, nonatomic, readonly) NSNumber *providerId;
@property (strong, nonatomic, readonly) NSString *title;

- (NSURL *)imageURL;

@end
