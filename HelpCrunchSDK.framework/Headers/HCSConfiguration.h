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
@property (nonatomic, readonly) BOOL isBrandingVisible;
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
@property (nonatomic) BOOL shouldUsePushNotificationDelegate;

+ (HCSConfiguration *)configurationForOrganization:(NSString *)organization
                                     applicationId:(NSString *)applicationId
                                 applicationSecret:(NSString *)applicationSecret;

@end

NS_ASSUME_NONNULL_END
