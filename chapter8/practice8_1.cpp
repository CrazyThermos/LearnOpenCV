#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cv::namedWindow("Output",cv::WINDOW_NORMAL);
    cv::VideoCapture cap;
    cap.open("video/ZRL2.mp4");
    double fps = cap.get(cv::CAP_PROP_FPS);
    cv::Size sz(
        (int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
        (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
    );
    cv::Mat output = cv::Mat(sz.height,sz.width*3,CV_8UC3);
  
    // shared_ptr<cv::Mat> ori_frame, gray_frame, canny_frame; 
    cv::Mat ori_frame, gray_frame, canny_frame; 

    // ori_frame  = output( cv::Range(0,0), cv::Range(sz.height,sz.width/3)); 
    // ori_frame = output.colRange(0,sz.width/3);
    for(;;){
        cap>>ori_frame;
        if(ori_frame.empty()) break;
        cv::cvtColor(ori_frame,gray_frame,cv::COLOR_BGR2GRAY);
        cv::Canny(ori_frame, canny_frame, 50, 255);
        // cv::imshow("0",ori_frame); 
        // cv::imshow("1",gray_frame);
        // cv::imshow("2",canny_frame);
        cv::Mat gray_frame_c3, canny_frame_c3;
        gray_frame_c3 = cv::Mat(sz.height,sz.width,CV_8UC3);
        canny_frame_c3 = cv::Mat(sz.height,sz.width,CV_8UC3);
        cv::cvtColor(gray_frame, gray_frame_c3, cv::COLOR_GRAY2BGR);
        cv::cvtColor(canny_frame, canny_frame_c3, cv::COLOR_GRAY2BGR);


        ori_frame.copyTo(output(cv::Rect(0,0,sz.width,sz.height)));
        gray_frame_c3.copyTo(output(cv::Rect(sz.width,0,sz.width,sz.height)));
        canny_frame_c3.copyTo(output(cv::Rect(sz.width*2,0,sz.width,sz.height)));

        cv::imshow("Output",output);
        char c = cv::waitKey(10);
        if(c == 'q') break;
    }
    cap.release();

    return 0;
}
