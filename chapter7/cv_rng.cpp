#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::RNG rng;
    cv::Mat m1 = cv::Mat(4,4,CV_32S);
    cv::Mat m2 = cv::Mat(4,4,CV_32S);

    rng.fill(m1,cv::RNG::NORMAL,0,10);
    rng.fill(m2,cv::RNG::UNIFORM,0,10);

    return 0;
}
