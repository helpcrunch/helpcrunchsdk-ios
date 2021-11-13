#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HCSUser : NSObject

@property (nonatomic, strong, nullable) NSString *userId;
@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *email;
@property (nonatomic, strong, nullable) NSString *phone;
@property (nonatomic, strong, nullable) NSString *company;

@property (nonatomic, strong, nullable) NSDictionary *customData;

@end

NS_ASSUME_NONNULL_END
