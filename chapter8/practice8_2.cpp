#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
void onMouse(int event, int x, int y, int flags, void* param);
void onMouse(int event, int x, int y, int flags, void* param){
    cv::Mat *im = reinterpret_cast<cv::Mat*>(param);
    string str;
    cv::Vec3b pixel;
    switch (event)
    {
    case cv::EVENT_LBUTTONDOWN:
        cout<<"("<<x<<","<<y<<")"<<endl;
        pixel = (*im).at<cv::Vec3b>(x,y);
        str = "("+to_string(x)+","+to_string(y)+") = R:"+to_string(pixel[2])+" G:"+to_string(pixel[1])+" B:"+to_string(pixel[0]);
        cv::putText(*im,str,cv::Point2i(x,y),cv::FONT_HERSHEY_COMPLEX,0.5,cv::Scalar(0,0,255));
        break;
    default:
        break;
    }
}

int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("pic/vim.jpg");
    cv::Mat bak = img.clone();
    cv::namedWindow("Practice8_2",cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("Practice8_2",onMouse,reinterpret_cast<void*>(&img));
    while(1){
        cv::imshow("Practice8_2", img);
        char c = cv::waitKey(10);
        if(c == 'q') break;
        
    }
    return 0;
}
