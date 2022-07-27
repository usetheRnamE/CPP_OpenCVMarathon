#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>

enum ObjType {NONE, POINT, LINE, TRIANGLE, RECTANGLE};

std::string ObjName;

void GetContours(cv::Mat& imgDil, cv::Mat& img)
{
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::findContours(imgDil, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	std::vector<std::vector<cv::Point>> conPoly(contours.size());
	std::vector<cv::Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
		if (cv::contourArea(contours[i]) > 1000)
		{
			cv::approxPolyDP(contours[i], conPoly[i], .02 * cv::arcLength(contours[i], true), true);
		
			switch (static_cast<int>(conPoly[i].size()))
			{
			case NONE:
				ObjName = "None";
				break;
			case LINE:
				ObjName = "Line";
				break;
			case TRIANGLE:
				ObjName = "Triangle";
				break;
			case RECTANGLE:
				if (static_cast<float>(boundRect[i].width / boundRect[i].height) > .95
					&& static_cast<float>(boundRect[i].width / boundRect[i].height) < 1.05)
					ObjName = "Squere";
				else
					ObjName = "Recagle";
				break;
			default:
				ObjName = "Multiangle shape";
				break;
			}

			cv::drawContours(img, conPoly, i, cv::Scalar(255, 0, 255), 1);

			boundRect[i] = cv::boundingRect(conPoly[i]);

			cv::rectangle(img, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);

			cv::putText(img, ObjName, { boundRect[i].x, boundRect[i].y }, cv::FONT_HERSHEY_TRIPLEX, .1, cv::Scalar(200, 24, 200), 2);
		}			
}

void main()
{
	std::string path = "D:/STD/Practise/OpenCVTutorial/Resources/Shapes.jfif";
	cv::Mat img = cv::imread(path);

	cv::resize(img, img, cv::Size(640, 480));

	//Preprocess
	cv::Mat imgGS, imgBlur, imgCanny, imgDil, imgEro;

	cv::cvtColor(img, imgGS, cv::COLOR_BGR2GRAY); 
	cv::GaussianBlur(img, imgBlur, cv::Size(7, 7), 5, 0);
	cv::Canny(img, imgCanny, 25, 150);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(6, 6));

	cv::dilate(imgCanny, imgDil, kernel); 
	cv::erode(imgDil, imgEro, kernel); 

	GetContours(imgDil, img);

	cv::imshow("Shapes", img);

	cv::waitKey(0);
}