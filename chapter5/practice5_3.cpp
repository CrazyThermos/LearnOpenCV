#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cv::Mat matrix = cv::Mat::zeros(100,100,CV_8UC3);
    
    for (int i = 20; i < 40; i++)
    {
        uchar* data = matrix.ptr<uchar>(i);
        for (int j = 5; j < 20; j++)
        {
            data[3*j] = 0;
            data[3*j+1] = 255;            
            data[3*j+2] = 0;            

        }
        
    }
    cv::imshow("matrix",matrix);
    cv::waitKey();
    return 0;
}
