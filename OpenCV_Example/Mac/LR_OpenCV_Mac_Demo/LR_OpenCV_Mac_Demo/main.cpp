//
//  main.cpp
//  LR_OpenCV_Mac_Demo
//
//  Created by admin on 2018/1/4.
//  Copyright © 2018年 lirui. All rights reserved.
//

//#include <iostream>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

//案例一：测试用例
//int main( int argc, char** argv ){
//    string imageName("/Users/admin/Desktop/2.jpg"); // by default
//    if( argc > 1) {
//        imageName = argv[1];
//    }
//    Mat image;
//    image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
//    if( image.empty() ){
//        cout <<  "Could not open or find the image" << std::endl ;
//        return -1;
//    }
//    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
//    imshow( "Display window", image );                // Show our image inside it.
//    waitKey(0); // Wait for a keystroke in the window
//
//    return 0;
//}

//案例二：两张图片叠加
//注意事项：两张叠加，必须有一张图片大于另外一张图片
//类似于给我们的图片打水印
int main( int argc, char** argv ){

    //第一步：准备两张图片
    //imread 函数：读取文件, 返回一个 Mat 矩阵（是 OpenCV框架最基本数据类型）
    Mat mat_image_src = imread("/Users/admin/Desktop/1.jpg");
    Mat mat_image_dst = imread("/Users/admin/Desktop/2.jpg");

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

    //第四步：显示图片
    namedWindow("叠加图片");
    imshow("叠加图片", mat_image_src);

    //第五步：窗口暂停 -> 等待状态
    waitKey();

    return 0;
}

//案例三：图片叠加输出一张新的图片
//int main( int argc, char** argv ){
//
//    //第一步：准备两张图片
//    //imread 函数：读取文件, 返回一个 Mat 矩阵（是 OpenCV框架最基本数据类型）
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//    Mat mat_image_dst = imread("/Users/admin/Desktop/image2.jpg");
//
//    //第二步：创建叠加区域，开辟了一块内存空间
//    Mat mat_roi = mat_image_src(Rect2i(0, 0, mat_image_dst.cols, mat_image_dst.rows));
//
//    //第三步：图片叠加，加水印->合并之后覆盖原来的图片
//    //参数一：第一个图片数组
//    //参数二：第一个图片数组的权重为0
//    //参数三：第二个图片数组
//    //参数四：第二个图片数组的权重为1
//    //参数五：权重和基础之上的标量值
//    //参数六：输出的图片数组
//    //dst = src1*alpha + src2*beta + gamma;
//    //伪代码：mat_roi * 0 + mat_image_dst * 1 + 0
//    addWeighted(mat_roi, 0, mat_image_dst, 1, 0, mat_roi);
//
//    //第四步：输出图片
//    imwrite("/Users/admin/Desktop/3.jpg", mat_image_src);
//
//    return 0;
//}

