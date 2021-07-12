// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(name: "HelpCrunchSDK", targets: ["HelpCrunchSDK"])
    ],
    dependencies: [    
    	.package(url: "https://github.com/socketio/socket.io-client-swift", .upToNextMinor(from: "15.0.0"))
    ],
    targets: [
        .binaryTarget(
            name: "HelpCrunchSDKBinary", 
            path: "HelpCrunchSDK.xcframework"),
        .target(
            name: "HelpCrunchSDK",
            dependencies: ["socket.io-client-swift"])
    ]
)