// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(
            name: "HelpCrunchSDK",
            targets: ["HelpCrunchSDK"])
    ],
    targets: [
        .binaryTarget(name: "HelpCrunchSDK",
                      path: "HelpCrunchSDK.xcframework")
    ]
)
