#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("./pic/0000296_01001_d_0000040.jpg");
    size_t src_w = img.cols;
    size_t src_h = img.rows;
    uint32_t dst_w = 640;
    uint32_t dst_h = 640;

    if (src_h != dst_h || src_w != dst_w) {
      cv::Mat dst(dst_h, dst_w, CV_8UC3, cv::Scalar(0, 0, 0));
      const float scaling_factors = std::min(1.0 * dst_w / src_w, 1.0 * dst_h / src_h);
      cv::Mat resized(src_h * scaling_factors, src_w * scaling_factors, CV_8UC3);
      cv::resize(img, resized, cv::Size(resized.cols, resized.rows));
      cv::Rect roi;
      roi.x = (dst.cols - resized.cols) / 2;
      roi.y = (dst.rows - resized.rows) / 2;
      roi.width = resized.cols;
      roi.height = resized.rows;

      resized.copyTo(dst(roi));
      img = dst;
    }
    cv::imshow("img",img);
    cv::waitKey();
        return 0;
}
