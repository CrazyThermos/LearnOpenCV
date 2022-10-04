#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<fstream>

using namespace std;
/*使用带滚动条的窗口*/
int g_slider_position = 0;//滚动条的开始位置
int g_run = 1, g_dontset = 0;//g_run为正数时，代表播放多少张图片后停止；g_run为负数时，开启自动播放模式。
cv::VideoCapture g_cap;

void onTarckbaSlide(int pos, void *){
    g_cap.set(cv::CAP_PROP_POS_FRAMES,pos);
    if(!g_dontset)//避免在调整进度条时触发单步模式
        g_run = 1;
    g_dontset = 0;
}

int main(int argc, char const *argv[])
{

    cv::namedWindow("Example2_4",cv::WINDOW_AUTOSIZE);
    g_cap.open("video/start.mp4");
    int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cout<<"Video has"<<frames<<"frames og demensions("<<tmpw<<","<<tmph<<")."<<endl;
    cv::createTrackbar("Postion","Example2_4",&g_slider_position,frames,onTarckbaSlide);
    cv::Mat frame;
    for(;;){
        if(g_run != 0){
            g_cap>>frame;
            if(frame.empty()) break;
            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            cv::setTrackbarPos("Postion","Example2_4",current_pos);
            cv::imshow("Example2_4",frame);

            g_run -= 1;
        }

        char c = (char)cv::waitKey(10);
        if(c == 's'){
            g_run = 1;
            cout<<"Singer step, run = "<<g_run<<endl;
        }
        if(c == 'r'){
            g_run = -1;
            cout<<"Run mode, run = "<<g_run<<endl;
        }
        if(c == 27){
            break;
        }
        
    }
    return 0;
}
