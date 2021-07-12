// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(name: "HelpCrunchSDK", targets: ["HelpCrunchSDK", "SocketIO"])
    ],
    dependencies: [    
    	.package(name: "SocketIO", url: "https://github.com/socketio/socket.io-client-swift", .upToNextMajor(from: "15.0.0"))
    ],
    targets: [
        // .binaryTarget(
        //     name: "HelpCrunchSDKBinary", 
        //     path: "HelpCrunchSDK.xcframework"),
        .binaryTarget(
            name: "HelpCrunchSDK",
            url: "https://sangwa.ru/HelpCrunchSDK.xcframework.zip",
            checksum: "699eb1be6c0cc030cc85274305cfd4e0eb5dd7fc5f7bed84029b2a4f8ba53f68"
            ),
        .target(
            name: "SocketIO",
            dependencies: ["SocketIO"])
    ]
)