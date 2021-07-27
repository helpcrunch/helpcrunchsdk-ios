[![Platform](https://img.shields.io/badge/platforms-iOS-orange.svg)](https://cocoapods.org/pods/HelpcrunchSDK)
[![Languages](https://img.shields.io/badge/languages-OjbC-orange.svg)]()
[![CocoaPods](https://img.shields.io/cocoapods/v/HelpCrunchSDK.svg)](#cocoapods)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](#carthage)
[![Apache License](http://img.shields.io/badge/license-APACHE2-blue.svg?style=flat)](https://www.apache.org/licenses/LICENSE-2.0.html)

![HelpCrunch](https://helpcrunch.com/img/layout/menu/logo.svg)

# HelpCrunch SDK

A perfect live chat, email automation and a super-intuitive help desk in one smart customer communication platform.

## Contents

- [Requirements](#requirements)
- [Migration Guide](#migration-guide)
- [Installation](#installation)
   - [CocoaPods](#cocoapods)
   - [Carthage](#carthage)
   - [Manual installation](#manual-installation)
   - [Update Info.plist](#update-infoplist)
- [Documentation](#documentation)
- [License](#license)

## Requirements

- iOS 10.0+
- Xcode 10.0+
- ObjC / Swift 4.0+

## Migration guide

If you use older pre v2.0 versions, please update with our [migration giude](https://docs.helpcrunch.com/sdk-migration-guide-from-1-x-to-2-x.html)

## Installation

### [CocoaPods](https://cocoapods.org)

CocoaPods is a dependency manager for Swift and Objective-C Cocoa projects. It has over 43 thousand libraries and is used in over 3 million apps. CocoaPods can help you scale your projects elegantly.

CocoaPods is built with Ruby and is installable with the default Ruby available on OS X. We recommend you use the default ruby.

Using the default Ruby install can require you to use  `sudo`  when installing gems. Further installation instructions are in [the guides](https://guides.cocoapods.org/using/getting-started.html#getting-started).

```shell
$ sudo gem install cocoapods
```

There is also [Mac app](https://cocoapods.org/app) for CocoaPods. It only gets major releases ATM though.

#### Podfile

To integrate HelpCrunch into your Xcode project using CocoaPods, specify it in your `Podfile` (text file named `Podfile` in your Xcode project directory):

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '10.0'
use_frameworks!

target 'ProjectTargetName' do
  pod 'HelpCrunchSDK', '~> 3.0.0'
end
```

> Tip: CocoaPods provides a `pod init` command to create a Podfile with smart defaults. You should use it.

Now you can install the dependencies in your project:

```shell
$ pod install
```

Make sure to always open the Xcode workspace instead of the project file when building your project:

```shell
$ open App.xcworkspace
```

Now you can import your dependencies e.g.:

ObjC:
```objective-c
@import HelpCrunchSDK;
```
Swift:
```swift
import HelpCrunchSDK
```

### [Carthage](https://github.com/Carthage/Carthage)

Carthage is another way to add frameworks to your Cocoa application.

Carthage builds your dependencies and provides you with binary frameworks, but you retain full control over your project structure and setup. Carthage does not automatically modify your project files or your build settings.

If you haven't installed it yet, please check [quick-start guide](https://github.com/Carthage/Carthage#quick-start)

#### Cartfile

Create a Cartfile in the same directory where your .xcodeproj or .xcworkspace is.

Open Cartfile and add `github "helpcrunch/helpcrunchsdk-ios" ~> 3.0.0`

Run:
```shell
$ carthage update --platform ios --use-xcframeworks
```

Open `General` settings. Drag the built `HelpcrunchSDK.framework`, `SocketIO.framework` and `Starscream.framework` binaries from `Carthage/Build/iOS` into `Embedded Binaries` section. Don't forget to select `Copy items if needed`

### Manual installation

You will be required to do several extra steps:

Download [HelpcrunchSDK.framework](https://github.com/helpcrunch/helpcrunchsdk-ios) and copy it into `Embedded Binaries` section. Don't forget to select `Copy items if needed`.

Next, you need to add our dependencies - [Socket.IO](https://github.com/socketio/socket.io-client-swift) ~ v15.0 and [Starscream](https://github.com/daltoniam/Starscream). You can choose any option you want to install it.

And last: create a new `Run Script Phase` in `Build Phases`. Add this to the script field:
```shell
 bash "${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/HelpCrunchSDK.framework/strip-frameworks.sh"
```
You need to this, to fix [App Store submission bug](http://www.openradar.me/radar?id=6409498411401216)

### Update Info.plist

In order to send files and photos, you need to have `NSCameraUsageDescription`, `NSPhotoLibraryAddUsageDescription` and `NSPhotoLibraryUsageDescription` entries in your `Info.plist`.

These entries are required by Apple. User will be prompted for the Camera/Photo Library permissions with your provided text only when he tries to use the camera or open or save image to the Photo Library. 

`NSCameraUsageDescription` - When user tries to use Camera

`NSPhotoLibraryUsageDescription` - When user tries to open Photo Library

`NSPhotoLibraryAddUsageDescription` - When user tries to save image to the Photo Library

## Documentation

Documentation is [available here](https://docs.helpcrunch.com/ios-sdk.html)
Also you can check swift and objc app examples [here](https://github.com/helpcrunch/helpcrunchsdk-ios/tree/master/Examples)

## License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details
