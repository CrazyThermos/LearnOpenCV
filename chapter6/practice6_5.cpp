#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::Mat img = cv::Mat::zeros(500,500,CV_8UC3);
    cv::Point2i a(10,10);
    cv::Point2i b(400,400);
    cv::Point2i c(100,100);
    cv::Point2i d(100,200);

    cv::line(img,a,b,cv::Scalar(123,32,141));
    cv::line(img,c,d,cv::Scalar(13,132,11));

    cv::imshow("img",img);
    cv::LineIterator it4 = cv::LineIterator(a,b,4);
    cv::LineIterator it8 = cv::LineIterator(a,b,8);
    cout<<"from ("<<a.x<<","<<a.y<<") to ("<<b.x<<","<<b.y<<")"<<endl;
    cout<<"pixel count with connectivity = 4 :"<<it4.count<<endl;
    cout<<"pixel count with connectivity = 8 :"<<it8.count<<endl;

    cv::LineIterator it4_ = cv::LineIterator(c,d,4);
    cv::LineIterator it8_ = cv::LineIterator(c,d,8);
    cout<<"from ("<<c.x<<","<<c.y<<") to ("<<d.x<<","<<d.y<<")"<<endl;
    cout<<"pixel count with connectivity = 4 :"<<it4_.count<<endl;
    cout<<"pixel count with connectivity = 8 :"<<it8_.count<<endl;
    
    cv::waitKey();
    return 0;
}
