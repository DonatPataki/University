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
	double max = 0, max2 = 0;
	int maxh = -1, maxh2 = -1;

	Mat img, hsv, mask, cont;
	Mat data(50 * 3, 3, CV_32F);
	Mat labels(50 * 3, 1, CV_32S);
	int idx = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 50; ++j) {
			labels.at<int>(idx) = i;
			img = imread("Dataset2/train/" + to_string(i) + "/" + to_string(j) + ".png");
			cvtColor(img, hsv, COLOR_BGR2HSV);
			inRange(hsv, Scalar(0, 30, 0), Scalar(30, 255, 255), mask);



			vector<vector<cv::Point>> conts;
			findContours(mask.clone(), conts, RETR_EXTERNAL, CHAIN_APPROX_NONE);
			vector<Point>maxc;

			int maxh = -1, maxh2 = -1;
			double max = 0, max2 = 0;

			for (int i = 0; i < conts.size(); ++i) {
				double t = contourArea(conts[i]);
				if (t > max) {
					max = t;
					maxh = i;
				}

			}


			//maxc = conts[maxh];




			Rect r = boundingRect(conts[maxh]);
			double x = r.height / r.width;
			double t = contourArea(conts[maxh]);
			double k = arcLength(conts[maxh], true);

			data.at<float>(idx, 0) = x;
			data.at<float>(idx, 1) = t;
			data.at<float>(idx, 2) = k;



			idx++;
		}

	vector<double>means, sigmas;
	cout << data << endl;
	for (int i = 0; i < data.cols; ++i) {
		cv::Scalar mean, sigma;
		meanStdDev(data.col(i), mean, sigma);
		data.col(i) = (data.col(i) - mean[0]) / sigma[0];
		means.push_back(mean[0]);
		sigmas.push_back(sigma[0]);
	}

	Ptr<TrainData> td = TrainData::create(data, ROW_SAMPLE, labels);

	Ptr<ml::SVM> model = ml::SVM::create();
	model->setKernel(SVM::KernelTypes::LINEAR);
	model->setType(SVM::C_SVC); // félreosztáylozás büntetése C
	model->setC(1); //bütetés mértéke
	model->train(td);

	model->save("nev.yml");

	Mat mv(means); //konvertáld a vektort
	Mat ms(sigmas); //konvertáld a sigma vektort
	FileStorage fs; //opencv fájlkezelője
	fs.open("mean_sigma.json", FileStorage::WRITE);
	fs << "means" << mv; // egy mátrix kiírása
	fs << "sigmas" << mv; // egy mátrix kiírása
	fs.release();*/
	

	//masik program


	Mat data2(1, 3, CV_32F);

	Ptr<ml::SVM> model = SVM::load("nev.yml");

	Mat means, sigmas; //ezekbe olvassuk az értékeket
	FileStorage fs;
	fs.open("mean_sigma.json", FileStorage::READ);
	fs["means"] >> means;
	fs["sigmas"] >> sigmas;
	fs.release();

	Mat hsv, mask;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 25; ++j) {

			Mat img = imread("Dataset2/test/" + to_string(i) + "/" + to_string(j) + ".png");

			cvtColor(img, hsv, COLOR_BGR2HSV);
			inRange(hsv, Scalar(0, 30, 0), Scalar(30, 255, 255), mask);



			vector<vector<cv::Point>> conts;
			findContours(mask.clone(), conts, RETR_EXTERNAL, CHAIN_APPROX_NONE);
			vector<Point>maxc;

			int maxh = -1, maxh2 = -1;
			double max = 0, max2 = 0;

			for (int i = 0; i < conts.size(); ++i) {
				double t = contourArea(conts[i]);
				if (t > max) {
					max = t;
					maxh = i;
				}

			}


			//maxc = conts[maxh];




			Rect r = boundingRect(conts[maxh]);
			double x = r.height / r.width;
			double t = contourArea(conts[maxh]);
			double k = arcLength(conts[maxh], true);

			data2.at<float>(0, 0) = x;
			data2.at<float>(0, 1) = t;
			data2.at<float>(0, 2) = k;

			for (int j = 0; j < 3; ++j) {
				data2.at<float>(j) = (data2.at<float>(j) - means.at<double>(j)) / sigmas.at<double>(j);
			}
			int lsl = model->predict(data2);


			imshow(to_string(lsl), img);
			resizeWindow(to_string(lsl), Size(300, 300));
			waitKey(100);
		}
	return 0;
}
