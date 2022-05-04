#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	//Mat img = imread("C:/Users/MSI/Pictures/OpenCvPhotos/test.jpg");
	//imshow("Image", img);
	//Mat imgGray,imgBlur,imgCanny;
	//cvtColor(img, imgGray,COLOR_RGB2GRAY);//灰度图
	//GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);//高斯模糊
	//Canny(img, imgCanny, 50, 150);

	//imshow("GrayImage",imgGray);
	//imshow("BlurImage", imgBlur);
	//imshow("CannyIamge", imgCanny);
	//waitKey(0);
	//VideoCapture cap(1);
	//Mat img;
	//while (true)
	//{
	//	cap.read(img);
	//	imshow("Image", img);
	//	waitKey(1);
	//}
	Mat m1(512, 512, CV_8UC3, Scalar(255, 255, 255));
	Mat m2(512, 512, CV_8UC3, Scalar(0,0,0));

	//Mat m2 = m1.clone();
	//Mat m3;
	//m3.copyTo(m1);
	//Mat m4 = m1;
	Mat m5 = Mat::ones(Size(512, 512), CV_8UC3);
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, 0, -5, 0, -1, 0, -1);
	imshow("white", m1);
	imshow("black", m2);
	imshow("kernel", kernel);
	cout << kernel;
	waitKey(0);
	return 0;

}