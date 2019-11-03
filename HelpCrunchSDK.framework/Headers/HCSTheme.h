#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, HCSThemeBrandingType) {
    HCSThemeBrandingNone,
    HCSThemeBrandingLight,
    HCSThemeBrandingDark
};

@interface HCSTheme : NSObject<NSCopying>

@property (nonatomic, strong) UIColor *mainColor;

@property (nonatomic, strong) UIColor *chatBackgroundColor;
@property (nonatomic, strong) UIColor *chatDateColor;
@property (nonatomic, strong) UIColor *chatWaitingMessageBackgroundColor;
@property (nonatomic, strong) UIColor *chatWaitingMessageFontColor;
@property (nonatomic, strong, nullable) UIColor *chatWaitingMessageActivityIndicatorColor;

@property (nonatomic, strong) UIColor *navigationBarTextColor;
@property (nonatomic, strong) UIColor *navigationBarBackgroundColor;
@property (nonatomic, strong) UIColor *navigationBarBottomLineColor;
@property (nonatomic, strong) UIColor *navigationBarAgentsMoreBackgroundColor;
@property (nonatomic) BOOL isNavigationBarBottomLineVisible;

@property (nonatomic, strong) UIColor *messageIncomingBubbleColor;
@property (nonatomic, strong) UIColor *messageIncomingFontColor;
@property (nonatomic, strong) UIColor *messageIncomingAgentNameFontColor;
@property (nonatomic, strong) UIColor *messageIncomingLinksColor;
@property (nonatomic, strong) UIColor *messageIncomingFileTypeBackgroundColor;
@property (nonatomic, strong) UIColor *messageIncomingFileTypeFontColor;
@property (nonatomic, strong) UIColor *messageIncomingQuoteLineColor;
@property (nonatomic, strong) UIColor *messageIncomingCodeBorderColor;
@property (nonatomic, strong) UIColor *messageIncomingCodeFontColor;
@property (nonatomic, strong) UIColor *messageIncomingCodeBackgroundColor;

@property (nonatomic, strong) UIColor *messageOutgoingBubbleColor;
@property (nonatomic, strong) UIColor *messageOutgoingFontColor;
@property (nonatomic, strong) UIColor *messageOutgoingLinksColor;
@property (nonatomic, strong) UIColor *messageOutgoingFileTypeBackgroundColor;
@property (nonatomic, strong) UIColor *messageOutgoingFileTypeFontColor;
@property (nonatomic, strong) UIColor *messageOutgoingQuoteLineColor;
@property (nonatomic, strong) UIColor *messageOutgoingCodeBorderColor;
@property (nonatomic, strong) UIColor *messageOutgoingCodeFontColor;
@property (nonatomic, strong) UIColor *messageOutgoingCodeBackgroundColor;

@property (nonatomic, strong) UIColor *messageTimeColor;

// Send message view
@property (nonatomic, strong) UIColor *sendMessageBackgroundColor;
@property (nonatomic, strong) UIImage *sendMessageAttachmentIconImage;
@property (nonatomic, strong) UIImage *sendMessageSendButtonIconImage;
@property (nonatomic, strong) UIColor *sendMessageTextFieldBackgroundColor;
@property (nonatomic, strong) UIColor *sendMessageTextFieldBorderColor;
@property (nonatomic, strong) UIColor *sendMessageTextFieldFontColor;
@property (nonatomic, strong) UIColor *sendMessageTextFieldPlaceholderColor;

/**
 Default is null. On set Send button will use text instead of icon.
 */
@property (nonatomic, strong) NSString *sendMessageSendButtonText;
@property (nonatomic, strong) UIColor *sendMessageSendButtonColor;

// Prechat Form
@property (nonatomic, strong) UIColor *prechatFormTopMessageBackgroundColor;
@property (nonatomic, strong) UIColor *prechatFormTopMessageFontColor;
@property (nonatomic, strong) NSString *prechatFormContinueButtonText;
@property (nonatomic, strong) UIColor *prechatFormContinueButtonColor;
@property (nonatomic, strong) UIColor *prechatFormContinueTextColor;
@property (nonatomic, strong) UIColor *prechatFormTextFieldBackgroundColor;
@property (nonatomic, strong) UIColor *prechatFormTextFieldBorderColor;
@property (nonatomic, strong) UIColor *prechatFormTextFieldSelectedBorderColor;
@property (nonatomic, strong) UIColor *prechatFormTextFieldPlaceholderColor;
@property (nonatomic, strong) UIColor *prechatFormTextFieldFontColor;

@property (nonatomic) HCSThemeBrandingType brandingType;

@property (nonatomic) UIKeyboardAppearance keyboardAppearance;

@end

NS_ASSUME_NONNULL_END
