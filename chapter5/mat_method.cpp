#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
int main(int argc, char const *argv[])
{   
    cv::RNG rng;
    cv::Mat ma = cv::Mat(10,10,CV_32F);
    cv::Mat mb = cv::Mat(10,10,CV_32F);
    cv::Mat mc = cv::Mat(10,10,CV_32F);
    // cv::Mat mc;
    cv::Mat mask = cv::Mat::ones(cv::Size(10,10),CV_32S);
    rng.fill(ma,cv::RNG::UNIFORM,0,10);
    rng.fill(mb,cv::RNG::UNIFORM,0,10);
    cout<<"ma:"<<ma<<endl;
    cout<<"mb:"<<mb<<endl;

    cout<<"cv::abs(ma):\n"<<cv::abs(ma)<<endl;
    cv::absdiff(ma,mb,mc);//差的绝对值
    cout<<"cv::absdiff(ma,mb,mc):\n"<<mc<<endl;
    cv::Rect rect(0,0,5,5);
    cv::add(ma,mb,mc);
    cout<<"cv::add(ma,mb,mc):\n"<<mc<<endl;
    cv::addWeighted(ma,-0.5,mb,0.5,255,mc);
    cout<<"cv::addWeighted(ma,-0.5,mb,0.5,255,mc)://ma*(-0.5)+mb*0.5+255\n"<<mc<<endl;
    //ex5-1
    cv::Mat src1 = cv::imread("pic/vim.jpg");
    cv::Mat src2 = cv::imread("pic/0000296_01001_d_0000040.jpg");
    cv::Mat roi1(src1,cv::Rect(255,255,255,255));
    cv::Mat roi2(src2,cv::Rect(100,100,255,255));
    cv::addWeighted(roi1, 0.2, roi2, 0.5, 0.0, roi1);
    cv::imshow("Alpha Blend",roi1);
    cv::waitKey();

    cv::bitwise_and( ma, mb, mc);
    cout<<"cv::bitwise_and( ma, mb, mc):\n"<<mc<<endl;
    //bitwise_and = &
    //bitwise_xor = ^
    //bitwise_not = ~
    //bitwise_or  = |
    cv::Mat samples[3];
    samples[0]=cv::Mat(1,3,CV_32F);
    samples[1]=cv::Mat(1,3,CV_32F);
    samples[2]=cv::Mat(1,3,CV_32F);
    rng.fill(samples[0],cv::RNG::UNIFORM,0,10);
    rng.fill(samples[1],cv::RNG::UNIFORM,0,10);
    rng.fill(samples[2],cv::RNG::UNIFORM,0,10);

    cv::Mat_<float> covar;
    cv::Mat_<float> mean;
    cv::calcCovarMatrix(samples,3,covar,mean,cv::COVAR_NORMAL);//计算均值和协方差相关的函数
    cout<<"cv::calcCovarMatrix(samples,covar,mean,cv::COVAR_NORMAL):\n"<<"covar=\n"<<covar<<"mean=\n"<<mean<<endl;

    cv::Mat magnitude;
    cv::Mat angle;
    cv::cartToPolar(ma,mb,magnitude,angle);//转换成极坐标
    cout<<"cv::cartToPolar(ma,mb,magnitude,angle):\n"<<"magnitude:\n"<<magnitude<<"angle:\n"<<angle<<endl;

    cout<<"cv::checkRange(ma,true,0,0,255):"<<cv::checkRange(ma,true,0,0,255)<<endl;

    cv::compare(ma,mb,mc,cv::CMP_EQ);
    cout<<"cv::compare(ma,mb,mc,cv::CMP_EQ):"<<mc<<endl;

    cout<<"cv::completeSymm(mc):\n"<<"mc:\n"<<mc<<endl;
    cv::completeSymm(mc);
    cout<<"mcSymm:\n"<<mc<<endl;

    cv::convertScaleAbs(ma,mc,0.5,25); //dst=saturate(|a*src+b|);
    cout<<"cv::convertScaleAbs(ma,mc,0.5,25):\n"<<mc<<endl;

    cout<<"cv::countNonZero(ma):"<<cv::countNonZero(ma)<<endl;//返回mtx中的非0像素数
    
    cv::dct(ma,mc,cv::DCT_INVERSE);//离散余弦变换
    cout<<"cv::dct(ma,mc,cv::DCT_INVERSE):\n"<<mc<<endl;

    cv::dft(ma,mc,cv::DFT_ROWS);//离散傅里叶变换
    cout<<"cv::dft(ma,mc,cv::DFT_ROWS):\n"<<mc<<endl;

    cv::Mat cvtimg;
    cv::cvtColor(src1,cvtimg,cv::COLOR_BGR2GRAY);
    cv::imshow("cvtColor",mc);

    cv::determinant(ma);//计算方阵的行列式
    cout<<"cv::determinant(ma):\n"<<cv::determinant(ma)<<endl;

    cv::Mat matrix;
    cv::Mat eigenvalue;
    cv::Mat eigenvectors;
    matrix = cv::Mat::ones(3,3,CV_32FC1);
    cv::eigen(3*matrix,eigenvalue,eigenvectors);//计算特征向量和特征值
    cout<<"cv::eigen(3*src,eigenvalue,eigenvectors):\n"<<"eigenvalue:\n"<<eigenvalue<<"eigenvectors:\n"<<eigenvectors<<endl;

    cv::exp(ma,mc);//计算指数
    cout<<"cv::exp(ma,mc):"<<mc<<endl;

    cv::flip(ma,mc,0);//旋转图像绕x轴或者y轴
    cout<<"cv::flip(ma,mc,0)"<<mc<<endl;

    cv::gemm(ma,mb,0.5,mc,0.1,mc,0);//广义矩阵乘法 dst = alpha*src1.T*src2+beta*
    cout<<"cv::gemm(ma,mb,0.5,mc,0.1,mc,0):\n"<<mc<<endl;

    cv::inRange(ma,2,9,mc);
    cout<<"cv::inRange(ma,2,9,mc):\n"<<mc<<endl;

    cv::invert(ma,mc);
    cout<<"cv::invert(ma,mc):\n"<<mc<<endl;

    cv::log(ma,mc);
    cout<<"cv::log(ma,mc):\n"<<mc<<endl;

    cv::Mat lut(1,255,CV_8U);
    cv::LUT(src1,lut,cvtimg);
    cout<<"cv::LUT(src1,lut,cvtimg):\n"<<cvtimg<<endl;

    cv::Vec vec1 = cv::Vec2i(3,4);
    cv::Vec2i vec2(5,8);
    cv::Mat icovar;
    cv::Mahalanobis(vec1,vec2,icovar);
    cout<<"cv::Mahalanobis(vec1,vec2,icovar):\n"<<icovar<<endl;

    cv::max(ma,mb,mc);
    cout<<"cv::max(ma,mb,mc):\n"<<mc<<endl;

    cout<<"cv::mean(ma):\n"<<cv::mean(ma)<<endl;
    cv::Mat mean;
    cv::Mat stddev;
    cv::meanStdDev(ma,mean,stddev);
    cout<<"cv::meanStdDev(ma,mean,stddev):\n"<<"mean:\n"<<mean<<"stddev:\n"<<stddev<<endl;

    cv::Mat dst;
    cv::merge(samples,3,dst);
    double minVal,maxVal;
    int minIdx,maxIdx;
    cv::Point minLoc,maxLoc;
    cv::minMaxIdx(ma,&minVal,&maxVal,&minIdx,&maxIdx);
    cv::minMaxLoc(ma,&minVal,&maxVal,&minLoc,&maxLoc);
    cout<<"cv::minMaxIdx(ma,&minVal,&maxVal,&minIdx,&minIdx):\n"<<"(minVal,maxVal,minIdx,minIdx):"<<"("<<minVal<<","<<maxVal<<","<<minIdx<<","<<maxIdx<<")"<<endl;
    cout<<"cv::minMaxLoc(ma,&minVal,&maxVal,&minLoc,&minLoc):\n"<<"(minVal,maxVal,minLoc,minLoc):"<<"("<<minVal<<","<<maxVal<<","<<minLoc<<","<<maxLoc<<")"<<endl;
    
    int fromTo[] = {0,1,1,2,2,0};
    cv::mixChannels(src1,dst,fromTo,3);
    cout<<"cv::mixChannels(src1,dst,fromTo,3):\n"<<endl;
    cv::imshow("mixChannels",dst);

    // cv::mulSpectrums(ma,mb,mc,0);//频谱的逐元素乘法
    cv::mulTransposed(ma,mc,true);
    cout<<"cv::mulTransposed(ma,mc,true):\n"<<mc<<endl;

    cout<<cv::norm(ma,mb,cv::NORM_L2)<<endl;

    cv::normalize(ma,mb,1,0,cv::NORM_L2);

    cv::perspectiveTransform(ma,mc,matrix);
    cout<<"cv::perspectiveTransform(ma,mc,matrix):\n"<<mc<<endl;

    cv::pow(ma,2,mc);

    cv::randn(matrix,0,65536);
    cv::randu(matrix,0,255);

    cv::repeat(ma,1,1,mc);

    cv::scaleAdd(ma,0.5,mb,mc);

    cv::Mat rhs = cv::Mat(1,10,CV_32F);
    cv::Mat dst2 = cv::Mat(1,10,CV_32F);
    cv::solve(ma,rhs,dst2);

    cv::solveCubic(ma,vec2);

    cv::solvePoly(ma,vec2);

    cv::sort(ma,mc,cv::SORT_EVERY_COLUMN|cv::SORT_ASCENDING);

    cv::sortIdx(ma,mc,cv::SORT_EVERY_COLUMN|cv::SORT_ASCENDING);

    cv::Mat mv[3];
    cv::split(src1,mv);

    cv::sqrt(ma,mc);
    cout<<"cv::sqrt(ma,mc):\n"<<mc<<endl;

    cv::subtract(ma,mb,mc);
    cout<<"cv::subtract(ma,mb,mc):\n"<<mc<<endl;

    cout<<"cv::sum(ma):\n"<<cv::sum(ma)<<endl;

    cout<<"cv::trace(ma)\n:"<<cv::trace(ma)<<endl;

    cv::Mat mtx = cv::Mat(3,3,CV_32F);
    rng.fill(mtx,cv::RNG::UNIFORM,0,1);
    cv::transform(src1,dst,mtx);    
    cout<<"cv::transform(src1,dst,mtx):"<<dst<<endl;
    cv::transpose(ma,dst);//对角线对称互换
    cout<<"cv::transpose(ma,dst):\n"<<dst<<endl;



    cv::waitKey(0);
    return 0;
}
