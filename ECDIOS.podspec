
Pod::Spec.new do |spec|
  spec.name         = "ECDIOS"
  spec.version      = "0.0.1"
  spec.summary      = "这是容联IM——iOS集成的sdk"
  spec.description  = "容联IMsdk"
  spec.homepage     = "https://github.com/dddfcz/ECDIOS"
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.author       = { "zcf" => "zcfjsjz@icloud.com" }
  spec.platform     = :ios, "10.0"
  spec.source       = { :git => "https://github.com/dddfcz/ECDIOS.git", :tag => "0.0.1" }
  spec.source_files  = "YTX_iOS_Full_SDK_v5.4.14t/**/*.{h,m}"
  spec.requires_arc = true
end
