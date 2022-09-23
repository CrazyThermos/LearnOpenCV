#include<opencv2/opencv.hpp>
#include <ctime>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cv::VideoCapture cap(0);
    double fps;
    int frameCount=0;
    int tick=0;
    std::time_t timeBegin = std::time(0);
    for (;;)
    {
        cv::Mat frame;
        cap>>frame;
        if(frame.empty()) break;
        frameCount++;
        std::time_t timeNow = std::time(0) - timeBegin;
        // cout<<timeNow<<endl;
        if (timeNow - tick >= 1)
        {
            tick++;
            fps = frameCount;
            frameCount = 0;
        }
        // fps = cap.get(cv::CAP_PROP_FPS);

        cv::putText(frame,cv::format("Average FPS=%lf", fps ),cv::Point2f(30,30),cv::FONT_HERSHEY_PLAIN,1,cv::Scalar(255,0,0));
        cv::namedWindow("practice6_3", cv::WINDOW_AUTOSIZE);
        cv::imshow("frame",frame);
        char c = cv::waitKey(10);
        if(c=='q') break;
    }
    cap.release();
    
    return 0;
}
