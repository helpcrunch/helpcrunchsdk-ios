#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HCSUserAttribute : NSObject

@property (nonatomic) BOOL required;
@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) NSString *attributeName;

@property (nonatomic) UIKeyboardType keyboardType;
@property (nonatomic, strong) NSString *validationRegex;

- (HCSUserAttribute *)initWithAttributeName:(NSString *)attributeName
                                placeholder:(NSString *)placeholder
                                   required:(BOOL)required;

@end

NS_ASSUME_NONNULL_END
