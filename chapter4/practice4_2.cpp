#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
     int w = 200,h = 100;
    cv::RNG rng;
    cv::Mat img_fp = cv::Mat(h,w,CV_32FC1);
    cv::Mat img_uc = cv::Mat(h,w,CV_8UC1);
    rng.fill(img_fp,cv::RNG::NORMAL,0,1);
    rng.fill(img_uc,cv::RNG::NORMAL,0,255);

    // cv::Mat imgE = cv::Mat(101,201,CV_16FC1,cv::Scalar(0.f));
    cv::Mat imgSum_fp = cv::Mat(h+1,w+1,CV_32FC1,cv::Scalar(0.f));
    cv::Mat imgSum_uc = cv::Mat(h+1,w+1,CV_8UC1,cv::Scalar(0));
    // imgSum_fp.copyTo(imgE(cv::Range(1,101),cv::Range(1,201)));
    // cout<<imgSum_fp<<endl;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            // cout<<i<<","<<j<<endl;
            // cout<<img_fp.at<uint8_t>(0,0)<<endl;
            // cout<<imgSum_fp.at<float>(i-1,j)<<","<<imgSum_fp.at<float>(i,j-1)<<","<<imgSum_fp.at<float>(i-1,j-1)<<","<<img_fp.at<float>(i-1,j-1)<<endl;
            if(imgSum_fp.at<float>(i-1,i)+imgSum_fp.at<float>(i,j-1)-imgSum_fp.at<float>(i-1,j-1)+img_fp.at<float>(i-1,j-1)>=1.f){
                imgSum_fp.at<float>(i,j)=1.f;    
            }
            else{
                imgSum_fp.at<float>(i,j) = imgSum_fp.at<float>(i-1,j)+imgSum_fp.at<float>(i,j-1)-imgSum_fp.at<float>(i-1,j-1)+img_fp.at<float>(i-1,j-1);
            }
            if(imgSum_uc.at<uchar>(i-1,j)+imgSum_uc.at<uchar>(i,j-1)-imgSum_uc.at<uchar>(i-1,j-1)+img_uc.at<uchar>(i-1,j-1)>=255){
                imgSum_uc.at<uchar>(i,j)=255;    
            }
            else{
                imgSum_uc.at<uchar>(i,j) = imgSum_uc.at<uchar>(i-1,j)+imgSum_uc.at<uchar>(i,j-1)-imgSum_uc.at<uchar>(i-1,j-1)+img_fp.at<uchar>(i-1,j-1);
            }
        }
    }

    // cout<<img_uc<<endl;
    // cout<<imgSum_uc<<endl;
    cv::imshow("input1",img_fp);
    cv::imshow("output1",imgSum_fp);
    cv::imshow("input2",img_uc);
    cv::imshow("output2",imgSum_uc);

    //计算45度旋转矩形的和

    cv::waitKey();
    return 0;
}
