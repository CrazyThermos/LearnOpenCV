#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::RNG rng;
    cv::Mat data = cv::Mat(4,4,CV_32F);
    cv::Mat W;
    cv::Mat U;
    cv::Mat Vt;

    rng.fill(data,cv::RNG::UNIFORM,0,1);
    cv::SVD svd(data);
    svd.compute(data,W,U,Vt);
    cout<<"data:\n"<<data<<endl;
    cout<<"W:\n"<<W<<endl;
    cout<<"U:\n"<<U<<endl;
    cout<<"Vt:\n"<<Vt<<endl;
    
    return 0;
}
