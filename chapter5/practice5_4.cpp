#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::Mat matrix = cv::Mat::zeros(210,210,CV_8UC3);
    
    for(int i=0;i<200;i+=20){
        for(int j=0;j<10;j++){
            cv::Point2i lt(i+j,i+j);
            cv::Point2i rb(210-i-j,210-i-j);
            cv::Rect roi(lt,rb);
            cv::rectangle(matrix,roi,cv::Scalar(0,255,0));
        }
        // cv::Point2i lt(i,i);
        // cv::Point2i rb(210-i,210-i);
        // cv::Rect roi(lt,rb);
        // cv::rectangle(matrix,roi,cv::Scalar(0,255,0),5);
    }
    cv::imshow("matrix",matrix);
    cv::waitKey();
    return 0;
}
