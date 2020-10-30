//
//  LeMaPayTool.h
//  LeMaOCPaySDK
//
//  Created by apple on 2019/11/9.
//  Copyright © 2019 apple. All rights reserved.
//

/* 使用说明
 *1.将SDK接入项目中
 *2.jiangImage.bundle引入项目中
 *3.在项目pod中引入MBProgressHUD
 *4.在项目URL Types中加入Url Schemes  info-》url types
 *5.info.plist 文件中加入白名单 LeMaPayApp
 */

/* code 错误码
   200: LMPay H5加载完成
   201: LMPay H5开始返回数据
   0   : 成功
 -100: 路由名称为空
 -101: LMPay H5加载失败
 -201: 未安装乐马Pay
 -202: 退出支付
 -301: SDK初始化失败
 -401: 初始化接口调用失败
  其他错误信息以ErrorCompletionBlock 回调返回为准
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ErrorCompletionBlock)(NSDictionary *resultDic);

@interface LMPay : NSObject

//初始化
+ (LMPay *)shareInstance;

/**
SDK支付接口
@param data 支付支付信息, 后端接口获取的json数据
@param appType 应用类型order=订单支付 frozen=预授权 credit_getout=乐贝提现 autopay_sign=自动签约扣款
@param urlSchemes 路由名称
@param netEnvironment 环境 1:内网 2:外网 3:正式     默认正式3
@param language  中文：zh-cn 英文：en  柬语：km  默认为中文  注意：此参数只用于手机未安装乐马支付app调起h5时使用
@param viewController  手机未安装app 则跳转h5
@param errorCompletionBlock  支付异常回调
*/
- (void)initForLemaWithData:(id)data
                    appType:(NSString *)appType
                 urlSchemes:(NSString *)urlSchemes
             netEnvironment:(NSInteger)netEnvironment
                SDKLanguage:(NSString *)language
         htmlPushController:(UIViewController *)viewController
                   isMustH5:(BOOL)isMustH5
                  errorback:(ErrorCompletionBlock)errorCompletionBlock;


@end

NS_ASSUME_NONNULL_END
