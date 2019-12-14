
Pod::Spec.new do |spec|
  spec.name         = "ECDIOS"
  spec.version      = "0.0.4"
  spec.summary      = "容联IMSDK"
  spec.description  = "这是容联IM——iOS集成的sdk"
  spec.homepage     = "https://github.com/dddfcz/ECDIOS"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "zcfddd" => "zcfjsjz@icloud.com" }
  spec.platform     = :ios, "8.0"
  spec.source       = { :git => "https://github.com/dddfcz/ECDIOS.git", :tag => "0.0.4" }
  spec.source_files  = "YTX_iOS_Full_SDK_v5.4.14t/**/*.{h,m}"
  spec.resources = "YTX_iOS_Full_SDK_v5.4.14t/*.{bundle}"
  spec.vendored_libraries = "YTX_iOS_Full_SDK_v5.4.14t/libCCPiPhoneSDK.a"
  spec.frameworks = "CoreTelephony","MediaPlayer","CFNetwork","SystemConfiguration","MobileCoreServices","AudioToolbox","CoreGraphics","AVFoundation","VideoToolbox"
  spec.libraries = "resolv.9","icucore","sqlite3","z","bz2","c"
 spec.requires_arc = true
end
