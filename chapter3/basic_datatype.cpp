#include<opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
    cv::Point3i p = cv::Point3i(1,1,1);//点类，表示三维或者二维的点，可以转换为固定向量类或者固定矩阵类

    cv::Scalar s = cv::Scalar(1,1,1,1);//四维点类
    
    cv::Size size = cv::Size2i(1,1);//形状类，可以和Point类相互转化，size中只有size.width和size.height
    
    cv::Rect r = cv::Rect2i(1,1,1,1);//矩形类，包括Point2和Size类的变量(x,y,w,h),其中(x,y)表示矩形左上角
    
    cv::RotatedRect rr;//表示图像绕中心点旋转一定角度，需要输入一个中心点Point，一个大小Size，和一个Float型的角度容器
    
    cv::Matx33f m33f;//固定矩阵类，支持1x1到6x6大小的矩阵，操作速度快

    cv::Vec3f v;//固定向量类从固定矩阵类派生出来，可以认为是列为一的Matx类
    
    cv::Complexf c;//复数类型
    
    return 0;
}
