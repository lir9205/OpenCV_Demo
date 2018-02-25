//
//  main.cpp
//  LR_OpenCV_Core_ImgProc_Mac
//
//  Created by admin on 2018/1/25.
//  Copyright © 2018年 lirui. All rights reserved.
//

#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#pragma mark - 图像组件->imgproc组件（image process）

//第六点：线性滤波核心函数->案例
////1、方框滤波->boxFilter()函数
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //参数一：原始图片
//    //参数二：目标图片
//    //参数三：输出图片深度(位深度：8位、16位、24位、32位、64位等等...)
//    //默认值：-1表示采用图片原始深度，类似于这个mat_image_src.depth()函数
//    Mat mat_image_dst;
//    //参数四：内"核"大小->Size2i(width, height)->一块区域->参照范围
//    //参数五：Point2i(-1, -1)表示锚点（锚点：被平滑的那个点）
//    //默认值就是Point2i(-1, -1)表示含义->如果这个值是负数，表示取"核"的中心点为锚点
//    //例如：Size2i(10, 10)，那么参数五为Point2i(-1, -1)，结果我们的锚点为Point2i(5, 5)
//    //参数六：bool值表示->默认值为true，表示内核是否被其他区域归一化
//    //参数七：用于推断图像的外部像素某种边界模式->一般都是默认值
//
//    boxFilter(mat_image_src, mat_image_dst, -1, Size2i(10, 10));
//
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//2、均值滤波->blur()函数
////均值滤波blur() 调用了方框滤波boxFilter()
////只是参数不一样，第三个参数图片深度传的-1；均值滤波是方框滤波的一种。
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //参数一：原始图片
//    //参数二：目标图片
//    Mat mat_image_dst;
//    //参数三：内"核"大小->Size2i(width, height)->一块区域->参照范围
//    //参数四：Point2i(-1, -1)表示锚点（锚点：被平滑的那个点）
//    //默认值就是Point2i(-1, -1)表示含义->如果这个值是负数，表示取"核"的中心点为锚点
//    //例如：Size2i(10, 10)，那么参数五为Point2i(-1, -1)，结果我们的锚点为Point2i(5, 5)
//    //参数五：用于推断图像的外部像素某种边界模式->一般都是默认值
//    blur(mat_image_src, mat_image_dst, Size2i(10,10));
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//3、高斯滤波->GaussianBlur()函数
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //参数一：原始图片
//    //参数二：目标图片
//    Mat mat_image_dst;
//    //参数三：内"核"大小->Size2i(width, height)->一块区域->参照范围
//    //注意：核大小必须是奇数，(ksize.width > 0 && ksize.width % 2 == 1 && ksize.height > 0 && ksize.height % 2 == 1)
//    //例如：3、5、7、9、11、13、15...
//    //参数四：高斯函数在 X 方向上标准偏差
//    //参数五：高斯函数在 Y 方向上标准偏差
//    //参数六：用于推断图像的外部像素某种边界模式->一般都是默认值
//    GaussianBlur(mat_image_src, mat_image_dst, Size2i(15, 15), 0, 0);
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}


