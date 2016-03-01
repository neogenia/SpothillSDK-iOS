//
//  IgnoreableEntity.h
//  Spothill
//
//  Created by Martin Krivus on 01/11/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import "SpothillSDKServerEntity.h"


extern NSString *const cSpothillSDKIgnoreableEntitIgnoredChanged;

@interface SpothillSDKIgnoreableEntity : SpothillSDKServerEntity

@property (strong, nonatomic, readonly) NSDate *ignored;

- (void)toggleIgnoreWithCompletion:(void (^)(BOOL success))completion;

@end