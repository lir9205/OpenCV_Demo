//
//  ViewController.m
//  LR_OpenCV_iOS_Demo
//
//  Created by admin on 2018/1/5.
//  Copyright © 2018年 lirui. All rights reserved.
//

#import "ViewController.h"
#import "OpenCVImageUtils.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)clickNormal:(id)sender {
    self.imageView.image = [UIImage imageNamed:@"image1.jpg"];
}


- (IBAction)clickWaterMark:(id)sender {
    UIImage *srcImage = [UIImage imageNamed:@"image1.jpg"];
    UIImage *dstImage = [UIImage imageNamed:@"image2.jpg"];
    self.imageView.image = [OpenCVImageUtils opencvImage:srcImage dst:dstImage];
}


@end
