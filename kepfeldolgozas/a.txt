#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
/*/
void masolo(const cv::Mat src, cv::Mat& dest)
{
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			cv::Vec3b c = src.at<cv::Vec3b>(i, j);
			if (c[0] != 255 || c[1] != 255 || c[2] != 255)
				dest.at<cv::Vec3b>(i, j) = c;
		}
	}
}
void narancsmasolo(const cv::Mat src, cv::Mat& dest)
{
	dest = cv::Mat::zeros(src.size(), CV_8UC3);

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			cv::Vec3b c = src.at<cv::Vec3b>(i, j);
			if (c[0] < 15 || c[1] < 5 || c[2] > 200)
				dest.at<cv::Vec3b>(i, j) = c;
		}
	}
}
void narancsmasolo(const cv::Mat src, cv::Mat& dest)
{
	cv::Mat hsv;
	cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);
	dest = cv::Mat::zeros(src.size(), CV_8UC3);

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			cv::Vec3b c = hsv.at<cv::Vec3b>(i, j);
			if (c[0] < 77 && c[1] > 0)
				dest.at<cv::Vec3b>(i, j) = src.at<cv::Vec3b>(i, j);
		}
	}
}
*/
void valt(cv::Mat rgb, vector<cv::Mat>& chs)
{
	cv::Mat rgbf, lab;
	rgb.convertTo(rgbf, CV_32FC3, 1.0 / 255.0);
	cv::cvtColor(rgbf, lab, cv::COLOR_BGR2Lab);
	cv::split(lab, chs);
}

int main() {
	/*
	//Beolvasunk egy képet, kiírjuk róla pár cuccot
	cv::Mat img = cv::imread("fizu.jpg", cv::IMREAD_UNCHANGED);
	cout << "szélesség" << img.cols<<endl<<"magasság"<<img.rows<<endl;
	
	if (img.type()==CV_8UC1) {
		cout << "szürke" << endl;
	}
	else if (img.type() == CV_8UC3) {
		cout << "színes" << endl;
	}

	imshow("jajj", img);

	//fekete képet csinálunk ugyanolyan méretűt mint az eredeti
	cv::Mat img2 = cv::Mat::zeros(img.rows,img.cols,CV_8UC1);
	imshow("kolbasz",img2);

	//ocv_gyak1_teljes.pdf referencia buzerálás
	//világosítjuk a képet
	cv::Mat img3 = cv::imread("fizu.jpg",cv::IMREAD_GRAYSCALE);
	cv::Mat img4 = img3 + 100; //Mátrix minden eleméhez hozzáadunk 100at ha túlmenne a tartományon akkor nem megy túl :)
	cv::imshow("világoskép",img4);

	//feladat: invertálás
	cv::Mat img5= cv::imread("fizu.jpg", cv::IMREAD_GRAYSCALE);
	
	if (img5.empty()) {
		cout << "Sikertelen beolvasás!" << endl;
	} else {
		cout << "Sikeres beolvasás!" << endl;
	}

	cv::Mat inv = 255 - img;
	cv::imshow("invertált",img5);
	
	//feladat: mosd össze
	cv::Mat kep0;
	cv::Mat kep1 = cv::imread("hatter.jpg", cv::IMREAD_UNCHANGED);
	cv::Mat kep2 = cv::imread("nap.jpg", cv::IMREAD_UNCHANGED);
	
	resize(kep2,kep0,kep1.size());
	
	double alpha = 0.3;

	cv::Mat result = alpha * kep1 + (1 - alpha) * kep0;
	masolo(kep1,kep2);
	cv::imshow("összemosott",result);
	

	//legelső képpont blabla
	cout << (int)img.at<cv::Vec3b>(0, 0)[0] << endl; //kék
	cout << (int)img.at<cv::Vec3b>(0, 0)[1] << endl; //zöld
	cout << (int)img.at<cv::Vec3b>(0, 0)[2] << endl; //piros


	cv::Mat kep = cv::imread("Indian_hybrid_Orange.jpg", cv::ImreadModes::IMREAD_COLOR);
	cv::Mat kep1;
	narancsmasolo(kep, kep1);
	cv::imshow("összemosott", kep1);
	*/
	cv::Mat etalon = cv::imread("etalon.png", cv::ImreadModes::IMREAD_COLOR);
	cv::imshow("összemosott", etalon);
	vector<cv::Mat> etv;
	valt(etalon, etv);
	cv::Mat img, e;

	for (int i = 0; i < 8; i++)
	{
		img = cv::imread("fa" + to_string(i) + ".png");
		vector<cv::Mat> imv;
		valt(img, imv);
		cv::Mat dL = etv[0] - imv[0];
		cv::Mat da = etv[1] - imv[1];
		cv::Mat db = etv[2] - imv[2];
		cv::Mat dL2 = dL.mul(dL);
		cv::Mat da2 = da.mul(da);
		cv::Mat db2 = db.mul(db);
		cv::sqrt(dL2 + da2 + db2, e);
		cv::Scalar x = cv::mean(e);
	}

	cv::waitKey();


	return 0;
}
