#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::RNG rng;
    cv::Mat mf = cv::Mat(1,3,CV_32F);
    cv::Mat md = cv::Mat(1,3,CV_64F);
    cv::Mat mu = cv::Mat(1,3,CV_8U);
    rng.fill(mf,cv::RNG::UNIFORM,0.,1.);
    rng.fill(md,cv::RNG::NORMAL,0.,1.);
    rng.fill(mu,cv::RNG::UNIFORM,0,255);
    cout<<mf<<endl;
    cout<<md<<endl;
    cout<<mu<<endl;

    return 0;
}
