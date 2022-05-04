#include<opencv2/opencv.hpp>
#include<iostream>
#include<stdio.h>
using namespace std;
using namespace cv;

//Mat change(long long a ,Mat img) {
//	for (size_t col = 0; col < 512; col++)
//	{
//		int pv = img.at<uchar>(0, col);
//		if (pv < a)
//		{
//			img.at<uchar>(0, col) = 0;
//		}
//		else
//		{
//			img.at<uchar>(0, col) = 255;
//		}
//	}
//}

int main() {
	//原图
	Mat img = imread("photos/test.jpg");
	imshow("Image", img);
	
	//灰度图
	Mat imgGray;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	imshow("Gray Image", imgGray);



	//前两行的平均值、中位数
	Mat img2 = imgGray.clone();
	vector<int> nums0;
	vector<int> nums1;
	long long n = (long long)img2.cols * img2.rows;
	long long sum = 0;
	long long a;//平均数
	long long c;//中位数
	for (size_t row = 0; row < img2.rows; row++)
	{
		for (size_t col = 0; col < img2.cols; col++)
		{
			int pv = img2.at<uchar>(row, col);
			nums0.push_back(pv);
			sum += pv;
		}
	}
	a = sum / n;
	cout <<"-----平均数-----" << '\n';
	cout << a << '\n';
	cout <<"-----中位数-----" <<'\n';
	sort(nums0.begin(), nums0.end());
	int s = n / 2;
	c = (nums0[s] + nums0[s+1]) / 2;
	cout << c << '\n';
	cout << '\n';


	//平均数为阈值
	for (size_t row = 0; row < img2.rows; row++)
	{
		for (size_t col = 0; col < img2.cols; col++)
		{
			int pv = img2.at<uchar>(row, col);
			if (pv < a)
			{
				img2.at<uchar>(row, col) = 0;
			}
			else
			{
				img2.at<uchar>(row, col) = 255;
			}
		}
	}
	imshow("Average", img2);

	//中位数为阈值
	for (size_t row = 0; row < img2.rows; row++)
	{
		for (size_t col = 0; col < img2.cols; col++)
		{
			int pv = img2.at<uchar>(row, col);
			if (pv < c)
			{
				img2.at<uchar>(row, col) = 0;
			}
			else
			{
				img2.at<uchar>(row, col) = 255;
			}
		}
	}
	imshow("Median", img2);

	//一半一半
	Mat imgHalf = imgGray.clone();
	for (size_t row = 0; row < imgHalf.rows/2; row++)
	{
		for (size_t col = 0; col < imgHalf.cols; col++)
		{
			int pv = imgHalf.at<uchar>(row, col);
			if (pv < a)
			{
				imgHalf.at<uchar>(row, col) = 0;
			}
			else
			{
				imgHalf.at<uchar>(row, col) = 255;
			}
		}
	}

	imshow("Half", imgHalf);

	//二值图
	Mat imgBinary = imgGray.clone();
	int w = imgBinary.cols;
	int h = imgBinary.rows;
	int dims = imgBinary.channels();
	//cout << w << ' ' << h << ' ' << dims << '\n';
	for (size_t row = 0; row < h; row++)
	{
		for (size_t col = 0; col < w; col++)
		{
			if (dims == 1)
			{
				int pv = imgBinary.at<uchar>(row, col);
				if (pv > 127)
				{
					imgBinary.at<uchar>(row,col) = 255;
				}
				else
				{
					imgBinary.at<uchar>(row, col) = 0;
				}
			}
		}
	}
	imshow("Binary Image", imgBinary);
	waitKey(0);
	//矩阵输出
	FILE* stream1;
	freopen_s(&stream1, "mat.txt", "w", stdout);
	cout << imgGray << ' ';
	_fcloseall;
	return 0;
}