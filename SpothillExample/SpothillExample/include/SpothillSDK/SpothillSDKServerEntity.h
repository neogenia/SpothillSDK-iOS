//
//  ServerEntity.h
//  Spothill
//
//  Created by Martin Krivus on 18/08/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface SpothillSDKServerEntity : NSObject

@property (strong, nonatomic, readonly) NSMutableDictionary *dataDictionary;
@property (strong, nonatomic, readonly) NSDate *downloadDate;

+ (instancetype)createWithDictionary:(NSDictionary *)dictionary;
- (void)updateWithDictionary:(NSDictionary *)dictionary;

@end
