#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cv::Mat matrix = cv::Mat::zeros(100,100,CV_8UC3);
    cv::Point2i lt(20,5);
    cv::Point2i rb(40,20);
    cv::Rect2i rect(lt,rb);
    cv::rectangle(matrix,rect,cv::Scalar(255,0,0));
    cv::imshow("matrix",matrix);
    cv::waitKey();
    return 0;
}
