//
//  OpenCVImageUtils.m
//  LR_OpenCV_iOS_Demo
//
//  Created by admin on 2018/1/5.
//  Copyright © 2018年 lirui. All rights reserved.
//

#import "OpenCVImageUtils.h"

@implementation OpenCVImageUtils

+ (UIImage *)opencvImage:(UIImage *)srcImage dst:(UIImage *)dstImage {
    //第一步：准备两张图片
    //imread 函数：读取文件, 返回一个 Mat 矩阵（是 OpenCV框架最基本数据类型）
    Mat mat_image_src;
    UIImageToMat(srcImage, mat_image_src);
    Mat mat_image_dst;
    UIImageToMat(dstImage, mat_image_dst);
    
    //第二步：创建叠加区域，开辟了一块内存空间
    Mat mat_roi = mat_image_src(Rect2i(0, 0, mat_image_dst.cols, mat_image_dst.rows));
    
    //第三步：图片叠加，加水印->合并之后覆盖原来的图片
    //参数一：第一个图片数组
    //参数二：第一个图片数组的权重为0
    //参数三：第二个图片数组
    //参数四：第二个图片数组的权重为1
    //参数五：权重和基础之上的标量值
    //参数六：输出的图片数组
    //dst = src1*alpha + src2*beta + gamma;
    //伪代码：mat_roi * 0 + mat_image_dst * 1 + 0
    addWeighted(mat_roi, 0, mat_image_dst, 1, 0, mat_roi);
    
    //第四步：将 Mat 图片转为 iOS 图片
    return MatToUIImage(mat_image_src);
}

@end
