#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>


using namespace std;
using namespace cv;


int main() {
	/*Mat th,er,di;
	Mat img = imread("sajt.jpg",IMREAD_GRAYSCALE);
	threshold(img, th, 250, 255, THRESH_BINARY_INV);
	Mat se = getStructuringElement(MORPH_CROSS, Size(3, 3));
	erode(th, er, se);
	imshow("erodált", er);
	dilate(er, di, se);
	imshow("dilat", di);
	morphologyEx(th, di, MORPH_GRADIENT, se);
	imshow("v", di);
	waitKey(0);*/
	/*Mat th, th2, er, di;
	threshold(img, th, 100, 255, THRESH_BINARY_INV);
	Mat se = getStructuringElement(MORPH_ELLIPSE, Size(5, 9));
	/*dilate(th, di, se);
	Mat sajt = di - th;
	imshow("sajt", sajt);
	threshold(img, th2, 252, 255, THRESH_BINARY_INV);
	Mat see = getStructuringElement(MORPH_ELLIPSE, Size(21, 21));
	dilate(th2, di, see);
	erode(di, er, see);
	imshow("sajt2", er);*/
	/*erode(th, er, se);
	Mat er2 = er(Rect(400, 0, er.cols - 400, er.rows));
	double foltterulet = countNonZero(er2);
	imshow("ds",er2);
	cout << foltterulet << endl;*/


	/*Mat img = imread("go2.png", IMREAD_GRAYSCALE);
	Mat dest = Mat::zeros(img.size(), CV_8UC1);
	for (int y = 1; y < img.rows; y++)
	{
		for (int x = 1; x < img.cols; x++)
		{
			int dx = img.at<uchar>(y, x) - img.at<uchar>(y, x - 1);
			int dy = img.at<uchar>(y, x) - img.at<uchar>(y - 1, x);
			dest.at<uchar>(y, x) = (fabs(dx) + fabs(dy))/2;
		}
	}
	imshow("asd", dest);*/
	
	/*Mat dx, dy;
	Sobel(img, dx, CV_32F, 1, 0);
	Sobel(img, dy, CV_32F, 0, 1);

	Mat g,dest;
	cv::sqrt(dx.mul(dx) + dy.mul(dy),g);
	convertScaleAbs(g, dest);
	
	vector <Vec3f>circles;
	HoughCircles(img, circles, HOUGH_GRADIENT, 2, 10, 80, 35, 20, 20);
	Mat img2;
	cvtColor(img, img2, COLOR_GRAY2BGR);
	for (auto c : circles) {
		if (img.at<uchar>(c[1], c[0]) > 128) {
			circle(img2, Point(c[0], c[1]), c[2], Scalar(255, 0, 0), 2);
		}
		else { circle(img2, Point(c[0], c[1]), c[2], Scalar(0, 255, 0), 2); }

	}
	
	imshow("img", img2);
	imshow("as", dest);*/
	////////////////////////////////////////////
	Mat 

	waitKey(0);
	
}





