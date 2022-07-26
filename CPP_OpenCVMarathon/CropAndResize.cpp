#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main()
{
	std::string path = "D:/STD/Practise/OpenCVTutorial/Resources/Cube.jpg";

	cv::Mat img = cv::imread(path);
	cv::Mat imgResized1, imgResized2, imgCroped;

	//img.size(); // a size of a image

	cv::resize(img, imgResized1, cv::Size(640, 480)); // set a specific size
	cv::resize(img, imgResized2, cv::Size(), 0.5, 0.5); // scale img in a half

	cv::Rect roi(50, 50, 400, 400);
	imgCroped = img(roi);

	cv::imshow("Resized1", imgResized1);
	cv::imshow("Resized2", imgResized2);
	cv::imshow("Cropped", imgCroped);

	cv::waitKey(0);
}