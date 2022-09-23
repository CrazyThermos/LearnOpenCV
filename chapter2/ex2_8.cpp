#include<opencv2/opencv.hpp>
//做两次图像金字塔操作在通过Canny进行边缘检测
int main(int argc, char const *argv[])
{
    /* code */
    cv::Mat img_rgb, img_gry, img_pyr1, img_pyr2, img_cny;
    img_rgb = cv::imread("pic/vim.jpg");
    cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
    cv::pyrDown(img_gry, img_pyr1);
    cv::pyrDown(img_pyr1,img_pyr2);
    cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);
    cv::namedWindow("Example2_8", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example2_8",img_cny);
    cv::waitKey(0);
    return 0;
}
