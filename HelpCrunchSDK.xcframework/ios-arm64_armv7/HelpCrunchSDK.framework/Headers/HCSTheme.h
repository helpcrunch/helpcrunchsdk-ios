#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, HCSThemeBrandingType) {
    HCSThemeBrandingLight,
    HCSThemeBrandingDark
};

@class HCSThemePrechatForm;
@class HCSThemeChatArea;
@class HCSThemeSendMessageArea;
@class HCSThemeNavigationBar;
@class HCSThemeChats;
@class HCSThemeTabBar;
@class HCSThemeKB;

@interface HCSTheme : NSObject<NSCopying>

/**
  Default color for next properties:
 
 - chatArea.messageIncomingLinksColor
 - chatArea.messageOutgoingBubbleColor
 - sendMessageArea.sendButtonColor
 - prechatForm.continueButtonColor
 - chats.createButtonBackgroundColor
 - chats.unreadMessagesIndicatorColor
 - navigationBar.backgroundColor
 */
@property (nonatomic, strong) UIColor *mainColor;

/// Chats screen
@property (nonatomic, strong) HCSThemeChats *chats;

/// Colors of navigation bar, Agent view, etc.
@property (nonatomic, strong) HCSThemeNavigationBar *navigationBar;

/// Colors of tab bar, buttons, background
@property (nonatomic, strong) HCSThemeTabBar *tabBar;

/// Messages, waiting view, offline view, colors
@property (nonatomic, strong) HCSThemeChatArea *chatArea;

/// Send button, textfield, icon, colors
@property (nonatomic, strong) HCSThemeSendMessageArea *sendMessageArea;

/// Colors, textfields, button
@property (nonatomic, strong) HCSThemePrechatForm *prechatForm;

/// Colors, elements
@property (nonatomic, strong) HCSThemeKB *knowledgeBase;

@end


@interface HCSThemeNavigationBar : NSObject

@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *bottomLineColor;
@property (nonatomic, strong) UIColor *agentsMoreBackgroundColor;
@property (nonatomic) BOOL isBottomLineVisible;

@property (nonatomic, strong) UIColor *chatsNewIndicatorColor;

@end

@interface HCSThemeTabBar : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *deselectedColor;
@property (nonatomic, strong) UIColor *selectedColor;
@property (nonatomic, strong) UIColor *chatsNewIndicatorColor;
@property (nonatomic, strong) UIColor *separatorColor;

@end

@interface HCSThemeKB : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *itemBackground;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *titleDecoriationColor;

@property (nonatomic) UIBarStyle searchBarStyle;
@property (nonatomic) HCSThemeBrandingType brandingType;

@end

@interface HCSThemeChats : NSObject

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *unreadMessagesIndicatorColor;
@property (nonatomic, strong) UIColor *dateColor;
@property (nonatomic, strong) UIColor *messageColor;
@property (nonatomic, strong) UIColor *titleColor;

@property (nonatomic, strong) UIColor *createButtonColor;
@property (nonatomic, strong) UIColor *createButtonBackgroundColor;

@end


@interface HCSThemePrechatForm: NSObject

// Prechat Form
@property (nonatomic, strong) UIColor *topMessageBackgroundColor;
@property (nonatomic, strong) UIColor *topMessageFontColor;
@property (nonatomic, strong) NSString *continueButtonText;
@property (nonatomic, strong) UIColor *continueButtonColor;
@property (nonatomic, strong) UIColor *continueTextColor;
@property (nonatomic, strong) UIColor *textFieldBackgroundColor;
@property (nonatomic, strong) UIColor *textFieldBorderColor;
@property (nonatomic, strong) UIColor *textFieldSelectedBorderColor;
@property (nonatomic, strong) UIColor *textFieldPlaceholderColor;
@property (nonatomic, strong) UIColor *textFieldFontColor;

@property (nonatomic, strong) UIColor *backgroundColor;

@property (nonatomic) UIKeyboardAppearance keyboardAppearance;

@end


@interface HCSThemeChatArea : NSObject

@property (nonatomic, strong) UIColor *offlineMessageIconColor;
@property (nonatomic, strong) UIColor *offlineMessageBackgroundColor;
@property (nonatomic, strong) UIColor *offlineMessageTitleColor;

@property (nonatomic, strong) UIColor *ratingBackgroundColor;
@property (nonatomic, strong) UIColor *ratingTitleColor;
@property (nonatomic, strong) UIColor *ratingRatingsDefaultColor;
@property (nonatomic, strong) UIColor *ratingPoorColor;
@property (nonatomic, strong) UIColor *ratingAvarageColor;
@property (nonatomic, strong) UIColor *ratingGreatColor;

/**
 Default is true.
 */
@property (nonatomic) BOOL waitingMessageIsVisible;

@property (nonatomic, strong) UIColor *waitingMessageBackgroundColor;
@property (nonatomic, strong) UIColor *waitingMessageFontColor;
@property (nonatomic, strong, nullable) UIColor *waitingMessageActivityIndicatorColor;

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
@property (nonatomic, strong) UIColor *dateColor;

@property (nonatomic, strong) UIColor *backgroundColor;

@property (nonatomic) HCSThemeBrandingType brandingType;

@end


@interface HCSThemeSendMessageArea : NSObject

@property (nonatomic) UIKeyboardAppearance keyboardAppearance;

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, strong) UIColor *backgroundDisabledColor;

@property (nonatomic, strong) UIColor *textFieldFontColor;
@property (nonatomic, strong) UIColor *textFieldPlaceholderColor;
@property (nonatomic, strong) UIColor *textFieldPlaceholderDisabledColor;

@property (nonatomic, strong) UIImage *attachmentIconImage;

/**
 Default is null. On set Send button will use text instead of icon.
 */
@property (nonatomic, strong) NSString *sendButtonText;
@property (nonatomic, strong) UIColor *sendButtonColor;
@property (nonatomic, strong) UIColor *sendButtonDisabledColor;
@property (nonatomic, strong) UIImage *sendButtonIconImage;

@end

NS_ASSUME_NONNULL_END
