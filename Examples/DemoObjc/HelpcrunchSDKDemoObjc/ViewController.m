#import "ViewController.h"

@import HelpCrunchSDK;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView selectRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:0]
                                animated:false
                          scrollPosition:UITableViewScrollPositionNone];
    
    HCSConfiguration *configuration = [HelpCrunch configuration];
    self.preformSwitch.on = (configuration.userAttributes != nil);

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(updateLaunchButton)
                                                 name:HCSUnreadMessagesNotification
                                               object:nil];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [self updateLaunchButton];
}

- (void)updateLaunchButton {
    if ([HelpCrunch numberOfUnreadMessages]) {
        [self.launchButton setTitle:[NSString stringWithFormat:@"Launch chat (%i unread)", (int)[HelpCrunch numberOfUnreadMessages]]
                           forState:UIControlStateNormal];
    } else {
        [self.launchButton setTitle:@"Launch chat"
                           forState:UIControlStateNormal];
    }
}

#pragma mark - IBActions

- (IBAction)buttonLaunchTouched:(id)sender {
    [HelpCrunch showFromController:self
                        completion:^(NSError * _Nullable error) {
                            NSLog(@"HelpCrunch is on screen");
                        }];
}

- (IBAction)buttonLogoutTouched:(id)sender {
    self.view.userInteractionEnabled = false;
    
    [self.logoutButton setTitle:@"Please wait" forState:UIControlStateNormal];
    
    [HelpCrunch logoutWithCompletion:^(NSError * _Nullable error) {
        self.view.userInteractionEnabled = true;
        
        [self.logoutButton setTitle:@"Logout" forState:UIControlStateNormal];
    }];
}

- (IBAction)preformSwitchChanged:(id)sender {
    HCSConfiguration *configuration = [HelpCrunch configuration];
    
    if (!self.preformSwitch.on) {
        configuration.userAttributes = nil;
        
        return;
    }
    
    configuration.userAttributes = @[[HCSUserAttribute nameAttributeAsRequired:true],
                                     [HCSUserAttribute emailAttributeAsRequired:false],
                                     [[HCSUserAttribute alloc] initWithAttributeName:@"My custom attribute"
                                                                         placeholder:@"Enter your something"
                                                                            required:true]];
}

#pragma mark - Theme

- (void)setCustomTheme {
    HCSTheme *theme = [HelpCrunch defaultTheme];
    
    theme.mainColor = [UIColor colorWithRed:0.90 green:0.51 blue:0.15 alpha:1.00];
    
    theme.sendButtonText = @"Send";
    
    [HelpCrunch bindTheme:theme];
}

#pragma mark - UITableView delegate and source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 3;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifier = @"themeCell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    
    switch (indexPath.row) {
        case 0:
            cell.textLabel.text = @"Light theme";
            break;
        case 1:
            cell.textLabel.text = @"Dark theme";
            break;
        case 2:
            cell.textLabel.text = @"Custom theme";
            break;
        default:
            break;
    }
        
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    switch (indexPath.row) {
        case 0:
            [HelpCrunch bindTheme:[HelpCrunch defaultTheme]];
            break;
        case 1:
            [HelpCrunch bindTheme:[HelpCrunch darkTheme]];
            break;
        case 2:
            [self setCustomTheme];
            break;
        default:
            break;
    }
}

@end
