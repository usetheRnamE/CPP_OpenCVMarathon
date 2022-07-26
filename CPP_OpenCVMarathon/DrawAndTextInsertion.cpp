#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void MAIN5()
{
	cv::Mat img(640, 480, CV_8UC3, cv::Scalar(255, 0, 255));

	cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(78, 40, 75), 10); // 10 -> thicknes of a board line, FILLED -> to make a filled circle
	cv::rectangle(img, cv::Point(256, 256), cv::Point(123, 123), cv::Scalar(45, 40, 34), 10);
	cv::line(img, cv::Point(256, 256), cv::Point(123, 123), cv::Scalar(43, 87, 24), 10);

	cv::putText(img, "rosni pizda", cv::Point(262, 262), cv::FONT_HERSHEY_PLAIN, 2, cv::Scalar(52, 98, 56), 2);

	cv::imshow("PurpleShit", img);
	cv::waitKey(0);
}