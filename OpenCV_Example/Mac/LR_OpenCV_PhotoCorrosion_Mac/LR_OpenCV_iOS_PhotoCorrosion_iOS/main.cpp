//
//  main.cpp
//  LR_OpenCV_iOS_PhotoCorrosion_iOS
//
//  Created by admin on 2018/1/6.
//  Copyright © 2018年 lirui. All rights reserved.
//


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

//// 案例一：图片腐蚀效果
//int main(int argc, const char * argv[]) {
//
//    // 第一步：加载图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    // 第二步：进行腐蚀操作
//    // 参数一: 腐蚀类型：矩形形式
//    // 参数二：腐蚀大小：范围（腐蚀单位大小，单位是像素）-> 腐蚀程度大小
//    Mat mat_element = getStructuringElement(MORPH_RECT, Size(8, 8));
//
//    //开始腐蚀
//    Mat mat_image_dst;
//    // 参数一: 原始图片
//    // 参数二：腐蚀之后的图片
//    // 参数三：腐蚀范围（腐蚀单位大小）
//    erode(mat_image_src, mat_image_dst, mat_element);
//
//    //第三步：显示图片
//    imshow("图片腐蚀",  mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//// 案例二：图片模糊效果
//int main(int argc, const char * argv[]) {
//
//    // 第一步：加载图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    // 第二步：模糊图片
//    Mat mat_image_dst;
//    // 参数一: 原始图片
//    // 参数二：模糊之后的图片
//    // 参数三：模糊单位大小
//    blur(mat_image_src, mat_image_dst, Size(10, 10));
//
//    //第三步：显示图片
//    imshow("图片模糊",  mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//// 案例三：图片边缘检测 -> 图片轮廓
//int main(int argc, const char * argv[]) {
//
//    // 第一步：加载图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
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
//    blur(mat_image_gray, mat_image_edge, Size(3,3));
//
//    // 第五步：进行算子处理
//    Canny(mat_image_edge, mat_image_edge, 3, 9, 3);
//
//    // 第六步：显示图片
//    imshow("边缘检测",  mat_image_edge);
//    waitKey();
//
//    return 0;
//}

// 案例三：图片边缘检测 -> 图片轮廓
int main(int argc, const char * argv[]) {

    // 第一步：加载图片
    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");

    // 第二步： 创建和mat_image_src同样大小的图片(Mat)
    Mat mat_image_dst;
    mat_image_dst.create(mat_image_src.size(), mat_image_src.type());

    // 第三步：将图片进行灰度处理
    Mat mat_image_gray;
    cvtColor(mat_image_src, mat_image_gray, COLOR_BGR2GRAY);

    // 第四步： 使用3*3内核来降噪处理
    Mat mat_image_edge;
    blur(mat_image_gray, mat_image_edge, Size(3,3));

    // 第五步：进行算子处理
    Canny(mat_image_edge, mat_image_edge, 3, 9, 3);

    // 第六步：显示图片
    imshow("边缘检测",  mat_image_edge);
    waitKey();

    return 0;
}



