#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("pic/vim.jpg");
    cv::Mat mv[3];
    cv::split(img,mv);
    cv::imshow("green",mv[1]);
    cv::waitKey();
    cv::Mat clone1,clone2;
    mv[1].copyTo(clone1);
    mv[1].copyTo(clone2);

    double max,min;
    cv::minMaxIdx(mv[1],&min,&max);
    cout<<"min:"<<min<<"max:"<<max<<endl;

    uchar threshold = uchar((max-min)/2.0);
    clone1.setTo(threshold);
    cv::compare(mv[1],clone1,clone2,cv::CMP_GE);
    cv::subtract(mv[1],threshold/2,mv[1],clone2);

    cv::imshow("green",mv[1]);
    cv::waitKey();

    return 0;
}
