// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(
            name: "HelpCrunchSDK",
            targets: ["HelpCrunchSDK", "HelpCrunch"])
    ],
    dependencies: [
        .package(name: "SocketIO", url: "https://github.com/socketio/socket.io-client-swift", .upToNextMajor(from: "15.0.0")),
    ],
    targets: [
        .binaryTarget(name: "HelpCrunchSDK",
                      path: "HelpCrunchSDK.xcframework"),
        .target(name: "HelpCrunch",
                dependencies: ["SocketIO"])
    ]
)
