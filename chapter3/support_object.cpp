#include<opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
    cv::TermCriteria tc;//为算法确定终止条件，构造函数TermCriteria(int type, int maxCount, double epsilon),maxCount表示迭代的终止次数，epsilon表示误差度量终止条件

    cv::Range r;//用于确定一个连续的整数序列，从start到end（左闭右开）
    
    cv::Ptr<cv::Matx33f> pt(new cv::Matx33f);//智能指针，自动处理引用，所有引用消失时自动释放对象

    cv::Exception error;//opencv的异常类继承自std::exception

    cv::DataType<cv::Rect_<int8_t>> temp;//数据模板类, 包含变量和枚举类型

    cv::InputArray input = 10;//表示输入，可以表示所有数组类型，只读 

    cv::OutputArray output ;//表示输出，可以表示所有数组类型，可以修改

    return 0;
}
