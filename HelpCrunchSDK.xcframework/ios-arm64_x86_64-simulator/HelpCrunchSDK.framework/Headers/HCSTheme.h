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
 - knowledgeBase.signInButtonColor
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
@property (nonatomic) UIBarStyle barStyleUnderStatusBar;

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

@property (nonatomic, strong) UIColor *textFieldPlaceholderColor;
@property (nonatomic, strong) NSString *signInButtonText;
@property (nonatomic, strong) UIColor *signInButtonColor;
@property (nonatomic, strong) UIColor *signInTextColor;
@property (nonatomic, strong) UIColor *accessTitleTextColor;

@property (nonatomic, strong) UIColor *languageButtonBackgroundColor;
@property (nonatomic, strong) UIColor *languageButtonTextColor;

@property (nonatomic) UIBarStyle searchBarStyle;
@property (nonatomic, strong) UIColor *searchBarBackgroundColor;
@property (nonatomic, strong) UIColor *searchBarPlaceholderColor;
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

@property (nonatomic, strong) UIColor *messageIncomingKnowledgeBaseColor;
@property (nonatomic, strong) UIColor *messageIncomingFileColor;
@property (nonatomic, strong) UIColor *messageIncomingFileTypeBackgroundColor __deprecated_msg("Use messageIncomingFileColor instead.");
@property (nonatomic, strong) UIColor *messageIncomingFileTypeFontColor __deprecated_msg("Use messageIncomingFileColor instead.");

@property (nonatomic, strong) UIColor *messageIncomingQuoteLineColor;
@property (nonatomic, strong) UIColor *messageIncomingCodeBorderColor __deprecated_msg("New design doesn't have border for code");
@property (nonatomic, strong) UIColor *messageIncomingCodeFontColor;
@property (nonatomic, strong) UIColor *messageIncomingCodeBackgroundColor;

@property (nonatomic, strong) UIColor *messageOutgoingBubbleColor;
@property (nonatomic, strong) UIColor *messageOutgoingFontColor;
@property (nonatomic, strong) UIColor *messageOutgoingLinksColor;

@property (nonatomic, strong) UIColor *messageOutgoingKnowledgeBaseColor;
@property (nonatomic, strong) UIColor *messageOutgoingFileColor;
@property (nonatomic, strong) UIColor *messageOutgoingFileTypeBackgroundColor __deprecated_msg("Use messageOutgoingFileColor instead.");
@property (nonatomic, strong) UIColor *messageOutgoingFileTypeFontColor __deprecated_msg("Use messageOutgoingFileColor instead.");

@property (nonatomic, strong) UIColor *messageOutgoingQuoteLineColor;
@property (nonatomic, strong) UIColor *messageOutgoingCodeBorderColor __deprecated_msg("New design doesn't have border for code");
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

@property (nonatomic, strong) UIColor *backgroundCustomKeyboard;

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
