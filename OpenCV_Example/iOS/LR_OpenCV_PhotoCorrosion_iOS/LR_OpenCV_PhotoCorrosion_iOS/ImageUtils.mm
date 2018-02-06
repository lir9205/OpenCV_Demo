
//
//  ImageUtils.m
//  LR_OpenCV_PhotoCorrosion_iOS
//
//  Created by admin on 2018/1/22.
//  Copyright © 2018年 lirui. All rights reserved.
//

#import "ImageUtils.h"

@implementation ImageUtils


+ (UIImage *)opencvImageErode:(UIImage *)srcImage {
    // 第一步：加载图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    
    // 第二步：进行腐蚀操作
    // 参数一: 腐蚀类型：矩形形式
    // 参数二：腐蚀大小：范围（腐蚀单位大小，单位是像素）-> 腐蚀程度大小
    Mat mat_element = getStructuringElement(MORPH_RECT, Size2i(10, 10));
    
    //开始腐蚀
    Mat mat_image_dst;
    // 参数一: 原始图片
    // 参数二：腐蚀之后的图片
    // 参数三：腐蚀范围（腐蚀单位大小）
    erode(mat_image_src, mat_image_dst, mat_element);
    
    //第三步：将 Mat 图片转为 iOS 图片
    return MatToUIImage(mat_image_dst);
}

+ (UIImage *)opencvImageBlur:(UIImage *)srcImage {
    // 第一步：加载图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);

    
    // 第二步：模糊图片
    Mat mat_image_dst;
    // 参数一: 原始图片
    // 参数二：模糊之后的图片
    // 参数三：模糊单位大小
    blur(mat_image_src, mat_image_dst, Size2i(10, 10));
    
    //第三步：将 Mat 图片转为 iOS 图片
    return MatToUIImage(mat_image_dst);
}

//+ (UIImage *)opencvImageCanny:(UIImage *)srcImage {
//    // 第一步：加载图片
//    Mat mat_image_src;
//    UIImageToMat(srcImage, mat_image_src);
//
//    // 第二步： 创建和mat_image_src同样大小的图片(Mat)
//    Mat mat_image_dst;
//    mat_image_dst.create(mat_image_src.size(), mat_image_src.type());
//
//    // 第三步：将图片进行灰度处理
//    Mat mat_image_gray;
//    cvtColor(mat_image_src, mat_image_gray, COLOR_BGR2GRAY);
//
//    // 第四步： 使用3*3内核来降噪处理
//    Mat mat_image_edge;
//    blur(mat_image_gray, mat_image_edge, Size2i(3,3));
//
//    // 第五步：进行算子处理
//    Canny(mat_image_edge, mat_image_edge, 3, 9, 3);
//
//
//    // 第六步：将 Mat 图片转为 iOS 图片
//    return MatToUIImage(mat_image_edge);
//}

#pragma mark - 图片处理组件

+ (UIImage *)opencvImageCanny:(UIImage *)srcImage {
    // 第一步：加载图片
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    
    // 在 iOS 平台，OpenCV支持单通道和3通道
    Mat mat_image_dst;
    // 将4个通道转成三个通道
    // 一般情况下是4个通道
    cvtColor(mat_image_src, mat_image_dst, CV_RGBA2RGB, 3);
    
   
    int value = 16;
    Mat mat_image_filter;
    //折中选择
    bilateralFilter(mat_image_dst, mat_image_filter, value, value * 2, value / 2);
    
    
    // 第六步：将 Mat 图片转为 iOS 图片
    return MatToUIImage(mat_image_filter);
}

@end
