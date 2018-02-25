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
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/ios.h>

using namespace cv;
using namespace std;

@interface ImageUtils : NSObject

//图像组件
//第六点：线性滤波核心函数->案例
///1、方框滤波->boxFilter()函数
+ (UIImage *)opencvImageBoxFilter:(UIImage *)srcImage;


///2、均值滤波->blur()函数
+ (UIImage *)opencvImageBlur:(UIImage *)srcImage;


///3、高斯滤波->GaussianBlur()函数
+ (UIImage *)opencvImageGaussianBlur:(UIImage *)srcImage;

//第八点：非线性滤波->核心函数->案例
///1、中值滤波 -> medianBlur() 函数
+ (UIImage *)opencvImageMedianBlur:(UIImage *)srcImage;

///2、双边滤波 -> bilateralFilter()函数 -> 美颜处理
+ (UIImage *)opencvImageBilateralFilter:(UIImage *)srcImage;


//第九点：形态学滤波
///1、膨胀：求局部最大值操作
+ (UIImage *)opencvImageDilate:(UIImage *)srcImage;

///2、腐蚀：求局部最小值操作
+ (UIImage *)opencvImageErode:(UIImage *)srcImage;

//3、 核心API 函数：morphologyEx()
+ (UIImage *)opencvImageMorphologyEx:(UIImage *)srcImage;


// 第十点：漫水填充 -> floodFill()
+ (UIImage *)opencvImageFloodFill:(UIImage *)srcImage;

//// 第十一点：图片高质量压缩
+ (UIImage *)opencvImageCVSaveImage:(UIImage *)srcImage;

// 第十二点：图像金字塔和图片尺寸缩放
//2、图片尺寸缩放->resize()函数
+ (UIImage *)opencvImageResize:(UIImage *)srcImage;

//图像变换
//1、基于OpenCV边缘检测
+ (UIImage *)opencvImageCanny:(UIImage *)srcImage;
//2、霍夫变换
+ (UIImage *)opencvImageHoughLinesP:(UIImage *)srcImage;



@end
