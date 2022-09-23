#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cv::Mat matrix = cv::Mat::zeros(100,100,CV_8UC3);
    cv::Point2i center(49,49);
    cv::circle(matrix,center,45,cv::Scalar(0,0,255));
    cv::imshow("matrix",matrix);
    cv::waitKey();
    return 0;
}
