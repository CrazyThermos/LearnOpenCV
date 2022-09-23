#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("pic/vim.jpg");
    cv::Rect2i rect1(5,10,20,30);
    cv::Rect2i rect2(50,60,20,30);
    cv::Mat roiImg1 = img(rect1);
    cv::Mat roiImg2 = img(rect2);

    cv::bitwise_not(roiImg1,roiImg1);
    cv::bitwise_not(roiImg2,roiImg2);
    roiImg1.copyTo(img(rect1));
    roiImg2.copyTo(img(rect2));

    cv::imshow("img",img);
    cv::waitKey(0);
    return 0;
}
