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
    
    //第六点：线性滤波核心函数->案例
    //1、方框滤波->boxFilter()函数
    //self.imageView.image = [ImageUtils opencvImageBoxFilter:srcImage];
    //2、均值滤波->blur()函数
    //self.imageView.image = [ImageUtils opencvImageBlur:srcImage];
    //3、高斯滤波->GaussianBlur()函数
    //self.imageView.image = [ImageUtils opencvImageGaussianBlur:srcImage];
    
    //第八点：非线性滤波->核心函数->案例
    //1、中值滤波 -> medianBlur() 函数
    //self.imageView.image = [ImageUtils opencvImageMedianBlur:srcImage];
    //2、双边滤波 -> bilateralFilter()函数 -> 美颜处理
    //self.imageView.image = [ImageUtils opencvImageBilateralFilter:srcImage];
    
    //第九点：形态学滤波
    //1、膨胀：求局部最大值操作
    //self.imageView.image = [ImageUtils opencvImageDilate:srcImage];
    //2、腐蚀：求局部最小值操作
    self.imageView.image = [ImageUtils opencvImageErode:srcImage];
}


@end
