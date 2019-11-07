#include <iostream>
#include <string>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/*
vector<Point>getMaxCont(vector<vector<Point>>& cont) {
	auto c = max_element(cont.begin(), cont.end(), [](vector<Point>& a, vector<Point>& b) {
		return a.size() < b.size();
		});
	return* c;
}

void wing_detector(const Mat gray, vector<Point>& wing) {
	Mat th;
	threshold(gray, th, 100, 255, THRESH_BINARY_INV);
	vector<vector<Point>>contours;
	findContours(th, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	wing = getMaxCont(contours);
}
*/


void hsvcpy(const Mat src, Mat& dest) {

	dest = Mat::zeros(src.size(), CV_8UC3);
	Mat hsv;
	cvtColor(src, hsv, COLOR_BGR2HSV);

	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			Vec3b c = src.at<Vec3b>(i, j);
			Vec3b hc = hsv.at<Vec3b>(i, j);
			if (hc[0] < 115 && hc[0]>95)
				dest.at<Vec3b>(i, j) = c;
		}
}


int main() {

	/*Mat sas_maszk;
	int fc = 0;
	VideoCapture cap;
	cap.open("sas.avi");

	if (!cap.isOpened()) {
		cout << "error" << endl;
		return -1;
	}

	Mat img, gray, mask, dest;
	while (1) {
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
		vector<vector<Point>>cont;
		findContours(sas_maszk.clone(), cont, RETR_EXTERNAL, CHAIN_APPROX_NONE);
		Rect r = boundingRect(cont[0]);
		Mat sas = img(r);
		imwrite(to_string(fc) + ".png", sas);
		imshow("sas", sas);
		fc++;


		//imshow("src", img);
		//imshow("dest", dest);

		waitKey(200);
	}*/

	/*Mat img = imread("sajt.png", IMREAD_GRAYSCALE);
	Mat th;
	double s = 0, ly = 0;
	threshold(img, th, 250, 255, THRESH_BINARY_INV);
	vector<vector<Point>> cont;
	vector<Vec4i> hier;
	Mat vaszon;
	cvtColor(img, vaszon, COLOR_GRAY2BGR);
	findContours(th, cont, hier, RETR_TREE, CHAIN_APPROX_NONE);
	for (int i = 0; i < hier.size(); i++) {
		if (hier[i][2 == -1]) {
			ly += contourArea(cont[i]);
			drawContours(vaszon, cont, i, Scalar(255, 0, 0), 2);
		}
		else{
			s +=contourArea(cont[i]);
			drawContours(vaszon, cont, i, Scalar(0, 255, 0), 2);
		}
	}
	imshow("sajt", vaszon);*/
	/*
	Mat img = imread("szita.jpg", IMREAD_GRAYSCALE);
	Mat vaszon = imread("szita.jpg");
	vector<Point> wing;
	wing_detector(img, wing);
	vector<vector<Point>>tmp;
	tmp.push_back(wing);
	drawContours(vaszon, tmp, 0, Scalar(255, 0, 0), 1);
	imshow("szarny", vaszon);
	vector<Point> hull;
	convexHull(wing, hull, false, true);
	polylines(vaszon, hull, true, Scalar(0, 255, 0),2);
	imshow("asd", vaszon);
	vector<int>hull2;
	convexHull(wing, hull2, false, false);
	vector<Vec4i> defects;
	convexityDefects(wing, hull2, defects);
	for (Vec4i df : defects) {
		if (df[3]/ 256.0>10.0)
		{
			drawMarker(vaszon, wing[df[2]], MARKER_CROSS);

		}
		else { drawMarker(vaszon, wing[df[2]], Scalar(0, 0, 255), MARKER_CROSS); }
	}
	imshow("jsa", vaszon);
	*/
	Mat fish = imread("fish.jpg");
	Mat smallFish;
	resize(fish, smallFish, fish.size() / 3);
	Mat hsvFish;
	hsvcpy(smallFish, hsvFish);
	imshow("fish", hsvFish);
	imwrite("AQC8ZY_fish.png", hsvFish);

	VideoCapture cap;
	cap.open("galamb.avi");
	if (!cap.isOpened())
	{
		cout << "Nem létezik a videó" << endl;
		waitKey(0);
		exit(0);
	}

	Mat sFish = imread("AQC8ZY_fish.png");
	Mat img;
	while (1)
	{
		cap >> img;
		if (img.empty())
			break;
		
		sFish.copyTo(img(cv::Rect(img.cols / 2 - sFish.cols, img.rows - sFish.rows, sFish.cols, sFish.rows)));
		medianBlur(img, img, 5);
		imshow("AQC8ZY", img);
		waitKey(30);
	}

	waitKey(0);

}
