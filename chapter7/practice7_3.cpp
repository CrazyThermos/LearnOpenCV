#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::RNG rng;
    cv::Mat mv[3];
    cv::Mat mv[0] = cv::Mat(10,10,CV_8UC1,cv::Scalar(0,0,0));
    cv::Mat mv[1] = cv::Mat(10,10,CV_8UC1,cv::Scalar(0,0,0));
    cv::Mat mv[2]= cv::Mat(10,10,CV_8UC1,cv::Scalar(0,0,0));
    rng.fill(mv[0],cv::RNG::NORMAL,64,10);
    rng.fill(mv[1],cv::RNG::NORMAL,192,10);
    rng.fill(mv[2],cv::RNG::NORMAL,128,2);
    
    cv::Mat m = cv::Mat(10,10,CV_8UC3);
    cv::merge(mv,3,m);
    cv::PCA pca(m,cv::Mat(),cv::PCA::DATA_AS_ROW);
    int maxComponents=2;
    pca.operator()(m,cv::Mat(),cv::PCA::DATA_AS_ROW,maxComponents);
    

    return 0;
}
