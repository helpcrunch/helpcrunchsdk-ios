#import <Foundation/Foundation.h>
#import "HCSUserAttribute.h"

NS_ASSUME_NONNULL_BEGIN

@interface HCSConfiguration : NSObject

@property (nonatomic, strong, nullable) NSArray<HCSUserAttribute *> *userAttributes;

@property (nonatomic, readonly) NSString *organization;
@property (nonatomic, readonly) NSString *applicationId;
@property (nonatomic, readonly) NSString *applicationSecret;

@property (nonatomic) BOOL isLoggingEnabled;

/**
 Server-based properties.
 */
@property (nonatomic, readonly) BOOL isFileAttachmentAllowed;

/**
 @summary
 If you're not using UserNotification delegate by yourself - set this property to True.
 
 @discussion
 If set to false - it's your responsibility to handle HelpCrunch push notificaitons.
 Use this code:
 \code
 if ([HelpCrunch isHelpCrunchNotification:notification.request.content.userInfo]) {
     if ([HelpCrunch isShowing]) {
        completionHandler(UNNotificationPresentationOptionNone);
     } else {
        completionHandler(UNNotificationPresentationOptionAlert);
     }
 }
 \endcode
 */
@property (nonatomic) BOOL shouldUsePushNotificationDelegate __deprecated_msg("Starting with iOS 13 we use our own UNUserNotificationCenterDelegate be default. To disable it and use your own class, please use [HelpCrunch disablePushNotificationDelegate] method.");


/// Modal presentation style for chat view controller
@property (nonatomic) UIModalPresentationStyle chatPresentationStyle;

/// modalInPresentation applied to the  view controller when you wish to force the presentation hosting the view controller into modal behavior.
/// When it is set to YES, the presentation will prevent interactive dismiss and ignore events outside of the presented view controller's bounds
/// Default is NO
@property (nonatomic) BOOL isModalInPresentation API_AVAILABLE(ios(13.0));

+ (HCSConfiguration *)configurationForOrganization:(NSString *)organization
                                     applicationId:(NSString *)applicationId
                                 applicationSecret:(NSString *)applicationSecret;

@end

NS_ASSUME_NONNULL_END
