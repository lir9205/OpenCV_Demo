//
//  main.cpp
//  LR_OpenCV_Function_Mac
//
//  Created by admin on 2018/1/25.
//  Copyright © 2018年 lirui. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


#define WINDOWS_WIDTH 240


#pragma mark - 绘制集合图形
//绘制椭圆
void drawElipse(Mat &mat_image, double angle) {
    //参数一：图片（画板）
    //参数二：中心点
    //参数三：轴大小（主轴大小）->半径
    //参数四：旋转角度
    //参数五：起始角度
    //参数六：结束角度
    //参数七：椭圆颜色
    //参数八：类型（如果小于表示实心圆、如果大于等于0表示空心圆）
    //如果这个大于0的，那么椭圆外围线大小
    ellipse(mat_image,
            Point2i(WINDOWS_WIDTH/2, WINDOWS_WIDTH/2),
            Size2i(WINDOWS_WIDTH/4, WINDOWS_WIDTH/16),
            angle, 0, 360,
            Scalar(0, 0, 255), -1);
}

//绘制圆
void drawCircle(Mat &mat_image, Point2i center) {
    //参数一：图片（画板）
    //参数二：中心点
    //参数三：半径
    //参数四：圆的颜色
    //参数五：类型（如果小于表示实心圆、如果大于等于0表示空心圆）
    //如果这个大于0的，那么椭圆外围线大小
    circle(mat_image, center, WINDOWS_WIDTH/4, Scalar(0, 0, 255), 5);
}

//int main(int argc, const char * argv[]) {
//    //第一步：创建一张图片->空白图片
////    Mat mat_image = Mat::zeros(WINDOWS_WIDTH, WINDOWS_WIDTH, CV_8UC3);
//
//    Mat mat_image(WINDOWS_WIDTH, WINDOWS_WIDTH, CV_8UC3, Scalar(255,255,255));
//
//    //第二步：给我们的图绘制集合图形
////    drawElipse(mat_image, 0);
//    drawCircle(mat_image, Point2i(WINDOWS_WIDTH/2, WINDOWS_WIDTH/2));
//
//
//    //第三步：显示图片
//    namedWindow("绘图");
//    imshow("图片",  mat_image);
//    waitKey();
//
//    return 0;
//}


#pragma mark - 颜色空间缩减
//void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div);
//
//int main(int argc, const char * argv[]) {
//    //第一步：创建一张图片->空白图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //第二步：按照原图创建一张新的图片
//    Mat mat_image_dst;
//    mat_image_dst.create(mat_image_src.rows,
//                         mat_image_src.cols,
//                         mat_image_src.type());
//
//    //记录开始时间
//    //getTickCount()函数表示：返回CPU自某个事件以来走过的时间周期数(纳秒，非常小的时间单位)
//    //例如：电脑启动、电脑休眠等等...
//    double time_start = static_cast<double>(getTickCount());
//
//    //第三步：颜色空间缩减
//    colorSpaceReduce(mat_image_src, mat_image_dst, 24);
//
//    //记录结束时间
//    double time_end = static_cast<double>(getTickCount());
//    //getTickFrequency()函数表示：返回CPU一秒钟所有的时间周期数，这样的话是不是我就能够按照秒单位计算出耗时
//    double time = (time_end - time_start) / getTickFrequency();
//
//    printf("耗时 %f 秒", time);
//
//    //第三步：显示图片
//    namedWindow("绘图");
//    imshow("图片",  mat_image_dst);
//    waitKey();
//
//    return 0;
//}

//访问图像像素有三大类方式
////第一类：指针访问
////耗时 0.002290 秒 = 2.29毫秒
//void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div) {
//    mat_image_out = mat_image_in.clone();
//    int rows = mat_image_out.rows;
//    int cols = mat_image_out.cols;
//    //通道数量->2种颜色，3种颜色（每一个像素点，有多少个颜色）
//    int channels = mat_image_out.channels();
//    //获取每一行元素个数 -> RGB 个数
//    int colsSize = cols * channels;
//
//    //循环缩减颜色通道
//    for (int i = 0; i < rows; i++) {
//        //获取第i行->指针访问像素点
//        uchar *data = mat_image_out.ptr<uchar>(i);
//
//        for (int j = 0; j < colsSize; j++) {
//            //指针位移
//            //data[j]->表示一个颜色值
//            //data[j] = 100
//            //div = 24
//            //data[j] = 100 / 24 * 24 = 96
//            //data[j] = 96 + 24 / 2 = 108
//            //这只是一个公式而已(随便你改)->想怎么玩就怎么玩->随心所欲
//            //data[j] = data[j]/div * div + div/2;
//            data[j] = data[j]/div * div;
//        }
//    }
//}


