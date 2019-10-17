# HelpCrunch SDK Objective C Test project

This is a test project that shows how you can properly install HelpCrunch SDK v2.x into your project

## Getting Started

These instructions will help you to install and run test project on your device or simulator.

All necessary information and help you can find in [this documentation](https://docs.helpcrunch.com/ios-sdk.html#create-a-new-app)

### Prerequisites

First of all you need to create iOS app in your account. [Here](https://docs.helpcrunch.com/ios-sdk.html#create-a-new-app) you can find help documentation how to do that. For further configuring we will need three parameters: **Organzation**, **ApplicationId** and **ApplicationSecret**. 

### Installing

Just clone the project and open console. You will need [CocoaPods](https://cocoapods.org/) installed on your machine. If you still don't have it, please visit [this link](https://guides.cocoapods.org/using/getting-started.html). It will help you install CocoaPods on your machine. 

After that just open folder with cloned project in console and run next command:
```
pod install
```

Wait until it installs every dependency and you ready to go!

## Starting the project

Now you can open
```HelpcrunchSDKDemoObjc.xcworkspace```

This is our test project. Open **AppDelegate.h**. Here we are setting up and configuring SDK in the -[setupHelpcrunchWithLaunchOptions:] method.

First of all you need to set **Organzation**, **ApplicationId** and **ApplicationSecret**, which you got from creating iOS app in your HelpCrunch account, to appropriate variables:
```
    NSString *organization = @"";
    NSString *applicationId = @"";
    NSString *applicationSecret = @""
 ```

Thats all, now you can launch your app and play with HelpCrunch chat.

### Logout

We created HCSUser at the start of the application so even if you try to logout - nothing happens. If you want to play with logout, comment or delete next lines:
```
    HCSUser *user = [HCSUser new];
    user.userId = @"testId";
    user.name = @"SDK Test User";
    user.company = @"Company LTD";
```

and change initialization method to:
```
    [HelpCrunch initWithConfiguration:configuration
                                 user:nil
                           completion:^(NSError * _Nullable error) {
                               NSLog(@"End of SDK initialization");
                           }];
```

## Prechat form screen

If you want to try pre chat form, where you ask user to provide some information, check this method in ViewController.m:
```
	- (IBAction)preformSwitchChanged:(id)sender
```

In this method you can see how you can set attributes that will be asked in pre chat form. For more information, please check [this link](https://docs.helpcrunch.com/ios-sdk.html?#welcome-screen).

## Theming

You can check our standard and dark themes simply by clicking on them in the main menu before you start chat. If you want to play with custom theme, that we provided for you as example, check this method in ViewController.m:
```
	- (void)setCustomTheme
```
