//
//  LemaAPI.h
//  LemaAPI
//
//  Created by adam on 2019/3/18.
//

#import <Foundation/Foundation.h>
#import "LemaAccessInfo.h"
#import "LemaUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol LemaAPIDelegate <NSObject>

- (void)onTokenResponse:(LemaAccessInfo*)info;
- (void)onTokenResponseError:(NSString*)msg;

- (void)onUserInfoResponse:(LemaUserInfo*)userInfo;
- (void)onUserInfoResponseError:(NSString*)msg;

@end

@interface LemaAPI : NSObject

+ (BOOL)isLemaInstalled;

//注册appid
+ (void)registerAPP:(NSString*)appid secret:(NSString*)secret;

//唤起乐马登录
+ (void)sendOAuthRequest;

//处理url
+ (void)handlerOpenUrl:(NSURL*)url delegate:(id <LemaAPIDelegate>) delegate;

//获取accessinfo
+ (void)getUserInfo:(LemaAccessInfo *)accessInfo delegate:(id <LemaAPIDelegate>) delegate;

@end

NS_ASSUME_NONNULL_END
