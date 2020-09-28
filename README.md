# LMPay

乐马支付iOS SDK
https://www.lmpayplc.com

## 功能
【单笔支付】、【批量支付】、【预授权冻结】、【乐贝提现】
自动判断是否安装乐马支付App

## 集成步骤

1. 注册乐马开发者
2. 服务端接入
3. 客户端接入

## 注册开发者 
请到乐马支付开发者应用登记页面，进行登记，登记并选择移动应用进行设置后，将该应用提交审核，只有审核通过的应用才能进行开发。
审核通过后将得到接入的AppID。

## 服务端接入

## iOS SDK 接入

/* 使用说明
 *1.将SDK接入项目中
 *2.在项目pod中引入MBProgressHUD
 *3.在项目URL Types中加入Url Schemes  info-》url types
 *4.info.plist 文件中加入白名单 LeMaPayApp
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

/**
SDK支付接口
@param data 支付支付信息, 后端接口获取的json数据
@param appType 应用类型order=订单支付 frozen=预授权 credit_getout=乐贝提现 autopay_sign=自动签约扣款
@param urlSchemes 路由名称
@param netEnvironment 环境 1:内网 2:外网 3:正式     默认正式3
@param language  中文：zh-en 英文：en  柬语：km  默认为中文  注意：此参数只用于手机未安装乐马支付app调起h5时使用
@param viewController  手机未安装app 则跳转h5
@param errorCompletionBlock  支付异常回调

