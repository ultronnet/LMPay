//
//  OAuthService.h
//  SDK
//
//  Created by adam on 2019/3/5.
//  Copyright © 2019年 test. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HttpServiceBase.h"

@interface OAuthService : HttpServiceBase

+ (OAuthService*)ShareInstance;

- (void)getAccessToken:(NSString*)appid secret:(NSString*)secret code:(NSString*)code handler:(void(^)(id imp, NSError *error))handler;
- (void)refreshAccessToken:(NSString*)appid refreshToken:(NSString*)token handler:(void(^)(id imp, NSError *error))handler;
- (void)getUserInfo:(NSString*)accessToken openId:(NSString *)openId handler:(void(^)(id imp, NSError *error))handler;

@end

