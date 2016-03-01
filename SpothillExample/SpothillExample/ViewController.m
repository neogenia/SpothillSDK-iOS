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

    [NSTimer scheduledTimerWithTimeInterval:5 target:self selector:@selector(simulateBeaconsRanging) userInfo:nil repeats:YES];
    
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

- (void)simulateBeaconsRanging {
    
    // simlate that some beacons have been found
    [SpothillSDKManager.sharedInstance.beaconManager testRangingOfBeaconWithMinor:100 mayor:1 accuracy:20];
    for (int i=1; i < 6; i++) {
        [SpothillSDKManager.sharedInstance.beaconManager testRangingOfBeaconWithMinor:i mayor:1 accuracy:20];
    }
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
