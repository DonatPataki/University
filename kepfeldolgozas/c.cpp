#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>


using namespace std;
using namespace cv;

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

void kuszobol(const Mat src, Mat& dest, float ratio = 0.1)
{
	Mat histo;
	createHisto(src, histo);
	double s = 0;
	double osszes = src.rows * src.cols;
	double k = 0;
	for (int i = 0; i < histo.rows; i++)
	{
		s += histo.at<float>(i);
		if (s / osszes > ratio)
		{
			k = i;
			break;
		}
	}
	threshold(src, dest, k, 255, THRESH_BINARY_INV);
}

void onChange_adthreshold(int pos, void* userdata) {
	Mat src = *(cv::Mat*)userdata;
	Mat dest;
	//kuszobold a képet
	//jelenítsd meg az eredményt (dest)
}



int main() {
	/*Mat img = imread("debrecen_deep.png", IMREAD_GRAYSCALE);
	double ah, th;
	minMaxLoc(img, &ah, &th);
	Mat dest = (img - ah) * (255.0 / (th - ah));
	Mat dest2;
	equalizeHist(img, dest2);
	imshow("melyseg",dest);
	imshow("melyseg2", dest2);
	waitKey();*/

	/*Mat dest;
	Mat img = imread("Indian_hybrid_Orange.jpg", IMREAD_COLOR);
	vector<Mat>chs;//3 kép B,G,R
	split(img, chs);
	equalizeHist(chs[0], chs[0]);
	equalizeHist(chs[1], chs[1]);
	equalizeHist(chs[2], chs[2]);
	merge(chs, dest);
	imshow("asdas", dest);
		waitKey();*/

		/*Mat dest,img2,dest2;
		Mat img = imread("Indian_hybrid_Orange.jpg", IMREAD_COLOR);
		cvtColor(img, img2, COLOR_BGR2Lab);
		vector<Mat>chs;//3 kép B,G,R
		split(img2, chs);
		equalizeHist(chs[0], chs[0]);
		merge(chs, dest);
		cvtColor(dest, dest2, COLOR_Lab2BGR);

		imshow("asdas", dest2);
		waitKey();*/
	/*Mat img = imread("szita2.png", IMREAD_COLOR);
	string menu = "tool";
	cv::namedWindow(menu, WINDOW_NORMAL);
	cv::resizeWindow(menu, Size(500, 50));
	int radius = 1, sigma = 1;
	createTrackbar("radius", menu, &radius, 25);
	createTrackbar("sigma", menu, &sigma, 25);
	Mat blur2, gauss, median2, bilat; //üres fejlécek a szűrt képek számára
	while (cv::waitKey(20) != 'q') { //q-ra lép ki
		blur (img, blur2, Size(2 * radius+3 , 2*radius+3));
		imshow("blur", blur2);
		GaussianBlur(img, gauss, Size(2 * radius + 3, 2 * radius + 3), sigma, sigma);
		imshow("gauss", gauss);
		medianBlur(img, median2, 2 * radius + 3);
		imshow("medin", median2);
	}*/
	/*
	int numFrame = 0;
	Mat img = imread("KossuthSquare\\SnapShot-20180731_173715.jpg");
	Mat acc = Mat::zeros(img.size(), CV_64FC3);
	for (int i = 173715; i < 173918; ++i) {
		img = imread("KossuthSquare\\SnapShot-20180731_" + to_string(i) + ".jpg");
		if (!img.empty())
		{
			accumulate(img, acc);
			numFrame++;
			imshow("Kossuth", img);
			waitKey(5);

		}
		Mat dest;
		acc.convertTo(dest, CV_8U, 1.0 / numFrame);
		imshow("dest", dest);
		waitKey(0);
		}*/


	/*
	Mat img = imread("dog.jpg");
	Mat dest;
	threshold(img, dest, 100, 255, THRESH_BINARY);
	//threshold(img, dest, 100, 255, THRESH_OTSU);
	imshow("kutya", dest);*/
	/*
	Mat img = imread("madar.jpg");
	Mat dest;
	vector<Mat> chs;
	split(img, chs);
	//threshold(chs[0], dest, 120, 255, THRESH_BINARY);
	//threshold(chs[0], dest, 100, 255, THRESH_OTSU);
	threshold(chs[0], dest, 120, 255, THRESH_TOZERO);
	imshow("m", dest);
	*/
	/*
	VideoCapture cap;
	cap.open("sas.avi");
	if (!cap.isOpened())
	{
		cout << "Nem nyílt meg" << endl;
		waitKey(0);
		exit(0);
	}
	Mat img, mas, szurke, mask;
	while (1)
	{
		cap >> img;
		if (img.empty())
			break;
		mas = img.clone();
		cvtColor(mas, szurke, COLOR_BGR2GRAY);
		inRange(szurke, 100, 155, mask);
		medianBlur(mask, mask, 5);
		mas.setTo(0, mask);
		imshow("kep", mas);
		waitKey(100);
	}
	*/
	/*
	Mat img = imread("sejtek.png");
	Mat dest;
	int x = 0, y = 0;
	for (int k = 0; k < 255; k+=20)
	{
		threshold(img, dest, k, 255, THRESH_BINARY_INV);
		namedWindow(to_string(k), WINDOW_NORMAL);
		imshow(to_string(k), dest);
		resizeWindow(to_string(k), 300, 300);
		moveWindow(to_string(k), x, y);
		x += 300;
		if (x > 900)
		{
			x = 0;
			y += 330;
		}
	}
	*/
	/*
	Mat img = imread("scanned3.png");
	Mat dest;
	kuszobol(img, dest);
	imshow("s", dest);
	*/
	Mat img = imread("zh.jpg", IMREAD_GRAYSCALE);
	

	waitKey(0);
}





