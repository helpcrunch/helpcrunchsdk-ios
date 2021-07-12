// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(name: "HelpCrunchSDK", targets: ["HelpCrunchSDK", "HelpCrunchSDKBinary"])
    ],
    dependencies: [    
    	.package(url: "https://github.com/socketio/socket.io-client-swift", .upToNextMajor(from: "15.0.0"))
    ],
    targets: [
        .binaryTarget(
            name: "HelpCrunchSDKBinary", 
            path: "./Source/HelpCrunchSDK/HelpCrunchSDK.xcframework"),
        .target(
            name: "HelpCrunchSDK",
            dependencies: ["socket.io-client-swift"])
    ]
)