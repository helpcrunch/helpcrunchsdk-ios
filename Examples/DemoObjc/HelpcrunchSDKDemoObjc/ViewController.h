#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) IBOutlet UIButton *launchButton;
@property (nonatomic, strong) IBOutlet UIButton *logoutButton;
@property (nonatomic, strong) IBOutlet UITableView *tableView;
@property (nonatomic, strong) IBOutlet UISwitch *preformSwitch;

@end