////第八点：非线性滤波->核心函数->案例
////1、中值滤波 -> medianBlur() 函数
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //参数一：原始图片
//    //参数二：目标图片
//    Mat mat_image_dst;
//    //参数三：孔径的线性尺寸（注意：参数必须是大于等于1，并且是奇数，例如：3、5、7、9、11...）
//    medianBlur(mat_image_src, mat_image_dst, 5);
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//2、双边滤波 -> bilateralFilter()函数 -> 美颜处理
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    Mat mat_image_dst;
//    //参数一：原始图片
//    //参数二：目标图片
//    //参数三（d）: 表示过滤过程中每个像素领域的直径，
//    //如果这个值被设置为非正数，那么OpenCV框架会从第五个参数(sigmaSpace)计算出这个值
//    //参数四(sigmaColor)：颜色空间滤波器的sigma值
//    //这个参数值越大，就表明该像素邻域内有越宽广的颜色会被混合到一起
//    //参数五(sigmaSpace)：坐标空间中滤波器的sigma值，坐标空间的标注方差。
//    //它的值越大，意味着越远像素会相互影响，从而使更大的区域中足够相似的颜色获取相同的颜色。
//    //当d>0时，d指定了领域大小且与sigmaSpace无关，否则，d正比于sigmaSpace
//    //参数六：用于推断图像外部像素的某种边界模式，一般采用默认值
//    //双边滤波算法->研究算法
//    //一般图片->权衡调整->相对比较平均
//    int value = 16;
//    //折中选择
//    bilateralFilter(mat_image_src, mat_image_dst, value, value * 2, value / 2);
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//第九点：形态学滤波
////1、膨胀：求局部最大值操作
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//    //参数一：核类型（样式）
//    //MORPH_RECT:矩形
//    //MORPH_CROSS:交叉形(十字架,"+")
//    //MORPH_ELLIPSE:椭圆形
//    // 参数二：核大小
//    Mat mat_element = getStructuringElement(MORPH_CROSS, Size2i(10, 10));
//
//    Mat mat_image_dst;
//    //参数一：原始图片
//    //参数二：目标图片
//    //参数三：核
//    //参数四：锚的位置->默认位置Point2i(-1, -1)
//    //参数五：迭代使用
//    //例如：1表示调用一次dilate函数，2表示调用两次dilate函数，以此类推...
//    //参数六：用于推断图像外部像素的某种边界模式，一般采用默认值
//    dilate(mat_image_src, mat_image_dst, mat_element);
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}



////2、腐蚀：求局部最小值操作
//int main(int argc, const char * argv[]) {
//    //第一步：加载一张图片
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//    //参数一：核类型（样式）
//    //MORPH_RECT:矩形
//    //MORPH_CROSS:交叉形(十字架,"+")
//    //MORPH_ELLIPSE:椭圆形
//    // 参数二：核大小
//    Mat mat_element = getStructuringElement(MORPH_CROSS, Size2i(10, 10));
//
//    Mat mat_image_dst;
//    //参数一：原始图片
//    //参数二：目标图片
//    //参数三：核
//    //参数四：锚的位置->默认位置Point2i(-1, -1)
//    //参数五：迭代使用
//    //例如：1表示调用一次dilate函数，2表示调用两次dilate函数，以此类推...
//    //参数六：用于推断图像外部像素的某种边界模式，一般采用默认值
//    erode(mat_image_src, mat_image_dst, mat_element);
//
//    namedWindow("图片显示");
//    imshow("图片显示", mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//3、 核心API 函数：morphologyEx()
//int main(int argc, const char * argv[]) {
//
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    //调用 API
//    //    MORPH_ERODE 腐蚀
//    //    MORPH_DILATE 膨胀
//    //    MORPH_OPEN 开运算
//    //    MORPH_CLOSE 闭运算
//    //    MORPH_GRADIENT 形态学梯度
//    //    MORPH_TOPHAT 顶帽
//    //    MORPH_BLACKHAT 黑帽
//
//    //    Mat mat_element = getStructuringElement(MORPH_RECT, Size2i(10, 10));
//    //    Mat mat_image_dst;
//    //    morphologyEx(mat_image_src, mat_image_dst, MORPH_TOPHAT, mat_element);
//
//    // 自己实现
//    Mat mat_element = getStructuringElement(MORPH_RECT, Size2i(10, 10));
//    Mat mat_image_dst;
//
//    //    // 开运算  -> 先腐蚀后膨胀
//    //    erode(mat_image_src, mat_image_dst, mat_element);
//    //    dilate(mat_image_dst, mat_image_dst, mat_element);
//
//    //    // 闭运算  -> 先膨胀后腐蚀
//    //    dilate(mat_image_src, mat_image_dst, mat_element);
//    //    erode(mat_image_dst, mat_image_dst, mat_element);
//
//    //    // 形态学梯度运算  -> 先得到膨胀图 -> 在得到腐蚀图 -> 最后进行差值
//    //    Mat mat_image_dilate;
//    //    dilate(mat_image_src, mat_image_dilate, mat_element);
//    //    Mat mat_image_erode;
//    //    erode(mat_image_src, mat_image_erode, mat_element);
//    //    mat_image_dst = mat_image_dilate - mat_image_erode;
//
//    //    // 顶帽 -> 原图像与开运算结果之差
//    //    erode(mat_image_src, mat_image_dst, mat_element);
//    //    dilate(mat_image_dst, mat_image_dst, mat_element);
//    //    mat_image_dst = mat_image_src - mat_image_dst;
//
//    // 黑帽 -> 闭运算与原图像结果之差
//    dilate(mat_image_src, mat_image_dst, mat_element);
//    erode(mat_image_dst, mat_image_dst, mat_element);
//    mat_image_dst = mat_image_dst - mat_image_src;
//
//
//    namedWindow("形态学滤波图片");
//    imshow("形态学滤波图片", mat_image_dst);
//    waitKey();
//
//    return 0;
//}


