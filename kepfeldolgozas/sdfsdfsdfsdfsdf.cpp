#include <iostream>
#include <string>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
void jerryMasolo(const Mat src, Mat& dest) {
	dest = Mat::zeros(src.size(), CV_8UC3);

	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			Vec3b c = src.at<Vec3b>(i, j);
			if (c[0] >20 & c[1] <255 & c[2] >50)
				dest.at<Vec3b>(i, j) = c;
		}
}
*/
/*
void wing_detecor(const Mat gray, vector<Point>& wing, vector<Point>& wing2) {
	Mat binary;
	threshold(gray, binary, 100, 255, THRESH_BINARY_INV);

	//imshow("wing", wing);

	vector<vector<Point>> contours;
	findContours(binary.clone(), contours, RetrievalModes::RETR_EXTERNAL, ContourApproximationModes::CHAIN_APPROX_SIMPLE);

	// k�t legnagyobb kont�r kiv�laszt�sa
	int maxh = -1, maxh2 = -1;
	double max = 0, max2 = 0;

	for (int i = 0; i < contours.size(); ++i) {
		double t = contourArea(contours[i]);
		if (t > max) {
			max2 = max;
			maxh2 = maxh;
			max = t;
			maxh = i;
		}
		else if (t > max2) {
			max2 = t;
			maxh2 = maxh;
		}
	}

	assert(maxh != -1 && maxh2 != -1);

	wing = contours[maxh];
	wing2 = contours[maxh2];
}


void defectDetector(const Mat img, const vector<Point>& wing, vector<Point>& dest) 
{
	vector<int> hull;
	convexHull(wing, hull, false, false);
	vector<Vec4i> defectPoints;
	convexityDefects(wing, hull, defectPoints);
	for (Vec4i dp : defectPoints)
		if (dp[3] / 256.0 > 10)
			dest.push_back(wing[dp[2]]);
}
*/

int main() {
	/*
	VideoCapture cap;
	cap.open("Jerry.avi");
	if (!cap.isOpened())
	{
		cout << "Nem sikerult a beolvasas" << endl;
		waitKey(0);
		exit(0);
	};

	VideoCapture cap2;
	cap2.open("snow.avi");
	if (!cap2.isOpened())
	{
		cout << "Nem sikerult a beolvasas" << endl;
		waitKey(0);
		exit(0);
	};
	int fn = 0;
	Mat img,img2,img3;
	while (1) {
		cap2 >> img;
		cap >> img2;
		if (img.empty() || img2.empty()) break;
		imshow("LCPI9V", img);
		imwrite("mentett_" + to_string(fn) + ".png", img);
		imshow("LCPI9Vs", img2);
		imwrite("LCPI9V" + to_string(fn) + ".png", img2);
		fn++;
		
	

		jerryMasolo(img2, img3);
		imshow("fsa", img3);
		Mat eloter;
		resize(img3, eloter, img.size());
		double alfa = 0.3;
		Mat res = alfa * img + (1 - alfa) * eloter;

		imshow("LCPI9V", res);
	*/
	/*-----------------------------------------
	Mat colorImg = imread("szita.jpg");

	assert(!colorImg.empty());

	Mat gray;
	cvtColor(colorImg, gray, COLOR_BGR2GRAY);

	Mat binary;
	threshold(gray, binary, 100, 255, THRESH_BINARY_INV);

	// a k�t legnagyobb sz�rny
	vector<Point> wing, wing2;
	wing_detecor(gray, wing, wing2);

	vector<Point> defectPoints;
	defectDetector(colorImg, wing, defectPoints);


	// -----------   k�p rajzol�sa  -------------------
	vector<vector<Point>> tmp;
	tmp.push_back(wing);
	tmp.push_back(wing2);
	drawContours(colorImg, tmp, -1, Scalar(255, 0, 0), 2);

	vector<Point> hull;
	convexHull(wing, hull, false, true);

	cv::polylines(colorImg, hull, true, Scalar(255, 255, 255), 2);

	for (auto dp : defectPoints)
		cv::drawMarker(colorImg, dp, Scalar(0, 0, 255), MARKER_CROSS, 15, 2);

	imshow("szarnyrajz", colorImg);
	*/
	/*
	Mat img = imread("szita.jpg", IMREAD_COLOR);
	Mat imgt, lab, bestlabels;
	img.convertTo(imgt, CV_32F, 1 / 256);
	cvtColor(imgt, lab, COLOR_BGR2Lab);
	Mat data = lab.reshape(1, img.rows * img.cols);
	cv::TermCriteria krit(TermCriteria::Type::EPS | TermCriteria::Type::MAX_ITER, 100, 0.001);
	kmeans(data, 3, bestlabels, krit, 3, KMEANS_RANDOM_CENTERS);
	Mat dest(img.size(), CV_32FC3);
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			int idx = i * img.cols + j;
			int klaszter_idx = bestlabels.at<int>(idx);

			dest.at<Vec3f>(i, j)[0] = center.at<float>(klaszter_idx, 0);
			dest.at<Vec3f>(i, j)[1] = center.at<float>(klaszter_idx, 1);
			dest.at<Vec3f>(i, j)[2] = center.at<float>(klaszter_idx, 2);
		}
	}
	Mat destt, deste;
	cvtColor(dest, destt, COLOR_BGR2Lab);
	destt.convertTo(deste, CV_8UC3, 256);
	imshow("fada", deste);
	*/
	Mat Data(18, 3, CV_32F);
	Mat img, mask;
	for (int i = 1; i < 19; i++)
	{
		img = imread("kekszek_vegyes\\" + to_string(i) + ".png", IMREAD_GRAYSCALE);
		threshold(img, mask, 100, 255, THRESH_OTSU | THRESH_BINARY_INV);
		medianBlur(mask, mask, 5);
		vector<vector<Point>> cont;
		findContours(mask.clone(), cont, RETR_EXTERNAL, CHAIN_APPROX_NONE);
		double ker = arcLength(cont[0], true);
		double ter = contourArea(cont[0]);
		double cirk = ter / ker * ker;
		Data.at<float>(i - 1, 0) = ker;
		Data.at<float>(i - 1, 1) = ter;
		Data.at<float>(i - 1, 2) = cirk;
	}
	/*
	.
	.
	.
	*/
	int contours[] = { 0, 0, 0 };
	for (int i = 1; i < 18; i++)
	{
		img = imread("kekszek_vegyes\\" + to_string(i) + ".png");
		lbl = bestlabels.at<int>(i);
	}

	waitKey(0);



	}
