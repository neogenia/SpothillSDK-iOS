//
//  DBEntity.h
//  Spothill
//
//  Created by Martin Krivus on 02/11/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface SpothillSDKDBEntity : NSManagedObject

@property (nonatomic, retain) NSDate * createDate;

@end
