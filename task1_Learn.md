# OpenCv Learning

## 一、task1

### 1、环境配置

##### （１）C++环境配置：

第一步：

​			[Github](https://github.com/opencv/opencv/releases)上下载版本，我下载的是４.５.５版本。解压至文件夹。

第二步：

​			１、添加环境变量：

<img src="C:\Users\MSI\AppData\Roaming\Typora\typora-user-images\image-20220504175057502.png" alt="image-20220504175057502" style="zoom:50%;" />

​			２、创建新项目，打开项目属性，包含目录里添加路径：

<img src="C:\Users\MSI\AppData\Roaming\Typora\typora-user-images\image-20220504174507833.png" style="zoom:50%;" />

​				３、库目录里添加路径：

<img src="C:\Users\MSI\AppData\Roaming\Typora\typora-user-images\image-20220504174655970.png" alt="image-20220504174655970" style="zoom:50%;" />

​				４、链接器，输入里添加附加依赖项（ｄ代表debug版本，没有ｄ代表release版本）：

<img src="C:\Users\MSI\AppData\Roaming\Typora\typora-user-images\image-20220504174859295.png" alt="image-20220504174859295" style="zoom:50%;" />

​		ｔｉｐｓ：有可能你的电脑也和我一样，不知道为什么显示<img src="C:\Users\MSI\AppData\Roaming\Typora\typora-user-images\image-20220504175516785.png" alt="image-20220504175516785" style="zoom: 33%;" />，或者其他很离谱的错误，０ｘｃ００００７ｂ是能解决的（网上搜）。所以附上懒人工具：[配置工具](https://github.com/Vselfdom/Automatically-Build-Opencv-VS-Environment)，具体使用看人家的README。或者用ｖｃｐｋｇ配置。

##### （２）Python配置

ｐｙｃｈａｒｍ里面有现成的。

### ２.　Ｌ１

###### 任务：在指定图像上，把图像转化为灰度图，二值图，在灰度图的基础上，把图像转化为矩阵显示并输出，计算整个矩阵的平均值，中位数，分别把平均值，中位数设为阈值T，把整个矩阵中小于T的数改为0，大于等于T的改为255

具体见ｔａｓｋ１．ｃｐｐ

### ３.知识点

##### 一、图像基础知识



##### 二、Ｍａｔ

Ｍａｔ是存储图像的一种矩阵，ｏｐｅｎｃｖ里的一种基本类型。

１.创建与初始化

```c++
	//创建带图像
	Mat img0 = imread("path");
	//创建空白图像
	Mat m0 = Mat::zeros(Size(5,8),CV_8UC3);//大小：5*8 8位（U）无符号（C3）三通道
	Mat m1 = Mat::ones(Size(5, 8), CV_8UC3);//ones为全1，zeros为全0
	Mat kernel = (Mat_<uchar>(3, 3) << 0, -1, 0
									  -1, 5, -1,
									   0, -1, 0);//直接创造特定矩阵（C++11引入）
	//初始化
	Mat img1 = img0.clone();
	Mat img2;
	img2.copyTo(img0);
	Mat img3 = img0;
```

２.操作矩阵

（１）可直接输出矩阵，建议配合ｆｒｅｏｐｅｎ使用

```c++
	FILE* stream1;
	freopen_s(&stream1, "mat.txt", "w", stdout);
	cout << imgGray << ' ';
	_fcloseall;
```

（２）可读取矩阵大小：

```c++
	MatSize px = img0.size; cout << px;//[a x b]形式
	int col = img0.cols;//列数
	int row = img0.rows;//行数
```

３.操作像素

（１）读取像素

```c++
int pv = imgBinary.at<uchar>(row, col);
```

（２）更改像素

```c++
imgBinary.at<uchar>(row,col) = 255;
／／改ｐｖ没用，除非用指针
```

４.ｃｖｔｃｏｌｏｒ函数

`void cvtColor( InputArray src, OutputArray dst, int code, int dstCn = 0 );`

ｓｒｃ：原图

ｄｓｔ：目标图

ｃｏｄｅ：改变的格式（例如：COLOR_BGR2GRAY　为　BGR　ｔｏ　ＧＲＡＹ）

