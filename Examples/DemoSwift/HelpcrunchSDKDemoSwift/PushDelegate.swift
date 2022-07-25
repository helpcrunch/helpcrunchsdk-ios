import Foundation
import UserNotifications
import HelpCrunchSDK

class PushDelegate {
        
    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
            
        if HelpCrunch.userNotificationCenterShouldPresent(notification) {
            if #available(iOS 14.0, *) {
                completionHandler([.list, .badge, .sound])
            } else {
                completionHandler([.alert])
            }
        } else {
            completionHandler([])
        }
    }
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        HelpCrunch.didReceiveRemoteNotification(response.notification.request.content.userInfo)

        completionHandler()
    }
}
