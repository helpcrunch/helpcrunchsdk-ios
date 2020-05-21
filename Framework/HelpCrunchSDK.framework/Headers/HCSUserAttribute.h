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
@property (nonatomic, readonly) BOOL isPredefined;

- (HCSUserAttribute *)initWithAttributeName:(NSString *)attributeName
                                placeholder:(NSString *)placeholder
                                   required:(BOOL)required;

+ (HCSUserAttribute *)nameAttributeAsRequired:(BOOL)required;
+ (HCSUserAttribute *)emailAttributeAsRequired:(BOOL)required;
+ (HCSUserAttribute *)companyAttributeAsRequired:(BOOL)required;
+ (HCSUserAttribute *)phoneAttributeAsRequired:(BOOL)required NS_SWIFT_NAME(HCSUserAttribute.phoneAttribute(asRequired:));

@end

NS_ASSUME_NONNULL_END
