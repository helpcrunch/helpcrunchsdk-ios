#import "AppDelegate.h"

// Don't forget to import HelpCrunchSDK
#import <HelpCrunchSDK/HelpCrunch.h>
#import <UserNotifications/UserNotifications.h>

// For custom UNUserNotificationCenterDelegate purpose
#import "PushDelegate.h"

@interface AppDelegate ()

// For custom UNUserNotificationCenterDelegate purpose
@property (nonatomic, strong) PushDelegate *pushDelegate;

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
    // Yes, we want receive push notifications from HelpCruch
    [HelpCrunch registerForRemoteNotifications];
    
    // If you want to use your own UNUserNotificationCenterDelegate
    // uncomment this method.
//    [HelpCrunch disablePushNotificationDelegate];
    
    // In this project, you can see PushDelegate.h/m as an example.
    // DON'T FORGET: you need strong pointer to your Push Delegate.
    // Uncomment these two lines:
//    self.pushDelegate = [PushDelegate new];
//    [UNUserNotificationCenter currentNotificationCenter].delegate = self.pushDelegate;
    
    NSString *organization = @"";
    NSString *applicationId = @"";
    NSString *applicationSecret = @"";

    HCSConfiguration *configuration = [HCSConfiguration configurationForOrganization:organization
                                                                       applicationId:applicationId
                                                                   applicationSecret:applicationSecret];
    
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
}

- (void)setupWelcomeScreen:(HCSConfiguration *)configuration {
    configuration.userAttributes = @[[[HCSUserAttribute alloc] initWithAttributeName:@"My custom attribute"
                                                                         placeholder:@"Enter your something"
                                                                            required:true]];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [HelpCrunch setDeviceToken:deviceToken];
}

@end
