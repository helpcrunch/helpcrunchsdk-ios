// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "HelpCrunchSDK",
    products: [
        .library(name: "HelpCrunchSDK", targets: ["HelpCrunchSDK"])
    ],
    dependencies: [    
    	.package(name: "SocketIO", url: "https://github.com/socketio/socket.io-client-swift", .upToNextMajor(from: "15.0.0"))
    ],
    targets: [
        // .binaryTarget(
        //     name: "HelpCrunchSDKBinary", 
        //     path: "HelpCrunchSDK.xcframework"),
        .binaryTarget(
            name: "HelpCrunchSDKBinary",
            url: "https://ucf0b01e0ff542ef7842e0adcd8b.dl.dropboxusercontent.com/cd/0/get/BSKH-xEwysJo737E6NVsYsePbrZ8JFLnytejDEWngXVYOMbGKXKbqTLFpT5NcJRfRrvjBGNDlenTqWhfNToEmeGOrUqBQSUR-pNUotgoUsmsw8-S7MJhY02Et-K5tyE0ASQ42Ou25tHWxlsI7TMGG0mQ/file?dl=1",
            checksum: "699eb1be6c0cc030cc85274305cfd4e0eb5dd7fc5f7bed84029b2a4f8ba53f68"
            ),
        .target(
            name: "HelpCrunchSDK",
            dependencies: ["HelpCrunchSDKBinary", "SocketIO"])
    ]
)