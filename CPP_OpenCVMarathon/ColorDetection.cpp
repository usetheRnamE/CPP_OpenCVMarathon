#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

/*namespace clr
{
	struct ColorSettings
	{
		int h, s, v;
	} min, max;
}*/

int minH, minS, minV;
int maxH, maxS, maxV;

void MAIN7()
{
	std::string path = "D:/STD/Practise/OpenCVTutorial/Resources/Cube.jpg";
	cv::Mat img = cv::imread(path);

	cv::Mat imgHSV, mask;

	cv::namedWindow("Orange", (640, 200));

	cv::createTrackbar("hue min", "Orange", &minH, 179);
	cv::createTrackbar("hue max", "Orange", &maxH, 179);
	cv::createTrackbar("sat min", "Orange", &minS, 255);
	cv::createTrackbar("sat max", "Orange", &maxS, 255);
	cv::createTrackbar("val min", "Orange", &minV, 255);
	cv::createTrackbar("val max", "Orange", &maxV, 255);

	while (true)
	{
		cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

		cv::Scalar min(minH, minS, minV);
		cv::Scalar max(maxH, maxS, maxV);

		cv::inRange(imgHSV, min, max, mask);
		cv::imshow("Orange mask", mask);

		cv::imshow("Cube", img);
		cv::imshow("Cube HSV", imgHSV);

		cv::waitKey(1);
	}
}
