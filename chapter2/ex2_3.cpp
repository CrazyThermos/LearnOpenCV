#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
/*显示视频*/
int main(int argc, char const *argv[])
{
    /* code */
    cv::namedWindow("Example3",cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open("video/start.mp4");
    cv::Mat frame;
    for(;;){
        cap>>frame;
        if(frame.empty()) break;
        cv::imshow("Example3",frame);
        if(cv::waitKey(33)>=0) break;
    }
    return 0;
}
