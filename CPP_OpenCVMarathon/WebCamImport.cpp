#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void MAIN2()
{
	cv::VideoCapture cap(0); // 0 - webcam ID

	cv::Mat img;

	while (true)
	{
		cap.read(img);

		cv::imshow("Cap", img);
		cv::waitKey(1);
	}
}