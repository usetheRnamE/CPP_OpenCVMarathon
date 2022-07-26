#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

void MAIN3()
{
	std::string path = "D:/STD/Practise/OpenCVTutorial/Resources/Cube.jpg";

	cv::Mat img = cv::imread(path);
	cv::Mat imgGS, imgBlur, imgCanny, imgDil, imgEro;

	cv::cvtColor(img, imgGS, cv::COLOR_BGR2GRAY); //convert rgb img to gs img
	cv::GaussianBlur(img, imgBlur, cv::Size(7, 7), 5, 0); //blured img
	cv::Canny(img, imgCanny, 25, 150); // make white borders and black background

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

	cv::dilate(imgCanny, imgDil, kernel); //make cannied img borders thicker
	cv::erode(imgDil, imgEro, kernel); //make cannied img borders thinner

	cv::imshow("Grayed", imgGS);
	cv::imshow("Blured", imgBlur);
	cv::imshow("Cannied", imgCanny);
	cv::imshow("Dilated", imgDil);
	cv::imshow("Eroded", imgEro);

	cv::waitKey(0);
}