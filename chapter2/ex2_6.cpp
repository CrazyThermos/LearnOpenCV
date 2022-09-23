#include<opencv2/opencv.hpp>
/*缩放图像到一半*/
int main(int argc, char const *argv[])
{
    /* code */
    cv::Mat img1,img2;
    cv::namedWindow("Example1",cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Exanple2",cv::WINDOW_AUTOSIZE);
    
    img1 = cv::imread("pic/vim.jpg");
    cv::pyrDown(img1, img2);
    
    cv::imshow("Example2", img2);
    cv::waitKey(0);
    
    return 0;
}
