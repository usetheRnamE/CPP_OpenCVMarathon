#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void MAIN0()
{
	std::string path = "Resources/Cube.jpg";
	cv::Mat img = cv::imread(path);
	imshow("Cube", img);

	cv::waitKey(0);
}