////第二类：迭代器访问->封装东西比较多(根据场景选择使用)
////耗时 0.007287 秒 = 7.287毫秒
//void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div) {
//    mat_image_out = mat_image_in.clone();
//
//    Mat_<Vec3b>::iterator it_start = mat_image_out.begin<Vec3b>();
//    Mat_<Vec3b>::iterator it_end = mat_image_out.end<Vec3b>();
//
//    //循环缩减颜色通道
//    for (; it_start != it_end; it_start++) {
//        //(*it_start) 表示一个像素点
//        //(*it_start)[0] 表示一个像素点的第一个通道值 -> 蓝色 B值
//        (*it_start)[0] = (*it_start)[0] / div * div;
//        (*it_start)[1] = (*it_start)[1] / div * div;
//        (*it_start)[2] = (*it_start)[2] / div * div;
//    }
//}

//第三类：动态地址计算
//耗时 0.005482 秒 = 5.482毫秒
void colorSpaceReduce(Mat &mat_image_in, Mat &mat_image_out, int div) {
    mat_image_out = mat_image_in.clone();
    int rows = mat_image_out.rows;
    int cols = mat_image_out.cols;
    
    //循环缩减颜色通道
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat_image_out.at<Vec3b>(i, j)[0] = mat_image_out.at<Vec3b>(i, j)[0] / div * div;
            mat_image_out.at<Vec3b>(i, j)[1] = mat_image_out.at<Vec3b>(i, j)[1] / div * div;
            mat_image_out.at<Vec3b>(i, j)[2] = mat_image_out.at<Vec3b>(i, j)[2] / div * div;
        }
    }
}


#pragma mark - ROI感兴趣区域

//通过ROI感兴趣区域实现图片叠加
//int main(int argc, const char * argv[]) {
//    //第一步：创建一张图片->空白图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//    Mat mat_image_logo = imread("/Users/admin/Desktop/image2.jpg");
//
//    //第二步：灰度处理 -> 加载一张灰度图片
//    Mat mat_image_mask = imread("/Users/admin/Desktop/image2.jpg");
//
//    //第三步：定义 ROI 区域
//    //根据原始图片 -> 得到 src 图片一块内存地址（指针）
//    Mat mat_image_roi = mat_image_src(Rect2i(50, 50, mat_image_logo.cols, mat_image_logo.rows));
//
//    //第三步：拷贝到ROI区域
//    //参数一：ROI区域
//    //参数二：需要填充图片(水印)
//    mat_image_logo.copyTo(mat_image_roi, mat_image_mask);
//
//    //第四步：显示图片
//    namedWindow("图片");
//    imshow("图片",  mat_image_src);
//    waitKey();
//
//    return 0;
//}


//计算数组加权和实现图片叠加
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
//    //第四步：显示图片
//    namedWindow("叠加图片");
//    imshow("叠加图片", mat_image_src);
//
//    //第五步：窗口暂停 -> 等待状态
//    waitKey();
//
//    return 0;
//}


#pragma mark - 核心组件->Core组件
//1、颜色通道分离 -> split()函数
//int main(int argc, const char * argv[]) {
//    //第一步：读取图片
//    Mat mat_image = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //第二步：分离通道 -> 字符串分隔
//    //参数一：原始图片 -> RGB 彩色图片 -> 多通道
//    //参数二：目标图片 -> 数组
//    vector<Mat> channels;
//    split(mat_image, channels);
//
//    //获取蓝色通道 -> 单通道 -> 灰度图片（图片亮度不一样，灰度成都不一样）
//    Mat mat_image_blue = channels.at(0);
//    //获取绿色通道
//    Mat mat_image_green = channels.at(1);
//    //获取红色通道
//    Mat mat_image_red = channels.at(2);
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_red);
//    waitKey();
//
//    return 0;
//}


