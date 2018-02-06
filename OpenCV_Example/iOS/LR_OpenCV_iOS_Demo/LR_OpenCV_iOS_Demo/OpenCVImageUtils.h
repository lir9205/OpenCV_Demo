//
//  OpenCVImageUtils.h
//  LR_OpenCV_iOS_Demo
//
//  Created by admin on 2018/1/5.
//  Copyright © 2018年 lirui. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
// 支持 iOS 平台图片转换
#include <opencv2/imgcodecs/ios.h>

using namespace cv;

@interface OpenCVImageUtils : NSObject

+ (UIImage *)opencvImage:(UIImage *)srcImage dst:(UIImage *)dstImage;

@end

