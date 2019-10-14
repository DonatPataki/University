#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>


using namespace std;
using namespace cv;
/*
void createHisto(const Mat img, Mat& hiszto) {
	//a hiszto az eredmeny, float típusú elemeket tartalmaz majd
	vector<Mat> kepek;
	kepek.push_back(img); // egy képet használunk
	vector<int> csatornak;
	csatornak.push_back(0); //a képnek a 0. csatornáját használjuk
	vector<int> hiszto_meretek;
	hiszto_meretek.push_back(256); //szürkeárnyalatok száma
	vector<float> hiszto_tartomanyok;
	hiszto_tartomanyok.push_back(0.0f); //hol kezdődik a tartomány
	hiszto_tartomanyok.push_back(255.f); //meddig tart
	//accumlate: marad false (nullázza a hisztogrammot)
	calcHist(kepek, csatornak, noArray(), hiszto, hiszto_meretek,
		hiszto_tartomanyok, false);

}
void kuszobol(const Mat src, Mat& dest, float ratio =0.1){

	Mat hiszto;
	createHisto(src, hiszto);
	int osszes = src.rows * src.cols;
	double s = 0; int k = 0;
	for (int i = 0; i < hiszto.rows; ++i) {
		s += hiszto.at<float>(i);
		if (s / osszes >= ratio) {
			k = i;
			break;
		}
	}
	threshold(src, dest, k, 255, THRESH_BINARY_INV);

}
*/

int main() {
	/*Mat dest;
	Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
	threshold(img, dest, 100, 255,THRESH_BINARY);

	imshow("img",dest);
	waitKey(0);
	medianBlur(dest, dest, 5);*/

	/*Mat dest;
	Mat img = imread("madar.jpg");
	vector<Mat>chs;
	split(img, chs);
	imshow("R", chs[2]);
	imshow("G", chs[1]);
	imshow("B", chs[0]);
	threshold(chs[0], dest, 110, 255, THRESH_BINARY);

	imshow("img", dest);
	waitKey(0);*/
	

	/*Mat dest;
	Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
	threshold(img, dest, 100, 255, THRESH_TOZERO);

	imshow("img", dest);
	waitKey(0);*/


	/*VideoCapture cap;
	cap.open("sas.avi");
	if (!cap.isOpened()) {
		cout << "Nem nyitható"<<endl;
		exit(-1);
	}
	Mat img, maszk, szurke, masolat; int fc = 0;
	while (1) { 
		cap >> img;
		if (img.empty()) break;
		
		/*imshow("img", img);
		waitKey(33);*/
		/*masolat = img.clone();
		cvtColor(masolat, szurke, COLOR_BGR2GRAY);
		inRange(szurke, 100, 155, maszk);
		medianBlur(maszk, maszk, 5);
		masolat.setTo(0, maszk);
		imwrite(to_string(fc)+".png",masolat);
		fc++;}*/
	/*Mat dest;
	Mat img = imread("sejtek.png", IMREAD_GRAYSCALE);
	int x = 0, y = 0;
	for (int i = 20; i <= 240; i += 20) {
		threshold(img, dest, i, 255, THRESH_BINARY_INV);
		string a = to_string(i);
		namedWindow(a, WINDOW_NORMAL);
		imshow(a, dest);
		resizeWindow(a, 300, 300);
		moveWindow(a, x, y);
		x += 300;
		if (x >= 900) {
			x = 0;
			y += 330;
		}
		
	}
	waitKey(0);*/
	/*
	Mat dest; int sugar = 20; int c = 0;
	Mat img = imread("zh.jpg", IMREAD_GRAYSCALE);
	namedWindow("a", WINDOW_NORMAL);
	resizeWindow("a", 500, 50);
	createTrackbar("th", "a", &sugar, 255);
	createTrackbar("C:", "a", &c, 50);
		int c2;
		while ((c2 = waitKey(1)) != 'q') {
			adaptiveThreshold(img, dest, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY_INV, 2*sugar+3, (c - 25));
			imshow("dest", dest);
		}
	*/
	//---------------------------------------------------------------------------	
	/*
	Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
	Mat th, er, di;
	threshold(img, th, 120, 255, THRESH_OTSU);
	Mat se = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
	erode(th, er, se);
	imshow("erózió", er);
	//dilate(er, di, se);
	morphologyEx(img, di, MORPH_OPEN, se);
	imshow("visszaállított", di);
	*/
	/* 
	Mat img = imread("sajt.jpg", IMREAD_GRAYSCALE);
	Mat th, th2, er, di;
	threshold(img, th, 120, 255, THRESH_OTSU);
	Mat se = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
	dilate(th, di, se);
	Mat sajt = di - th;
	imshow("sajt", sajt);
	threshold(img, th2, 252, 255, THRESH_BINARY_INV);
	Mat see = getStructuringElement(MORPH_ELLIPSE, Size(21, 21));
	dilate(th2, di, see);
	erode(di, er, see);
	imshow("sajt2", er);
	*/
	/*
	Mat img = imread("szitakoto.jpg", IMREAD_GRAYSCALE);
	Mat th, er, di;
	threshold(img, th, 120, 255, THRESH_BINARY_INV);
	Mat se = getStructuringElement(MORPH_ELLIPSE, Size(25, 25));
	erode(th, er, se);
	dilate(er, di, se);
	double p = countNonZero(di);
	cout << p;
	imshow("asd", di);
	*/
	/*
	Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
	Mat dest = Mat::zeros(img.size(), CV_8UC1);
	for (int y = 1; y < img.rows; y++)
	{
		for (int x = 1; x < img.cols; x++)
		{
			int dx = img.at<uchar>(y, x) - img.at<uchar>(y, x - 1);
			int dy = img.at<uchar>(y, x) - img.at<uchar>(y - 1, x);
			dest.at<uchar>(y, x) = abs(dx) + abs(dy);
		}
	}
	imshow("asd", dest);
	*/
	/*
	Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
	Mat dx, dy;
	Sobel(img, dx, CV_32F, 1, 0);
	Sobel(img, dy, CV_32F, 0, 1);
	Mat G, dest;
	cv::sqrt(dx.mul(dx) + dy.mul(dy), G);
	convertScaleAbs(G, dest);
	imshow("asd", dest);
	*/
	Mat img = imread("go2.png", IMREAD_GRAYSCALE);
	vector<Vec3f> circles;
	Mat img2;
	cvtColor(img, img2, COLOR_GRAY2BGR);
	HoughCircles(img, circles, HOUGH_GRADIENT, 2, 10, 80, 35, 20, 20);
	for (auto c : circles)
	{
		if (img.at<uchar>(Point(c[0], c[1])) > 128) 
		{
			circle(img2, Point(c[0], c[1]), c[2], Scalar(255, 0, 0), 2);
		}
		else
		{
			circle(img2, Point(c[0], c[1]), c[2], Scalar(0, 255, 0), 2);
		}
	}
	imshow("sffa", img2);

	waitKey(0);
}





