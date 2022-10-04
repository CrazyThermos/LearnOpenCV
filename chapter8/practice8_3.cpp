#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
cv::Rect rect;
void onMouse(int event, int x, int y, int flags, void* param);
void showHist(cv::Mat roi);
void onMouse(int event, int x, int y, int flags, void* param){
    cv::Mat *im = reinterpret_cast<cv::Mat*>(param);
    // string str;
    cv::Vec3b pixel;
    cv::Mat roi;
    switch (event)
    {
    case cv::EVENT_LBUTTONDOWN:
        cout<<"("<<x<<","<<y<<")"<<endl;
        rect.x = x;
        rect.y = y;
        cv::circle(*im,cv::Point2i(x,y),1,cv::Scalar(255,255,0));
        break;
    case cv::EVENT_LBUTTONUP:
        cout<<"("<<x<<","<<y<<")"<<endl;
        rect.width = x - rect.x;
        cv::circle(*im,cv::Point2i(x,y),1,cv::Scalar(255,255,0));
        //  (*im)(lt,rb).copyTo(roi);
        showHist(roi);
        // cout<<lt.start<<lt.end<<endl;
        // cout<<rb.start<<rb.end<<endl;
        break;
    default:
        break;
    }

    
}

void showHist(cv::Mat roi){
    cv::namedWindow("Statistics",cv::WINDOW_AUTOSIZE);
    cv::Mat stat = cv::Mat(400,400,CV_8UC3,cv::Scalar(0,0,0));
    int blue[8];
    int green[8];
    int red[8];
    memset(blue,0,sizeof(blue));
    memset(green,0,sizeof(green));
    memset(red,0,sizeof(red));

    cv::MatIterator_<cv::Vec3b> it = roi.begin<cv::Vec3b>();
    cv::MatIterator_<cv::Vec3b> end = roi.end<cv::Vec3b>();
    for(;it!=end;it++){
        int b = (int)(*it).val[0];
        int g = (int)(*it).val[1];
        int r = (int)(*it).val[2];

        blue[b/32]  +=1;
        green[g/32] +=1; 
        red[r/32]   +=1; 
    }
    int start = 25;
    for(int i=0;i<7;i++){
        cv::line(stat,cv::Point2i(start*(i+1),blue[i]),cv::Point2i(start*(i+2),blue[i+1]),cv::Scalar(255,0,0));       
        cv::line(stat,cv::Point2i(start*(i+1),green[i]),cv::Point2i(start*(i+2),green[i+1]),cv::Scalar(0,255,0));       
        cv::line(stat,cv::Point2i(start*(i+1),red[i]),cv::Point2i(start*(i+2),red[i+1]),cv::Scalar(0,0,255));       
    }
    cv::imshow("Statistics",stat);
}

int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("pic/vim.jpg");
    cv::Mat bak = img.clone();
    cv::namedWindow("Practice8_3",cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("Practice8_3",onMouse,reinterpret_cast<void*>(&img));
    while(1){
        cv::imshow("Practice8_3", img);
        char c = cv::waitKey(10);
        if(c == 'q') break;
        
    }
    return 0;
}
