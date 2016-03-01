
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


1.5. Add import where you want to use SDK
#import <SpothillSDK/SpothillSDK.h>


2. Add SDK to your AppDelegate

#import <SpothillSDK/SpothillSDK.h>


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    SpothillSDKManager.sharedInstance.backend.providerHash = @"your provider hash";

    if (!SpothillSDKManager.sharedInstance.backend.isLoggedIn) {
        [SpothillSDKManager.sharedInstance.backend registerAnonymousUserWithCompletion:^(BOOL success, NSInteger statusCode) {
            if (success) {
                // api can be used now
            } else {
                // you have to try again
            }
        }];
    }


}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    [SpothillSDKManager.sharedInstance didReceiveLocalNotification:notification];
}

3. Example: load nearby campaigns to a simple UITableViewController and allow to switch favorite flag

//
//  ViewController.m
//  SpothillExample
//
//  Created by Martin Krivus on 09/02/16.
//  Copyright © 2016 Martin Krivus. All rights reserved.
//

#import "ViewController.h"

#import <SpothillSDK/SpothillSDK.h>


@interface ViewController () <UITableViewDataSource, UITableViewDelegate>

@property (strong, nonatomic) IBOutlet UITableView *tableView;
@property (strong, nonatomic) NSArray *campaigns;

@end

@implementation ViewController

- (void)viewDidLoad {
[super viewDidLoad];

self.title = NSLocalizedString(@"Nearby Campaigns", nil);

// simlate that some beacons have been found
dispatch_async(dispatch_get_main_queue(), ^{
[SpothillSDKManager.sharedInstance.beaconManager testRangingOfBeaconWithMinor:100 mayor:1 accuracy:20];
for (int i=1; i < 6; i++) {
[SpothillSDKManager.sharedInstance.beaconManager testRangingOfBeaconWithMinor:i mayor:1 accuracy:20];
}

});

[self loadCampaigns];
}

- (void)viewWillAppear:(BOOL)animated {
[super viewWillAppear:animated];

[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(loadCampaigns) name:cSpothillSDKNewNearbyCampaingsDidLoad object:nil];
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(loadCampaigns) name:cSpothillSDKBackendUserDidLogin object:nil];

[self loadCampaigns];
}

- (void)viewWillDisappear:(BOOL)animated {
[super viewWillDisappear:animated];

[[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)loadCampaigns {
NSArray *campaigns = [SpothillSDKManager.sharedInstance.cache dataForListType:CampaignListTypeNearbyCampaigns];

self.campaigns = campaigns;
[self.tableView reloadData];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
return self.campaigns.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
static NSString *identifier = @"campaignCell";
UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
if (!cell) {
cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:identifier];
}

SpothillSDKCampaign *campaign = [self.campaigns objectAtIndex:indexPath.row];
cell.textLabel.text = campaign.title;
cell.detailTextLabel.text = campaign.desc;

cell.accessoryType = UITableViewCellAccessoryDetailDisclosureButton;

return cell;
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
SpothillSDKCampaign *campaign = [self.campaigns objectAtIndex:indexPath.row];
if (campaign.favourite) {
cell.backgroundColor = [UIColor greenColor];
} else {
cell.backgroundColor = [UIColor whiteColor];
}
}

- (void)tableView:(UITableView *)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath {
SpothillSDKCampaign *campaign = [self.campaigns objectAtIndex:indexPath.row];
SpothillSDKSpotDetailViewController *vc = [SpothillSDKSpotDetailViewController spotDetailViewControllerWithCampaign:campaign];

[self.navigationController pushViewController:vc animated:YES];
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
SpothillSDKCampaign *campaign = [self.campaigns objectAtIndex:indexPath.row];
__weak ViewController *weakSelf = self;
[campaign toggleFavouriteWithCompletion:^(BOOL success) {
[weakSelf.tableView reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
}];
}

@end







