#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::RNG rng;
    cv::Mat mf = cv::Mat(1,20,CV_32F);
    cv::Mat md = cv::Mat(1,20,CV_64F);
    cv::Mat mu = cv::Mat(1,20,CV_8U);
    cv::Mat mc3 = cv::Mat(1,20,CV_8UC3);

    rng.fill(mf,cv::RNG::UNIFORM,0.,1.);
    rng.fill(md,cv::RNG::NORMAL,0.,1.);
    rng.fill(mu,cv::RNG::UNIFORM,0,255);
    rng.fill(mc3,cv::RNG::UNIFORM,0,255);
    cout<<mf<<endl;
    cout<<md<<endl;
    cout<<mu<<endl;
    cout<<mc3<<endl;
    return 0;
}
