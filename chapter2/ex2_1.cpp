#include<opencv2/opencv.hpp>
/*显示图片*/
int main(int argc, const char** argv) {
    cv::Mat img = cv::imread("pic/vim.jpg");
    if(img.empty()) return -1;
    cv::namedWindow("Example1",cv::WINDOW_AUTOSIZE);
    cv::imshow("Example1",img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
    return 0;
}