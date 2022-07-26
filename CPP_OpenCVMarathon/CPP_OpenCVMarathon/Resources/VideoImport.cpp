#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void MAIN1()
{
	std::string path = "Resources/Video.mp4";
	cv::VideoCapture cap(path);

	cv::Mat img;

	while (true)
	{
		cap.read(img);

		cv::imshow("Cap", img);
		cv::waitKey(20);
	}
}