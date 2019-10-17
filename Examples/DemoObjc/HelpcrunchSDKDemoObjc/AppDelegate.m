#import "AppDelegate.h"

// Don't forget to import HelpCrunchSDK
#import <HelpCrunchSDK/HelpCrunch.h>

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //
    // Your initialization code
    // ...
    //
    
    [self setupHelpcrunchWithLaunchOptions:launchOptions];
    
    return YES;
}

- (void)setupHelpcrunchWithLaunchOptions:(NSDictionary *)launchOptions {
//    NSString *organization = @"";
//    NSString *applicationId = @"";
//    NSString *applicationSecret = @"";
    NSString *organization = @"mobile";
    NSString *applicationId = @"1580";
    NSString *applicationSecret = @"3DJ51cmMVWGe5fI0VYmFK+CjJ0TdkxElKBIHvKvUuYvS86T/guV7Ddex2EMCVKy99mF/g6JZHkhv6c8lj1nNoA==";
    
    HCSConfiguration *configuration = [HCSConfiguration configurationForOrganization:organization
                                                                       applicationId:applicationId
                                                                   applicationSecret:applicationSecret];
    configuration.shouldUsePushNotificationDelegate = true;
    
    HCSUser *user = [HCSUser new];
    user.userId = @"testId";
    user.name = @"SDK Test User";
    user.company = @"Company LTD";
    
    // If you want to test Welcome screen - uncomment next line
    // [self setupWelcomeScreen:configuration];
    
    [HelpCrunch initWithConfiguration:configuration
                                 user:user
                           completion:^(NSError * _Nullable error) {
                               NSLog(@"End of SDK initialization");
                           }];
    
    // Yes, we want receive push notifications from HelpCruch
    [HelpCrunch registerForRemoteNotifications];
    
    if (![HelpCrunch didReceiveRemoteNotificationWithLaunchOptions:launchOptions]) {
        // This push notificaiton not from HelpCrunch. Do something
    }
}

- (void)setupWelcomeScreen:(HCSConfiguration *)configuration {
    configuration.userAttributes = @[[HCSUserAttribute nameAttributeAsRequired:true],
                                     [HCSUserAttribute emailAttributeAsRequired:false],
                                     [[HCSUserAttribute alloc] initWithAttributeName:@"My custom attribute"
                                                                         placeholder:@"Enter your something"
                                                                            required:true]];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [HelpCrunch setDeviceToken:deviceToken];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    if (![HelpCrunch didReceiveRemoteNotification:userInfo]) {
        // This push notificaiton is not from HelpCrunch. Do something
    }
}

@end
