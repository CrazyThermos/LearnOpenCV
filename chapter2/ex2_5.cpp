#include<opencv2/opencv.hpp>

void example2_5(const cv::Mat &image){
    //创建窗口展示输入和输出图像
    cv::namedWindow("Example2_5-in",cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example2_5-out",cv::WINDOW_AUTOSIZE);
    //展示输入图片
    cv::imshow("Example2_5-in",image);
    //变量保存输出的平滑图像
    cv::Mat out;

    //使用高斯模糊来平滑图像
    cv::GaussianBlur(image, out, cv::Size(5,5), 3, 3);
    cv::GaussianBlur(out, out, cv::Size(5,5), 3, 3);

    //展示输出图像
    cv::imshow("Example2_5-out", out);

    cv::waitKey(0);
}

int main(int argc, char const *argv[])
{
    cv::Mat image;
    image = cv::imread("pic/vim.jpg");
    example2_5(image);
    return 0;
}
