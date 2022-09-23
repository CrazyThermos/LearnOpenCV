#include<opencv2/opencv.hpp>
/*Canny边缘检测器输出一单通道的灰度图像*/
int main(int argc, char const *argv[])
{
    /* code */
    cv::Mat img_rgb, img_gry, img_cny;
    cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

    img_rgb = cv::imread("pic/vim.jpg");
    
    cv::cvtColor(img_rgb,img_gry,cv::COLOR_BGR2GRAY);
    cv::imshow("Example Gray", img_gry);
    
    cv::Canny(img_gry, img_cny, 10, 100, 3, true);//边缘检测器
    cv::imshow("Example Canny",img_cny);
    
    cv::waitKey(0);
    return 0;
}
