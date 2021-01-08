//
//  AccessInfo.h
//  SDK
//
//  Created by adam on 2019/3/5.
//  Copyright © 2019年 test. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LemaAccessInfo : NSObject

@property (nonatomic, copy) NSString *accessToken;
@property (nonatomic, copy) NSString *refreshToken;
@property (nonatomic, copy) NSString * openId;
@property (nonatomic, assign) int expireIn;
@property (nonatomic, copy) NSString *scope;

+ (LemaAccessInfo *)parseToObject:(NSDictionary *)itemDict;

@end

