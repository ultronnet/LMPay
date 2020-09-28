Pod::Spec.new do |s|  
    s.name              = 'LMPay'
    s.version           = '0.1.0'
    s.summary           = '乐马支付iOS SDK'
    s.homepage          = 'https://www.lmpayplc.com'

    s.author            = { 'Cyril' => 'cyril8239@gmail.com' }
    s.license           = { :type => 'Copyright', :text => 'Copyright © 2020.LM PAY PLC' }

    s.platform          = :ios
    s.source            = { :git => "https://github.com/ultronnet/LMPay.git", :tag => "#{s.version}" }

    s.ios.deployment_target = '10.0'
    s.vendored_frameworks = 'LMPay.framework'
    s.resources           = "LMPay.bundle"
    s.frameworks          = 'WebKit'
    s.dependency          "MBProgressHUD"
end  