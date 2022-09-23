#include<opencv2/opencv.hpp>
#include<iostream>

int main(int argc, char const *argv[])
{
    cv::namedWindow("Example2_11", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

    cv::VideoCapture cap(0);

    double fps = cap.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
        (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
    );

    cv::VideoWriter writer;
    writer.open("video/start2.mp4", cv::VideoWriter::fourcc('M','J','P','G'), fps, size);

    cv::Mat logpolar_frame, bgr_frame;
    for(;;){
        cap>>bgr_frame;
        if(bgr_frame.empty()) break;

        cv::imshow("Example2_11", bgr_frame);
        cv::logPolar(bgr_frame, logpolar_frame, cv::Point2f(bgr_frame.cols/2, bgr_frame.rows/2),40,cv::WARP_FILL_OUTLIERS);

        cv::imshow("Log_Polar", logpolar_frame);
        writer<<logpolar_frame;

        char c = cv::waitKey(10);
        if(c=='q') break;
    }

    cap.release();
    return 0;
}
