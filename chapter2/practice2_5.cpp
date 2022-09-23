#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<fstream>

using namespace std;
int scale = 0;
int level = 7;
void onTarckbaSlide(int pos, void *){
    scale = pos;
    cout<<scale<<endl;
}

int main(int argc, char const *argv[])
{
    

    cv::namedWindow("Pyrd", cv::WINDOW_GUI_EXPANDED);

    cv::VideoCapture cap;
    cap.open("video/start.mp4");

    cv::createTrackbar("Postion","Pyrd",&scale,level,onTarckbaSlide);
    
    //cv::VideoWriter writer;
    //writer.open("video/start2.mp4", cv::VideoWriter::fourcc('M','J','P','G'), fps, size);
    cv::Mat pyr_frame, bgr_frame;
    for(;;){
        cap>>bgr_frame;
        if(bgr_frame.empty()) break;

        //int current_pos = (int)cap.get(cv::CAP_PROP_POS_FRAMES);
        //cv::setTrackbarPos("Postion","Pyrd",current_pos);
 
        //cv::imshow("Input", bgr_frame);
        //cv::logPolar(bgr_frame, pyr_frame, cv::Point2f(bgr_frame.cols/2, bgr_frame.rows/2),40,cv::WARP_FILL_OUTLIERS);

        //cout<<bgr_frame<<endl;
        pyr_frame = bgr_frame;
        for (int i = 0; i < scale; i++)
        {
            cv::pyrDown(pyr_frame, pyr_frame);
        }
        cv::imshow("Pyrd", pyr_frame);
        //writer<<pyr_frame;

        char c = cv::waitKey(10);
        if(c == 'q') break;
    }

    cap.release();
    return 0;
}
