//
//  ImageUtils.h
//  LR_OpenCV_PhotoCorrosion_iOS
//
//  Created by admin on 2018/1/22.
//  Copyright © 2018年 lirui. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/ios.h>

using namespace cv;
using namespace std;

@interface ImageUtils : NSObject

/**
 图片腐蚀
 */
+ (UIImage *)opencvImageErode:(UIImage *)srcImage;


/**
 图片模糊
 */
+ (UIImage *)opencvImageBlur:(UIImage *)srcImage;


/**
 图片边缘检测 -> 图片轮廓
 */
+ (UIImage *)opencvImageCanny:(UIImage *)srcImage;



















@end
