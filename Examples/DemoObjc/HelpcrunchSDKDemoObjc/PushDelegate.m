#import "PushDelegate.h"
#import <HelpCrunchSDK/HelpCrunch.h>

@implementation PushDelegate

- (void)userNotificationCenter:(UNUserNotificationCenter *)center
       willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {

    if (![HelpCrunch userNotificationCenterShouldPresentNotification:notification]) {
        completionHandler(UNNotificationPresentationOptionNone);
    } else {
        if (@available(iOS 14.0, *)) {
            completionHandler(UNNotificationPresentationOptionList | UNNotificationPresentationOptionBanner | UNNotificationPresentationOptionSound);
        } else {
            completionHandler(UNNotificationPresentationOptionAlert);
        };
    }
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler {
    [HelpCrunch didReceiveRemoteNotification:response.notification.request.content.userInfo];

    completionHandler();
}

@end
