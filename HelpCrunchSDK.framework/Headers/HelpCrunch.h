#import <UIKit/UIKit.h>

#import "HCSConfiguration.h"
#import "HCSTheme.h"
#import "HCSUser.h"

#pragma mark - SDK Notification Events

/**
 Called on tap on corresponding data type. URL will be in userInfo[@"data"]
 */
FOUNDATION_EXTERN NSString * _Nonnull const HCSURLNotification;
FOUNDATION_EXTERN NSString * _Nonnull const HCSImageURLNotification;
FOUNDATION_EXTERN NSString * _Nonnull const HCSFileURLNotification;

/**
 Will be called when SDK state is changed
 */
FOUNDATION_EXTERN NSString * _Nonnull const HCSStateChangedNotification;

/**
 Will be called on user's first sent message
 */
FOUNDATION_EXTERN NSString * _Nonnull const HCSUserStartedChatNotification;

/**
 Will be called from both Prechat Form and Chat screens
 */
FOUNDATION_EXTERN NSString * _Nonnull const HCSUserClosedChatNotification;

/**
 Will be called each time number of unread chats changes. Could be called outside of main thread.
 */
FOUNDATION_EXTERN NSString * _Nonnull const HCSUnreadChatsNotification;

/**
 HelpCrunch SDK State
 
 - HCSUnknownState: Default state
 
 - HCSReadyState: SDK completed initialization and ready to use
 
 - HCSLoadingState: SDK is initializating
 
 - HCSUserIsBlockedState: Current user is blocked
 
 - HCSErrorState: SDK has failed to initialize
*/
typedef NS_ENUM(NSUInteger, HCSState) {
    /// Default state
    HCSIdleState,
    /// SDK completed initialization and ready to use
    HCSReadyState,
    /// SDK is initializating
    HCSLoadingState,
    /// Current user is blocked
    HCSUserIsBlockedState,
    /// SDK has failed to initialize
    HCSErrorState
};

static NSString * _Nonnull const HCSSDKVersion = @"3.0.2";

typedef void (^HCSCompletionHandler)(NSError * _Nullable error);

@interface HelpCrunch : NSObject

#pragma mark - State of the SDK

/**
 Initialize HelpCrunch sdk. You must call this method before any other SDK methods (except Theme methods)

 @param configuration Organization, ApplicationId and ApplicationSecret are required parameters. Everything else - optional.
 @param user You can apply user from beginning. If needed, use updateUser:completion method
 @param completion Will be called when HelpCrunch SDK completed initializtion
 */
+ (void)initWithConfiguration:(HCSConfiguration * _Nonnull)configuration
                         user:(HCSUser * _Nullable)user
                   completion:(HCSCompletionHandler _Nullable)completion;

+ (void)bindConfiguration:(HCSConfiguration * _Nonnull)configuration;
+ (HCSConfiguration * _Nonnull)configuration;

/**
 Actual state of SDK
 
 @return HCSState
 */
+ (HCSState)state;

/**
 Logout current user and remove current chat.
 If you require some user attributes, user will be prompted with Prechat Form screen on next showFromController:completion: call
 @param completion will be executed on successfull logout
 */
+ (void)logoutWithCompletion:(HCSCompletionHandler _Nullable)completion;

+ (void)updateUser:(HCSUser * _Nullable)user completion:(HCSCompletionHandler _Nullable)completion;

/**
 Number of unread chats. Will be reduced after user clicks on chat
 */
+ (NSUInteger)numberOfUnreadChats;

#pragma mark - Theming

+ (HCSTheme * _Nonnull)darkTheme;
+ (HCSTheme * _Nonnull)lightTheme;

+ (void)bindTheme:(HCSTheme * _Nonnull)theme;

#pragma mark - View Controllers

/**
 Returns true if Prechat Form or Chat view controllers currently on the screen
 */
+ (BOOL)isVisible;

/**
 Shows Prechat Form or Chat view controller presented from given View Controller
 
 @param viewController - view controller to be presented from
 @param completion - block, that will be executed on completion of presenting animation
 */
+ (void)showFromController:(UIViewController * _Nonnull)viewController completion:(HCSCompletionHandler _Nullable)completion;

/**
 Will dismiss HelpCrunch screens if any presented.
 Completion block won't fire if no HelpCrunch screen presented. Use [isVisible] method to check.
 
 @param completion - block, that will be executed on completion of dismissing animation.
 */
+ (void)closeChatWithCompletion:(HCSCompletionHandler _Nullable)completion;

#pragma mark - Push Notifications

/**
 Standard UserNotification permissions request. Use it only if you're not asking for permissions by yourself.
 */
+ (void)registerForRemoteNotifications;

/**
 Add your push notification device token to HelpCrunch

 @param deviceToken raw token data from AppDelegate's didRegisterForRemoteNotificationsWithDeviceToken: method
 */
+ (void)setDeviceToken:(NSData * _Nonnull)deviceToken;

+ (BOOL)didReceiveRemoteNotification:(NSDictionary *)userInfo;
+ (BOOL)didReceiveRemoteNotificationWithLaunchOptions:(NSDictionary *)launchOptions;
+ (BOOL)isHelpCrunchNotification:(NSDictionary * _Nonnull)notification;

+ (void)trackEvent:(NSString * _Nonnull)event;
+ (void)trackEvent:(NSString * _Nonnull)event data:(NSDictionary * __nullable)data;

@end

