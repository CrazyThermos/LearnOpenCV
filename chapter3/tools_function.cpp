#include<opencv2/opencv.hpp>
int main(int argc, char const *argv[])
{
    int *p = NULL;
    size_t sz = 1024;
    
    cv::alignPtr(p,10);//根据(T*)(((size_t)ptr + n + 1) & -n)计算一个相同类型的指针
    
    cv::alignSize(sz,10);//计算包含n个整数对象的缓冲区大小，公式为(sz + n - 1) & -n

    cv::fastAtan2(1,2);//改函数计算了下x,y对的正反切并且返回圆心到该点的角度

    
    return 0;
}
