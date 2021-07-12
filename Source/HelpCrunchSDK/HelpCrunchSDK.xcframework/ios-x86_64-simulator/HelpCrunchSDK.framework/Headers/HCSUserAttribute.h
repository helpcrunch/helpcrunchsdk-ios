#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HCSUserAttribute : NSObject

@property (nonatomic) BOOL required;
@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) NSString *attributeName;

@property (nonatomic) UIKeyboardType keyboardType;
@property (nonatomic, strong) NSString *validationRegex;

/**
 User have Name, Company, Email and Phone as predefined system attributes.
 This parameter will be true if current object represents one of these attributes
 */
@property (nonatomic, readonly) BOOL isPredefined __attribute__((deprecated("This property is deprecated and won't be available beginning with 3.3 version. Please, configure pre-chat form via Customization tab in your account on the web.")));

- (HCSUserAttribute *)initWithAttributeName:(NSString *)attributeName
                                placeholder:(NSString *)placeholder
                                   required:(BOOL)required;

+ (HCSUserAttribute *)nameAttributeAsRequired:(BOOL)required __attribute__((deprecated("This method is deprecated and won't be available beginning with 3.3 version. Please, configure pre-chat form via Customization tab in your account on the web.")));
+ (HCSUserAttribute *)emailAttributeAsRequired:(BOOL)required __attribute__((deprecated("This method is deprecated and won't be available beginning with 3.3 version. Please, configure pre-chat form via Customization tab in your account on the web.")));
+ (HCSUserAttribute *)companyAttributeAsRequired:(BOOL)required __attribute__((deprecated("This method is deprecated and won't be available beginning with 3.3 version. Please, configure pre-chat form via Customization tab in your account on the web.")));
+ (HCSUserAttribute *)phoneAttributeAsRequired:(BOOL)required NS_SWIFT_NAME(HCSUserAttribute.phoneAttribute(asRequired:)) __attribute__((deprecated("This method is deprecated and won't be available beginning with 3.3 version. Please, configure pre-chat form via Customization tab in your account on the web.")));

@end

NS_ASSUME_NONNULL_END
