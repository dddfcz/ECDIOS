#
#  Be sure to run `pod spec lint ECDIOS.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|



  spec.name         = "ECDIOS"
  spec.version      = "0.0.1"
  spec.summary      = "这是容联IM——iOS集成的sdk"
  spec.description  = "容联IMsdk"
  spec.homepage     = "https://github.com/dddfcz/ECDIOS"
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.author             = { "zcf" => "zcfjsjz@icloud.com" }
  spec.platform     = :ios, "10.0"
  spec.source       = { :git => "http://EXAMPLE/ECDIOS.git", :tag => "#{spec.version}" }
  spec.source_files  = "ECDIOS/YTX_iOS_Full_SDK_v5.4.14t/**/*.{h,m}"
  spec.requires_arc = true


end
