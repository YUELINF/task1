#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	////创建带图像
	//Mat img0 = imread("path");
	////创建空白图像
	Mat m0 = Mat::zeros(Size(5,8),CV_8UC3);//大小：5*8 8位（U）无符号（C3）三通道
	//Mat m1 = Mat::ones(Size(5, 8), CV_8UC3);//ones为全1，zeros为全0
	//Mat kernel = (Mat_<uchar>(3, 3) << 0, -1, 0
	//								  -1, 5, -1,
	//								   0, -1, 0);//直接创造特定矩阵（C++11引入）
	////初始化
	//Mat img1 = img0.clone();
	//Mat img2;
	//img2.copyTo(img0);
	//Mat img3 = img0;

	//MatSize px = img0.size; cout << px;//[a x b]形式
	//int col = img0.cols;//列数
	//int row = img0.rows;//行数

	int a = m0.at<uchar>(0, 0);
	cout << a;
	
	return 0;
}