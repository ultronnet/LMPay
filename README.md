# LMPay

乐马支付iOS SDK，第三方应用可通过此 SDK 支持乐马支付。[了解更多](https://www.lmpayplc.com)

## 功能

乐马支付SDK支持以下功能
- 单笔支付
- 批量支付
- 预授权冻结
- 乐贝提现

SDK支持两种支付交互：
- 安装乐马支付 App 时，自动跳转乐马支付 App 完成支付
- 未安装乐马支付 App 时，在应用中打开 Web 页面完成支付

## 集成步骤

1. 注册乐马开发者
2. 服务端接入
3. 客户端接入

## 注册开发者 

1. 请 [联系乐马支付](https://www.lmpayplc.com/#contact) 服务人员
2. 在乐马支付开发者应用登记页面，进行登记，登记并选择移动应用进行设置
3. 将该应用提交审核，只有审核通过的应用才能进行开发
4. 审核通过后将得到接入的 AppID

## 服务端接入

参考文档：https://www.showdoc.com.cn/394592199916192

## iOS SDK 接入

- iOS客户段接入请参考此文档，[下载示例代码](https://github.com/ultronnet/LMPay)
- Android 客户端接入请参考： <https://www.showdoc.com.cn/awesomesdk>

### 导入SDK

#### CocoaPods

在 `Podfile` 中添加以下内容
```
  use_frameworks!

  target 'YourTarget' do
     pod 'LMPay'
  end
```
然后执行 `pod install`

### 工程配置

1. 定义 URL Schemes

此 URL Schemes 用于支付完成后跳转回您的应用，您可以自定义值，但必须确保支付是的 `urlSchemes` 和 `info.plist` 中的值一致，
```
	<key>CFBundleURLTypes</key>
	<array>
		<dict>
			<key>CFBundleTypeRole</key>
			<string>Editor</string>
			<key>CFBundleURLSchemes</key>
			<array>
				<string>YourCustomSchemes</string>
			</array>
		</dict>
	</array>
```

2. 添加乐马支付 App 的 URL Schemes 到白名单，在 `info.plist` 文件中添加以下内容：
```
  <key>LSApplicationQueriesSchemes</key>
  <array>
    <string>NewLeMaPayApp</string>
  </array>
```

### 调用支付接口

```
LMPay.shareInstance().initForLema(
    withData: payData as Any,
    appType: "order",
    urlSchemes: "YourCustomSchemes",
    netEnvironment: 3,
    sdkLanguage: "zh-en",
    htmlPush: pushVC) { (result: [AnyHashable : Any]) in
    DispatchQueue.main.async {
        print(result)
    }
}
```
| 参数 | 说明 |
|- |- |
| data | 支付信息, 服务端接入支付API后，通过调用服务端接口获取的json数据 |
| appType | 应用类型 `order`=订单支付 `frozen`=预授权 `credit_getout`=乐贝提现`autopay_sign`=自动签约扣款 |
| urlSchemes | 路由名称，请确保和 `info.plist` 定义的相同 |
| netEnvironment | 环境 1:内网 2:外网 3:正式 默认正式3
| language |  中文：`zh-en` 英文：`en`  柬语：`km`  默认为中文  注意：此参数只用于手机未安装乐马支付app调起h5时使用 |
| viewController | 手机未安装app 则跳转h5 |
| errorCompletionBlock | 支付异常回调 |

### 状态码

|状态码| 说明 |
|-    | - |
|200  | LMPay H5加载完成 |
|201  | LMPay H5开始返回数据 |
|0    | 成功 |
|-100 | 路由名称为空 |
|-101 | LMPay H5加载失败 |
|-201 | 未安装乐马Pay |
|-202 | 退出支付 |
|-301 | SDK初始化失败 |
|-401 | 初始化接口调用失败 |

其他错误信息以 `ErrorCompletionBlock` 回调返回为准

## 常见问题

1. 支付完成无法跳回自己的App
   > 检测是否添加 URL Schemes 中的值是否和 `urlSchemes` 参数的值相同