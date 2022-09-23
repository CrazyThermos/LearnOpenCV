#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
//读取图像的像素数据
void readPixels(cv::Mat &img_rgb, cv::Mat &img_gry, cv::Mat &img_cny, cv::Mat &img_pyr2){
    int x = 16, y = 32;
    cv::Vec3b intensity = img_rgb.at<cv::Vec3b>(y, x);

    uchar blue = intensity[0];
    uchar green = intensity[1];
    uchar red = intensity[2];

    cout<<"At(x,y)=("<<x<<","<<y<<"):(blue, green, red) = ("<<(unsigned int)blue<<","<<(unsigned int)green<<","<<(unsigned int)red<<")"<<endl;
    cout<<"Gray pixel there is:"<<(unsigned int)img_gry.at<uchar>(y, x)<<endl;
    x/=4;y/=4;
    cout<<"Pyramid2 pixel there is:"<<(unsigned int)img_pyr2.at<uchar>(y, x)<<endl;
    img_cny.at<uchar>(x, y) = 128;
}


int main(int argc, char const *argv[])
{
    /* code */
    cv::Mat img_rgb, img_gry, img_pyr1, img_pyr2, img_cny;
    img_rgb = cv::imread("pic/vim.jpg");
    cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::pyrDown(img_gry, img_pyr1);
    cv::pyrDown(img_pyr1,img_pyr2);
    cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);
    readPixels(img_rgb,img_gry,img_cny,img_pyr2);
    cv::namedWindow("Example2_8", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example2_8",img_cny);
    cv::waitKey(0);
    return 0;
}
