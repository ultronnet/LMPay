//
//  LemaUserInfo.h
//  LemaAPI
//
//  Created by adam on 2019/3/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LemaUserInfo : NSObject

@property(nonatomic, copy)NSString *openId;
@property(nonatomic, copy)NSString *nickName;
@property(nonatomic, copy)NSString *headerUrl;

+ (LemaUserInfo *)parseToObject:(NSDictionary *)itemDict ;

@end

NS_ASSUME_NONNULL_END
