
INSTALLATION

1. Add library to your project

1.1. Drag and drop files to your project:
- include/*
- libSpothillSDK.a
- SpothillSDKBundle.bundle

1.2. Add dependencies

CoreLocation.framework
CoreBluetooth.framework
MobileCoreServices.framework
SystemConfiguration.framework
Security.framework

1.3. Project Build Settings
"Enable Bitcode" set to "NO"
to "Other Linker Flags" add "-ObjC"

1.4. Create InfoPlist.strings file that is localized and add NSLocationAlwaysUsageDescription key, example:

NSLocationAlwaysUsageDescription = "Vaše polohové služby potřebujeme kvůli zobrazování kampaní pro Vás na základě výskytu při našem spotu.";

1.5.

enable "location" background mode

1.6. Add import where you want to use SDK
#import <SpothillSDK/SpothillSDK.h>


2. Add SDK to your AppDelegate

#import <SpothillSDK/SpothillSDK.h>


2.1. Setup SpothillSDKManager in your app delegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // app specific value provided by Neogenia s.r.o.
    SpothillSDKManager.sharedInstance.backend.providerHash = @"your provider hash";

    // change this value to production for release applications
    SpothillSDKManager.sharedInstance.backend.environment = SpothillSDKBackendEnvironmentBeta;


    // process local notification
    if (launchOptions[UIApplicationLaunchOptionsLocalNotificationKey]) {
        [self application:application didReceiveLocalNotification:launchOptions[UIApplicationLaunchOptionsLocalNotificationKey]];
    }

    [self registerForUserNotifications];

    return YES;
}

- (void)registerForUserNotifications {
    // this is for ios8+, ios7 allows local notifications without asking for permissions
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeSound categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
    }
}

// redirect local notification to SpothillSDKManager, it ignores notifications that weren't scheduled by SpothillSDK
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    [SpothillSDKManager.sharedInstance didReceiveLocalNotification:notification];
}


2.2. Register anonymous user for your app installation.

// after successful login SpothillSDK starts to work on background and you can listen to notifications

if (!SpothillSDKManager.sharedInstance.backend.isLoggedIn) {
    [SpothillSDKManager.sharedInstance.backend registerAnonymousUserWithCompletion:^(BOOL success, NSInteger statusCode) {
        if (success) {
            // api can be used now
        } else {
            // you have to try again
        }
    }];
}

2.3. Register user with params

	Data for the registration
	NSDictionary * data = @{
		@"sex": sex,
		@"name": name,	
		@"surname": surname,
		@"email": email,
		@"password": password,
		@"oldPassword": oldPass   // Only when you want to change the password
         };

Registration where is required to activate the account by the link from the email send to registration email
[SpothillSDKManager.sharedInstance.backend registerUserWithData:data loginMethod:loginMethod completion:^(BOOL success, NSInteger statusCode) {

Registration where you can skip the account activation 
[SpothillSDKManager.sharedInstance.backend registerUserWithData:data loginMethod:loginMethod skipActivation:<#(BOOL)#> completion:^(BOOL success, NSInteger statusCode) {

2.4. See ViewController.m in SpothillExample app for example of loading campaigns asociated with nearby beacons



