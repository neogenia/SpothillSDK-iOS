//
//  UIColor+Spothill.h
//  Spothill
//
//  Created by Martin Krivus on 01/07/14.
//  Copyright (c) 2014 Martin Krivus. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Spothill)

+ (UIColor *)spothillLightRed;
+ (UIColor *)spothillRed;
+ (UIColor *)spothillDarkRed;
+ (UIColor *)spothillBlue;
+ (UIColor *)spothillDarkBlue;
+ (UIColor *)spothillMenuDarkBlue;
+ (UIColor *)spothillMenuSeparator;
+ (UIColor *)spothillLightBlue;
+ (UIColor *)spothillNavigationBlue;
+ (UIColor *)spothillGreen;
+ (UIColor *)spothillOrange;
+ (UIColor *)spothillGrayListBackground;
+ (UIColor *)spothillGrayListLine;
+ (UIColor *)spothillGrayArrow;
+ (UIColor *)spothillGrayHeader;
+ (UIColor *)spothillGrayPerex;

- (UIImage *)imageWithSize:(CGSize)size;

@end
