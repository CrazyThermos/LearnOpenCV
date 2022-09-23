#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("pic/vim.jpg");
    cv::cvtColor(img,img,cv::COLOR_BGR2GRAY);
    cv::Mat array[] = {img,img,img};
    cv::merge(array,3,img);
    cv::Point2i pt(500,500);
    cv::putText(img,"sleeping",pt,cv::FONT_HERSHEY_COMPLEX,5,cv::Scalar(0,0,255));
    cv::imshow("img",img);
    cv::waitKey(0);
    return 0;
}
