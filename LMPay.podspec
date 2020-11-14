Pod::Spec.new do |s|  
    s.name              = 'LMPay'
    s.version           = '0.2.1'
    s.summary           = '乐马支付iOS SDK'
    s.homepage          = 'https://www.lmpayplc.com'

    s.author            = { 'Cyril' => 'cyril8239@gmail.com' }
    s.license           = { :type => 'Copyright', :text => 'Copyright © 2020.LM PAY PLC' }

    s.platform          = :ios
    s.source            = { :git => "https://github.com/ultronnet/LMPay.git", :tag => "#{s.version}" }

    s.ios.deployment_target = '10.0'
    s.vendored_frameworks = 'LMPay.framework'
    s.frameworks          = 'WebKit'
    s.dependency          "MBProgressHUD"

    s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end  