#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HCSUser : NSObject

@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *company;

@property (nonatomic, strong) NSDictionary *customData;

@end

NS_ASSUME_NONNULL_END
