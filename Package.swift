// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(name: "HelpCrunchSDK", targets: ["HelpCrunchSDK"])
    ],
    dependencies: [    
    	.package(url: "https://github.com/socketio/socket.io-client-swift", .upToNextMajor(from: "15.0.0"))
    ],
    targets: [
    	.binaryTarget(
            name: "HelpCrunchSDK", 
            path: "HelpCrunchSDK.xcframework"),
        .target(
            name: "HelpCrunchSDKSocket",
            dependencies: ["SocketIO"])
    ]
)