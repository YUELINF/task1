#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {
	////������ͼ��
	//Mat img0 = imread("path");
	////�����հ�ͼ��
	Mat m0 = Mat::zeros(Size(5,8),CV_8UC3);//��С��5*8 8λ��U���޷��ţ�C3����ͨ��
	//Mat m1 = Mat::ones(Size(5, 8), CV_8UC3);//onesΪȫ1��zerosΪȫ0
	//Mat kernel = (Mat_<uchar>(3, 3) << 0, -1, 0
	//								  -1, 5, -1,
	//								   0, -1, 0);//ֱ�Ӵ����ض�����C++11���룩
	////��ʼ��
	//Mat img1 = img0.clone();
	//Mat img2;
	//img2.copyTo(img0);
	//Mat img3 = img0;

	//MatSize px = img0.size; cout << px;//[a x b]��ʽ
	//int col = img0.cols;//����
	//int row = img0.rows;//����

	int a = m0.at<uchar>(0, 0);
	cout << a;
	
	return 0;
}