//// 第十点：漫水填充 -> floodFill()
//int main(int argc, const char * argv[]) {
//
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//    Rect rect;
//    floodFill(mat_image_src,
//              Point2i(50, 50),
//              Scalar(155, 100, 255),
//              &rect,
//              Scalar(30, 30, 30),
//              Scalar(30, 30, 30));
//
//    namedWindow("形态学滤波图片");
//    imshow("形态学滤波图片", mat_image_src);
//    waitKey();
//
//    return 0;
//}

//// 第十一点：图片高质量压缩
//int main(int argc, const char * argv[]) {
//    //p 图片参数
//    int p[3];
//    //图片类型
//    p[0] = CV_IMWRITE_JPEG_QUALITY;
//    //压缩比例
//    p[1] = 50;
//    p[2] = 0;
//
//    IplImage *image = cvLoadImage("/Users/admin/Desktop/img.png");
//    cvSaveImage("/Users/admin/Desktop/image_new.jpg", image, p);
//
//    return 0;
//}


//// 第十二点：图像金字塔和图片尺寸缩放
////1、图像金字塔
////
////层级越高，则图像越小，分辨率越低
////对图像向上进行采样 -> pyrUp 函数
////对图像向下采样 -> pyrDown 函数
////
////2、图片尺寸缩放->resize()函数
//int main(int argc, const char * argv[]) {
//
//    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
//
//
//    Mat mat_iamge_dst;
//    resize(mat_image_src, mat_iamge_dst, Size2i(50, 50));
//
//
//    namedWindow("图片");
//    imshow("图片", mat_iamge_dst);
//    imwrite("/Users/admin/Desktop/image_new.jpg", mat_iamge_dst);
//    waitKey();
//
//    return 0;
//
//}


#pragma mark - 图像变换

//第一点：基于OpenCV边缘检测
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

//第二点：霍夫变换
int main(int argc, const char * argv[]) {
    
    // 第一步：加载图片
    Mat mat_image_src = imread("/Users/admin/Desktop/image1.jpeg");
    
    // 进行边缘检测和转化为灰度图片
    Mat mat_image_edges;
    Canny(mat_image_src, mat_image_edges, 50, 200, 3);
    Mat mat_image_dst;
    cvtColor(mat_image_edges, mat_image_dst, CV_GRAY2BGR);
    
    
    // 进行霍夫线变换
    vector<Vec4i> lines;
    HoughLinesP(mat_image_edges, lines, 1, CV_PI/180, 80, 50, 10);
    
    for (size_t i = 0; i < lines.size(); i++) {
        Vec4i l = lines[i];
        line(mat_image_dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, LINE_AA);
    }
    
    
    // 第六步：显示图片
    //    imshow("原图",  mat_image_src);
    //    imshow("边缘检测后的图",  mat_image_edges);
    imshow("效果图",  mat_image_dst);
    waitKey(0);
    
    return 0;
}

//跨平台处理
//
//一个方面：环境配置（每一个平台不一样）
//另一个方面：存在兼容性问题，那么一般情况下都是图片通道的类型问题->原来4个通道->单通道或者3通道








