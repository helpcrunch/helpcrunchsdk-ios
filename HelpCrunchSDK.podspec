Pod::Spec.new do |spec|
spec.name = "HelpCrunchSDK"
spec.version = "3.3.3"
spec.summary = "A perfect live chat, email automation and a super-intuitive help desk in one smart customer communication platform."
spec.documentation_url = 'https://docs.helpcrunch.com/ios-sdk.html'
spec.homepage = "https://github.com/helpcrunch/helpcrunchsdk-ios"
spec.license = { type: 'Apache 2.0', file: 'LICENSE' }
spec.authors = { "HelpCrunchSDK" => 'indo@helpcrunch.com' }
spec.swift_version = '4.0'

spec.frameworks = 'SystemConfiguration', 'AudioToolbox', 'UserNotifications', 'ImageIO'

spec.ios.deployment_target = '10.0'
spec.requires_arc = true
spec.source = { :git => "https://github.com/helpcrunch/helpcrunchsdk-ios.git", :tag => "#{spec.version}" }

spec.source_files = 'HelpCrunchSDK.framework/Headers/*.h'
spec.public_header_files = 'HelpCrunchSDK.framework/Headers/*.h'
spec.ios.vendored_frameworks = 'HelpCrunchSDK.framework'
spec.resources = 'HelpCrunchSDK.framework/HelpCrunchSDK.bundle'

spec.dependency 'Socket.IO-Client-Swift', '~> 15.0'

end

