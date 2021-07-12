// swift-tools-version:4.0
import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(name: "HelpCrunchSDK", targets: ["HelpCrunchSDK"]),
        .executable(name: "socket.io-test", targets: ["HelpCrunchSDK"])
    ],
    dependencies: [    
    	.package(url: "https://github.com/socketio/socket.io-client-swift", .upToNextMinor(from: "15.0.0"))
    ],
    targets: [
    	.binaryTarget(
            name: "HelpCrunchSDK", 
            path: "HelpCrunchSDK.xcframework"),
        .target(
            name: "HelpCrunchSDK",
            dependencies: ["SocketIO"])
    ]
)