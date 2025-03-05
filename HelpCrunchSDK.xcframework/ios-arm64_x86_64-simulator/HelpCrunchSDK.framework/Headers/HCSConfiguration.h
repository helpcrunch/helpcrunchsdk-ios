#import <Foundation/Foundation.h>
#import "HCSUserAttribute.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, HCSViewType) {
    // Only Chat is enabled.
    HCSViewTypeChatOnly,
    // Chat and KB are enabled. Chat will try to open first
    HCSViewTypeChatFirst,
    // Only KB is enabled.
    HCSViewTypeKbOnly,
    // Chat and KB are enabled. KB will try to open first
    HCSViewTypeKbFirst,
    // Default State
    HCSViewTypeServiceDefault
};

@interface HCSConfiguration : NSObject

@property (nonatomic, strong, nullable) NSArray<HCSUserAttribute *> *userAttributes;

@property (nonatomic, readonly) NSString *organization;
@property (nonatomic, readonly) NSString *applicationId;
@property (nonatomic, readonly) NSString *applicationSecret;

@property (nonatomic) BOOL isLoggingEnabled;
@property (nonatomic) BOOL isCameraEnabled;

/**
 Server-based properties.
 */
@property (nonatomic, readonly) BOOL isFileAttachmentAllowed;

/// Modal presentation style for chat view controller
@property (nonatomic) UIModalPresentationStyle chatPresentationStyle;

/// modalInPresentation applied to the  view controller when you wish to force the presentation hosting the view controller into modal behavior.
/// When it is set to YES, the presentation will prevent interactive dismiss and ignore events outside of the presented view controller's bounds
/// Default is NO
@property (nonatomic) BOOL isModalInPresentation;

+ (HCSConfiguration *)configurationForOrganization:(NSString *)organization
                                     applicationId:(NSString *)applicationId
                                 applicationSecret:(NSString *)applicationSecret;

@end

NS_ASSUME_NONNULL_END
