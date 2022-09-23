#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cv::namedWindow("Example2_10",cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    if(argc){
        cap.open(0);
    }
    else{
        cap.open(argv[1]);
    }
    if(!cap.isOpened()){
        cerr<<"Couldn't open capture."<<endl;
        return -1;
    }
    cv::Mat frame;
    for(;;){
        cap>>frame;
        if(frame.empty()) break;
        cv::imshow("Example3",frame);
        if(cv::waitKey(33)>=0) break;
    }
    return 0;
}
