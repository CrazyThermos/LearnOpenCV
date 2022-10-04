#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
float data[3][2] = {{1.,1.},{0.,1.},{-1.,1.}};
int main(int argc, char const *argv[])
{
    cv::RNG rng;
    cv::Mat A = cv::Mat(3,2,CV_32F,data);
    cv::Mat M = A.t() * A;
    cout<<"A:\n"<<A<<endl;
    cout<<"M:\n"<<M<<endl;

    cv::Mat eigenvalue;
    cv::Mat eigenvectors;
    cv::eigen(M,eigenvalue,eigenvectors);
    
    cv::Mat W;
    cv::Mat U;
    cv::Mat Vt;
    cv::SVD svd(eigenvalue,cv::SVD::FULL_UV);
    svd.compute(eigenvalue,W,U,Vt);
    cout<<"W:\n"<<W<<endl;
    cout<<"U:\n"<<U<<endl;
    cout<<"Vt:\n"<<Vt<<endl;

    return 0;
}
