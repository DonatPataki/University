#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>


using namespace std;
using namespace cv;

/*
void eloterMasolo(const cv::Mat src, cv::Mat dest) {
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			Vec3b c = src.at<Vec3b>(i, j);
			if (c[0] != 255 || c[1] != 255 || c[2] != 255)
				dest.at<Vec3b>(i, j) = c;
		}
}
void narancsMasolo(const Mat src, Mat& dest) {
	dest = Mat::zeros(src.size(), CV_8UC3);
	
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			Vec3b c = src.at<Vec3b>(i, j);
			if (c[0] < 50 || c[1] < 60 || c[2] > 200)
				dest.at<Vec3b>(i, j) = c;
		}
}

void narancsMasolo2(const Mat src, Mat& dest) {
	
	dest = Mat::zeros(src.size(), CV_8UC3);
	Mat hsv;
	cvtColor(src, hsv, COLOR_BGR2HSV);
	
	for (int i = 0; i < src.rows; i++)
		for (int j = 0; j < src.cols; j++) {
			Vec3b c = src.at<Vec3b>(i, j);
			Vec3b hc = hsv.at<Vec3b>(i, j);
			if (hc[0] < 30 && hc[1]>5 )
				dest.at<Vec3b>(i, j) = c;
		}
}

void valto(Mat rgb, vector<Mat>& chs) {
	rgb.convertTo(rgb, CV_32FC3, 1.0 / 255.0);
	Mat lab; 
	cvtColor(rgb, lab, COLOR_BGR2Lab);
	split(lab, chs);
}
*/

int main() {
	/*Mat eloter; Mat orange1;
	//Mat orange = imread("orange.jpg");
	Mat eloter0 = imread("orange.jpg");
	Mat hatter = imread("background.jpg");
	resize(eloter0, eloter, hatter.size());
	//eloterMasolo(eloter, hatter);
	narancsMasolo2(eloter, hatter);
	imshow("uj kep", hatter);
	//imshow("Orange", orange);
	waitKey(0);

	return 0;
	Mat img;
	Mat etalon = imread("etalon.png");
	assert(!etalon.empty());
	vector <Mat>ev;
	valto(etalon, ev);
	for (int i = 1; i < 8; i++) {
		img = imread("fa" + to_string(i) + ".png");
		assert(!img.empty());
		vector<Mat> iv;
		valto(img, iv);
		Mat dL = ev[0] - iv[0];
		Mat dA = ev[1] - iv[1];
		Mat dB = ev[2] - iv[2];
		Mat dL2 = dL.mul(dL);
		Mat dA2 = dA.mul(dA);
		Mat dB2=dB.mul(dB);
		Mat res; cv::sqrt(dL2 + dA2 + dB2, res);
		Scalar s = mean(res);
		cout << s[0] << endl;
	}
	------------------
	Mat img = imread("debrecen_deep.png", IMREAD_GRAYSCALE);
	double ah, th;
	minMaxLoc(img, &ah, &th);
	Mat dest = (img - ah) * (255.0 / (th - ah));
	Mat dest2;
	equalizeHist(img, dest2);
	imshow("melyseg", dest);
	imshow("melyseg2", dest2);
	
	Mat img = imread("Indian_hybrid_Orange.jpg");
	Mat hsv, lab;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	cvtColor(img, lab, COLOR_BGR2Lab);
	vector<Mat> chs;
	split(lab, chs);
	equalizeHist(chs[0], chs[0]);
	Mat dest;
	merge(chs, dest);
	Mat dest2;
	cvtColor(dest, dest2, COLOR_Lab2BGR);
	imshow("sajt", dest2);
	
	string menu = "tool";
	cv::namedWindow(menu, WINDOW_NORMAL);
	cv::resizeWindow(menu, Size(500, 50));
	int radius = 1, sigma = 1;
	createTrackbar("radius", menu, &radius, 25);
	createTrackbar("sigma", menu, &sigma, 25);
	Mat img = imread("szita2.png", IMREAD_GRAYSCALE);
	imshow("blur", img);
	Mat blur1, gauss, median, bilat; //üres fejlécek a szűrt képek számára
	while (cv::waitKey(20) != 'q') { //q-ra lép ki
	//mossa el a különböző szűrőkkel a képet és mentse
		
		//blur(img, blur1, Size(2 * radius + 3, 2 * radius + 3));
		//imshow("blur", blur1);
		GaussianBlur(img, gauss, Size(2 * radius + 3, 2 * radius + 3), sigma);
		imshow("blur", gauss);
		

	}
	*/
	Mat img = imread("KossuthSquare\\SnapShot-20180731_173715.jpg");
	Mat acc = Mat::zeros(img.size(), CV_64FC3);
	int f = 0;
	for (int i = 173715; i < 173918; i++)
	{
			img = imread("KossuthSquare\\SnapShot-20180731_" + to_string(i) + ".jpg");
			if (!img.empty())
			{
				accumulate(img, acc);
				f++;
			}
	}
	Mat dest;
	acc.convertTo(dest, CV_8U, 1.0 / f);
	imshow("Kossuth", dest);

	waitKey(0);
	return 0;
}
