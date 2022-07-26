#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

struct WarpImage	
{
		const float w = 350, h = 350;
		cv::Mat Img;
	}warp;
	namespace wrp
	{
		struct Side
		{
			cv::Point2f source[4];
			cv::Point2f destination[4] = { { 0.0f, 0.0f }, { warp.w, 0.0f }, { 0.0f, warp.h}, { warp.w,  warp.h } };;

			cv::Mat matrix;
		} yellow, blue, orange;
	}
	void MAIN6()
	{
		std::string path = "D:/STD/Practise/OpenCVTutorial/Resources/Cube.jpg";
		cv::Mat img = cv::imread(path);

		wrp::yellow.source[0] = { 75, 107 };
		wrp::yellow.source[1] = { 216, 155 };
		wrp::yellow.source[2] = { 81, 434 };
		wrp::yellow.source[3] = { 214, 513 };

		wrp::yellow.matrix = cv::getPerspectiveTransform(wrp::yellow.source, wrp::yellow.destination);

		wrp::blue.source[0] = { 77, 101 };
		wrp::blue.source[1] = { 378, 82 };
		wrp::blue.source[2] = { 225, 151 };
		wrp::blue.source[3] = { 540, 122 };

		wrp::blue.matrix = cv::getPerspectiveTransform(wrp::blue.source, wrp::blue.destination);

		wrp::orange.source[0] = { 218, 152 };
		wrp::orange.source[1] = { 542, 137 };
		wrp::orange.source[2] = { 217, 513 };
		wrp::orange.source[3] = { 536, 473 };

		wrp::orange.matrix = cv::getPerspectiveTransform(wrp::orange.source, wrp::orange.destination);

		cv::warpPerspective(img, warp.Img, wrp::yellow.matrix, cv::Point(warp.w, warp.h));
		cv::imshow("Yellow", warp.Img);

		cv::warpPerspective(img, warp.Img, wrp::blue.matrix, cv::Point(warp.w, warp.h));
		cv::imshow("Blue", warp.Img);

		cv::warpPerspective(img, warp.Img, wrp::orange.matrix, cv::Point(warp.w, warp.h));
		cv::imshow("Orange", warp.Img);

		for (int i = 0; i < 4; i++)
		{
			cv::circle(img, wrp::yellow.source[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
			cv::circle(img, wrp::blue.source[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
			cv::circle(img, wrp::orange.source[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
		}
		cv::imshow("Cube", img);

		cv::waitKey(0);
	}