//
//  1_TwoSum.m
//  leetcode
//
//  Created by hatlonely on 16/2/5.
//  Copyright © 2016年 hatlonely. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface TwoSum : NSObject

- (NSMutableArray *)twoSum:(NSArray *)nums sum:(int)target;

@end

@implementation TwoSum

- (NSMutableArray *)twoSum:(NSArray *)nums sum:(int)target {
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
    NSInteger count = nums.count;
    for (NSInteger i = 0; i < count; i++) {
        [dict setObject:[NSNumber numberWithLong:i] forKey:[nums objectAtIndex:i]];
    }
    for (NSInteger i = 0; i < count; i++) {
        if ([dict ]) {
            <#statements#>
        }
    }
}

@end