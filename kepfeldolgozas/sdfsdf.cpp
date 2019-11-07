#include <iostream>
#include <string>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

vector<Point> getMaskContour(vector<vector<Point>>& count)
{
	auto c = max_element(count.begin(), count.end(), [](vector<Point>& a, vector<Point>& b) {return a.size(); return b.size(); });
	return* c;
}

void wing_detecor(const Mat gray, vector<Point>& wing)
{
	Mat szarny;
	threshold(gray, szarny, 100, 255, THRESH_BINARY_INV);
	vector<vector<Point>> contours;
	findContours(szarny, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	wing = getMaskContour(contours);
}


int main() {
	/*

	VideoCapture cap;
	cap.open("sas.avi");

	if (!cap.isOpened()) {
		cout << "error" << endl;
		return -1;
	}

	Mat img, gray, mask, sas_maszk, dest;
	int fc = 0;
	while ( 1 ) {
		cap >> img;
		if (img.empty())
			break;

		cvtColor(img, gray, COLOR_BGR2GRAY);
		inRange(gray, 100, 155, mask);

		dest = img.clone();
		medianBlur(mask, mask, 5);
		dest.setTo(0, mask);

		sas_maszk = 255 - mask;
		dilate(sas_maszk, sas_maszk, getStructuringElement(MORPH_ELLIPSE, Size(9, 9)));
		vector<vector<Point>> contours;
		findContours(sas_maszk.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
		Rect r = boundingRect(contours[0]);
		Mat sas = img(r);
		imwrite(to_string(fc)+".png", sas);
		imshow("kicsi", sas);
		//imshow("src", img);
		//imshow("dest", dest);
		

		
		cv::waitKey(200);
		fc++;
	}
	cv::waitKey(0);
	*/
	/*
	Mat img = imread("sajt.png", IMREAD_GRAYSCALE);
	Mat sajt_maszk;
	threshold(img, sajt_maszk, 250, 255, THRESH_BINARY_INV);
	vector<vector<Point>> cont;
	vector<Vec4i> hier;
	findContours(sajt_maszk, cont, hier, RETR_TREE, CHAIN_APPROX_NONE);
	double lap_terulet = 0, lyuk_terulet = 0;
	Mat vaszon;
	cvtColor(img, vaszon, COLOR_GRAY2BGR);
	for (int i = 0; i < hier.size(); i++)
	{
		if (hier[i][2] == -1)
		{
			lyuk_terulet += contourArea(cont[i]);
			drawContours(vaszon, cont, i, Scalar(255, 0, 0), 2);
		}
		else
		{
			lap_terulet += contourArea(cont[i]);
			lyuk_terulet += contourArea(cont[i]);
			drawContours(vaszon, cont, i, Scalar(0, 255, 0), 2);
		}
	}
	imshow("sajt", vaszon);
	cout << 100 - (lap_terulet / lyuk_terulet) * 100;
	waitKey(0);
	*/
	Mat img = imread("szita.jpg", IMREAD_GRAYSCALE);
	vector<Point> wing;
	wing_detecor(img, wing);
	vector<Point> hull;
	convexHull(wing, hull, false, true);
	Mat dest;
	polylines(dest, hull, true, Scalar(255, 0, 0));
	imshow("sdfs", dest);
	waitKey(0);
	return 0;
}
