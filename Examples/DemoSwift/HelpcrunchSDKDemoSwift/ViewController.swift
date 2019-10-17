import UIKit
import HelpCrunchSDK

class ViewController: UIViewController {
    
    @IBOutlet weak var launchButton: UIButton!
    @IBOutlet weak var logoutButton: UIButton!
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var preformSwitch: UISwitch!
    
    // MARK: - View methods
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.selectRow(at: IndexPath(row: 0, section: 0),
                            animated: false,
                            scrollPosition: .none)
        
        let configuration = HelpCrunch.configuration()
        configuration?.isBrandingEnabled = true
        preformSwitch.isOn = configuration?.userAttributes != nil
        
        NotificationCenter.default.addObserver(self,
                                               selector: #selector(updateLaunchButton),
                                               name: NSNotification.Name.HCSUnreadMessages,
                                               object: nil)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        updateLaunchButton()
    }

    @objc func updateLaunchButton() {
        if HelpCrunch.numberOfUnreadMessages() > 0 {
            launchButton.setTitle("Launch chat (\(HelpCrunch.numberOfUnreadMessages()) unread)", for: .normal)
        } else {
            launchButton.setTitle("Launch chat", for: .normal)
        }
    }
    
    func setCustomTheme() {
        let theme = HelpCrunch.defaultTheme()!
        
        theme.mainColor = UIColor(red: 0.90, green: 0.51, blue: 0.15, alpha: 1.0)
        theme.sendButtonText = "Send";

        HelpCrunch.bindTheme(theme)
    }
    
    // MARK: - IBActions

    @IBAction func preformSwitchChanged(_ sender: Any) {
        let configuration = HelpCrunch.configuration()
        
        guard preformSwitch.isOn == true else {
            configuration?.userAttributes = nil;
            
            return
        }
        
        configuration?.userAttributes = [HCSUserAttribute.nameAttribute(asRequired: true),
                                         HCSUserAttribute.emailAttribute(asRequired: false),
                                         HCSUserAttribute(attributeName: "My custom attribute",
                                                          placeholder: "Enter something",
                                                          required: true)]
    }
    
    @IBAction func buttonLaunchTouched(_ sender: UIButton) {
        HelpCrunch.show(from: self) { (error) in
            print("HelpCrunch is on screen")
        }
    }

    @IBAction func buttonLogoutTouched(_ sender: UIButton) {
        view.isUserInteractionEnabled = false
        
        sender.isEnabled = true
        sender.setTitle("Please wait", for: .normal)
        
        HelpCrunch.logout { (error) in
            self.view.isUserInteractionEnabled = true
            
            sender.isEnabled = false
            sender.setTitle("Logout", for: .normal)
        }
    }
}

extension ViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 3
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let identifier: String = "themeCell"
    
        var cell = tableView.dequeueReusableCell(withIdentifier: identifier)
        
        if cell == nil {
            cell = UITableViewCell(style: .default, reuseIdentifier: identifier)
        }
        
        switch indexPath.row {
        case 0:
            cell?.textLabel?.text = "Light theme"
        case 1:
            cell?.textLabel?.text = "Dark theme"
        case 2:
            cell?.textLabel?.text = "Custom theme"
        default:
            break;
        }
        
        return cell!
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch indexPath.row {
        case 0:
            HelpCrunch.bindTheme(HelpCrunch.defaultTheme())
        case 1:
            HelpCrunch.bindTheme(HelpCrunch.darkTheme())
        case 2:
            setCustomTheme()
        default:
            break;
        }
    }
}
