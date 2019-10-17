import UIKit

import HelpCrunchSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        //
        // Your initialization code
        // ...
        //
        
        setupHelpcrunch(launchOptions: launchOptions)
        
        return true
    }
    
    func setupHelpcrunch(launchOptions: [UIApplication.LaunchOptionsKey: Any]?) {
        let organization: String = ""
        let applicationId: String = ""
        let applicationSecret: String = "";
        
        let configuration = HCSConfiguration(forOrganization: organization,
                                             applicationId: applicationId,
                                             applicationSecret: applicationSecret)
        configuration.shouldUsePushNotificationDelegate = true
        
        // If you want to test PrechatForm screen - uncomment next line
        setupPrechatFormScreen(configuration: configuration)
        
        let user = HCSUser()
        user.userId = "testId"
        user.name = "SDK Test User"
        user.company = "Company LTD"
        
        HelpCrunch.initWith(configuration,
                            user: user) { (error) in
                                print("End of SDK initialization")
        }
        
        HelpCrunch.registerForRemoteNotifications()
        
        if !HelpCrunch.didReceiveRemoteNotification(launchOptions: launchOptions) {
            // This push notificaiton is not from HelpCrunch. Do something
        }
    }
    
    func setupPrechatFormScreen(configuration: HCSConfiguration) {
        configuration.userAttributes = [HCSUserAttribute.nameAttribute(asRequired: true),
                                        HCSUserAttribute.emailAttribute(asRequired: false),
                                        HCSUserAttribute(attributeName: "My custom attribute",
                                                         placeholder: "Enter something",
                                                         required: true)]
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        HelpCrunch.setDeviceToken(deviceToken)
    }
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        if !HelpCrunch.didReceiveRemoteNotification(userInfo) {
            // This push notificaiton is not from HelpCrunch. Do something
        }
    }
}

