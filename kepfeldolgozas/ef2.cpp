#include <iostream>
#include <string>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/ml.hpp>

using namespace std;
using namespace cv;
using namespace cv::ml;




int main() {
	/*
	Mat hsv, barna, lila, hatter;
	Mat img = imread("sejtek.bmp");
	GaussianBlur(img, img, Size(5, 5), 1.4);
	cvtColor(img, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(0, 10, 0), Scalar(30, 255, 150), barna);
	inRange(hsv, Scalar(80, 10, 0), Scalar(170, 255, 150), lila);
	inRange(hsv, Scalar(0, 10, 0), Scalar(255, 255, 255), hatter);
	hatter = hatter - barna - lila;
	Mat marker(img.size(), CV_32S);
	marker.setTo(128, barna);
	marker.setTo(255, lila);
	marker.setTo(50, hatter);
	watershed(img, marker);
	Mat eredmeny = Mat::zeros(img.size(), CV_8UC3);
	img.copyTo(eredmeny, marker == 128);
	medianBlur(eredmeny, eredmeny, 5);
	imshow("eredmeny", eredmeny);
	*/

	/*
	Mat hsv, eloter, tavolsag, dil;
	Mat img = imread("sejtek.bmp");
	cvtColor(img, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(0, 35, 0), Scalar(255, 255, 255), eloter);
	distanceTransform(eloter, tavolsag, DIST_L2, 3);
	normalize(tavolsag, tavolsag, 0, 1, NORM_MINMAX);
	tavolsag.convertTo(tavolsag, CV_8U, 255.0);
	//imshow("tav", tavolsag);
	Mat m = Mat::ones(5, 5, CV_8UC1);
	m.at<uchar>(2, 2) = 0;
	cout << m << endl;
	dilate(tavolsag, dil, m);
	Mat loc = tavolsag > dil;
	Mat marker(img.size(), CV_32S);
	int lb = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			if (loc.at<uchar>(i, j))
			{
				marker.at<int>(i, j) = lb++;
			}
		}
	}
	watershed(img, marker);
	Mat markerV;
	marker.convertTo(markerV, CV_8UC1);
	//imshow("marker", markerV);
	vector<Vec3b> szinek;
	for (int i = 0; i < lb; i++)
	{
		szinek.push_back(Vec3b(rand() % 255, rand() % 255, rand() % 255));
	}
	Mat dest = Mat::zeros(img.size(), CV_8UC3);
	int l = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			l = marker.at<int>(i, j);
			dest.at<Vec3b>(i, j) = szinek[l];
		}
	}
	imshow("sdfsf", dest);
	*/
	Mat img = imread("sejtek.bmp");
	Mat hsv, barna, veloter, bhatter;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(0, 10, 0), Scalar(30, 255, 150), barna);
	medianBlur(barna, barna, 3);
	dilate(barna, veloter, getStructuringElement(MORPH_ELLIPSE, Size(21, 21)));
	bhatter = 255 - veloter;
	veloter = veloter - barna;
	Mat mask = Mat::zeros(img.size(), CV_8UC1);
	mask.setTo(GC_FGD, barna);
	mask.setTo(GC_PR_FGD, veloter);
	mask.setTo(GC_BGD, bhatter);
	Mat model1, model2;
	grabCut(img, mask, Rect(), model1, model2, 10, GC_INIT_WITH_MASK);
	imshow("sf", mask);

	waitKey();
	return 0;
}