////2、颜色通道合并 -> merge()函数
//int main(int argc, const char * argv[]) {
//    //第一步：读取图片
//    Mat mat_image = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //第二步：分离通道 -> 字符串分隔
//    //参数一：原始图片 -> RGB 彩色图片 -> 多通道
//    //参数二：目标图片 -> 数组
//    vector<Mat> channels;
//    split(mat_image, channels);
//
//    //获取蓝色通道 -> 单通道 -> 灰度图片（图片亮度不一样，灰度程度不一样）
//    Mat mat_image_blue = channels.at(0);
//    //获取绿色通道
//    Mat mat_image_green = channels.at(1);
//    //获取红色通道
//    Mat mat_image_red = channels.at(2);
//
//
//    //通道合并
//    //参数一：原始数组 -> 通道数组
//    Mat mat_image_dst;
//    merge(channels, mat_image_dst);
//
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}

//3、多通道图像混合
////对两种图片进行叠加
////图片A->彩色图片
////图片B->彩色图片
////叠加->图片B是->图片B的某一个通道进行叠加
//void channelOverlaying(Mat &mat_image_src, Mat &mat_image_logo, int channelIndex) {
//    vector<Mat> channels;
//    split(mat_image_src, channels);
//
//    //获取指定通道
//    // 注意：mat_image_channel 是一个引用，当它发生改变的时候，那么我们集合中元素也会发生改变
//    Mat mat_image_channel = channels.at(channelIndex);
//
//    //获取叠加区域 -> ROI
//    Mat mat_image_roi = mat_image_channel(Rect2i(0, 0, mat_image_logo.cols, mat_image_logo.rows));
//
//    //通过加权函数进行叠加图片
//    //将 logo 添加到原图的某个通道上
//    addWeighted(mat_image_roi, 0, mat_image_logo, 1, 0, mat_image_roi);
//
//    //合并通道
//    merge(channels, mat_image_src);
//}
//
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//    //参数二：单通道，必须写，否则程序会报错
//    Mat mat_image_logo = imread("/Users/admin/Desktop/image2.jpg", 0);
//
//
//    channelOverlaying(mat_image_src, mat_image_logo, 2);
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_src);
//    waitKey();
//
//    return 0;
//}

//4、图像对比度和亮度值调整？
//4.1 什么是对比度？
//答案：对比度指的是一幅图像中明暗区域最亮的白和最暗的黑之间不同亮度层级的测量，差异范围越大代表对比越大，差异范围越小代表对比越小，好的对比率120:1就可容易地显示生动、丰富的色彩，当对比率高达300:1时，便可支持各阶的颜色。但对比率遭受和亮度相同的困境，现今尚无一套有效又公正的标准来衡量对比率，所以最好的辨识方式还是依靠使用者眼睛。
//4.2 如何计算对比度和亮度结果图片？
//公式：g(x) = a * f(x) + b;->标准对比度和亮度计算公式
//每一个像素点，每一个颜色值都需要按照这个公式进行计算
//g(x)->表示输出图片->结果图片(调整对比度和亮度之后的图片)
//a->表示对比度,是百分比
//f(x)->表示原始图片
//b->表示亮度
//根据以上算法->推导出一个新的算法结构->获取像素点
//g(i, j) = a * f(i, j) + b;
//i表示第几行
//j表示第几列
//获取像素点
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    int rows = mat_image_src.rows;
//    int cols = mat_image_src.cols;
//    //  访问像素点 -> 获取颜色值
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            mat_image_src.at<Vec3b>(i, j)[0] = mat_image_src.at<Vec3b>(i, j)[0];
//            mat_image_src.at<Vec3b>(i, j)[1] = mat_image_src.at<Vec3b>(i, j)[1];
//            mat_image_src.at<Vec3b>(i, j)[2] = mat_image_src.at<Vec3b>(i, j)[2];
//        }
//    }
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_src);
//    waitKey();
//
//    return 0;
//}


//实现功能
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    int rows = mat_image_src.rows;
//    int cols = mat_image_src.cols;
//    //  访问像素点 -> 获取颜色值
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            // g(i,j) = a * f(i,j) + b;
//            // mat_image_src.at<Vec3b>(i, j)[0] 相当于 g(i,j)
//            // 对比度（百分比） ，值越小，黑的部分占比越重
//            mat_image_src.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(80 * 0.01 * mat_image_src.at<Vec3b>(i, j)[0] + 50);
//            mat_image_src.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(80 * 0.01 * mat_image_src.at<Vec3b>(i, j)[1] + 50);
//            mat_image_src.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(80 * 0.01 * mat_image_src.at<Vec3b>(i, j)[2] + 50);
//        }
//    }
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_src);
//    waitKey();
//
//    return 0;
//}


