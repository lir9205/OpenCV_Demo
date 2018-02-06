//
//  ViewController.m
//  LR_OpenCV_PhotoCorrosion_iOS
//
//  Created by admin on 2018/1/22.
//  Copyright © 2018年 lirui. All rights reserved.
//

#import "ViewController.h"
#import "ImageUtils.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (IBAction)clickNormal:(id)sender {

    self.imageView.image = [UIImage imageNamed:@"image1.jpeg"];

}


- (IBAction)clickWaterMark:(id)sender {

    UIImage *srcImage = [UIImage imageNamed:@"image1.jpeg"];
    self.imageView.image = [ImageUtils opencvImageCanny:srcImage];
}


@end
