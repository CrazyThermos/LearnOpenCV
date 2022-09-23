#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int rows=10,cols=10,type=CV_32F,ndims=3;
    int sz3[3] = {4,4,4};
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    cv::Size sz = cv::Size2i(10, 10);
    cv::Scalar s = cv::Scalar(1,2,3,4);
    cv::Matx33f mx = cv::Matx33f();

    cv::Mat m0 = cv::Mat(rows, cols, CV_16S);
    cv::Mat m1 = cv::Mat(rows, cols, CV_16S);
    cv::Mat m2 = cv::Mat(rows, cols, type, s);
    cv::Mat m3 = cv::Mat(ndims, sz3, CV_32FC3);
    cv::Mat m4 = cv::Mat::ones(rows, cols, type);
    cv::Mat m5 = cv::Mat::eye(rows, cols, type);
    cv::Mat m6 = cv::Mat(v);
    
    cv::randn(m0,0,10);
    cv::randn(m1,0,10);
    cv::randu(m3,-1.0f,1.0f);

    cout<<"m1[3][3]="<<m1.at<float>(3,3)<<endl;
    cout<<"m2[3][3]="<<m2.at<float>(3,3)<<endl;
    cout<<"m3[3][3]="<<m3.at<float>(3,3,3)<<endl;
    cout<<"m4[3][3]="<<m4.at<float>(3,3)<<endl;
    cout<<"m5[3][3]="<<m5.at<float>(3,3)<<endl;
    cout<<"m6[3][3]="<<m6.at<float>(1,3)<<endl;

    //exp
    float max = 0;
    float len2 = 0;
    cv::MatConstIterator_<cv::Vec3f> it = m3.begin<cv::Vec3f>();
    while (it != m3.end<cv::Vec3f>())
    {
        len2 = (*it)[0]*(*it)[0]+(*it)[1]*(*it)[1]+(*it)[2]*(*it)[2];
        if(len2 > max) max = len2;
        it++;
    }
    cout<<"len2:"<<len2<<endl;

    //exp4-1
    const int n_mat_size = 5;
    const int n_mat_sz[] = {n_mat_size, n_mat_size, n_mat_size};
    cv::Mat n_mat(3, n_mat_sz, CV_32FC1);
    
    cv::RNG rng;
    rng.fill(n_mat, cv::RNG::UNIFORM, 0.f, 1.f);
    
    const cv::Mat* arrays[] = {&n_mat, 0};
    cv::Mat my_planes[1];
    cv::NAryMatIterator Nit(arrays, my_planes);

    float ff = 0.f;
    int n = 0;
    for(int p = 0; p < Nit.nplanes;p++, ++Nit){
        ff += cv::sum(Nit.planes[0])[0];
        n++;
    }
    cout<<"ff:"<<ff<<endl;
    
    //exp4-2
    cv::Mat n_mat0(3, n_mat_sz, CV_32FC1);
    cv::Mat n_mat1(3, n_mat_sz, CV_32FC1);

    rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);
    rng.fill(n_mat1, cv::RNG::UNIFORM, 0.f, 1.f);

    const cv::Mat* arrays2[] = {&n_mat0, &n_mat1, 0};
    cv::Mat my_planes2[2];
    cv::NAryMatIterator Nit2(arrays2, my_planes2);

    float ff2 = 0.f;
    int n2 = 0;
    for(int p = 0; p < Nit2.nplanes;p++, ++Nit2){
        ff2 += cv::sum(Nit2.planes[0])[0];
        ff2 += cv::sum(Nit2.planes[1])[0];
        n2++;
    }
    cout<<"ff2:"<<ff2<<endl;



    //访问区块
    int i=0,j=4,d=1;
    cout<<endl;
    cout<<m1<<endl<<endl;
    cout<<m1.row(i)<<endl<<endl;
    cout<<m1.col(j)<<endl<<endl;
    cout<<m1.rowRange(i,j)<<endl<<endl;
    cout<<m1.rowRange(cv::Range(i, j))<<endl<<endl;
    cout<<m1.colRange(i,j)<<endl<<endl;
    cout<<m1.colRange(cv::Range(i, j))<<endl<<endl;
    cout<<m1.diag(d)<<endl<<endl;
    cout<<m1(cv::Range(i,j), cv::Range(i,j))<<endl<<endl;
    cout<<m1(cv::Rect(i,j,3,3))<<endl<<endl;
    
    //矩阵操作
    int val = 2;
    cout<<"m0+m1="<<m0+m1<<endl<<endl;
    cout<<"m1+s="<<m1+s<<endl<<endl;
    cout<<"-m1="<<-m1<<endl<<endl;
    cout<<"m1*val"<<m1*val<<endl<<endl;
    cout<<"m2 invert()"<<m2.inv()<<endl<<endl;//矩阵求逆三种method cv::DECOMP_LU cv::DECOMP_CHOLESKY cv::DECOMP_SVD
    cout<<"m1 T"<<m1.t()<<endl<<endl;
    cout<<"m0==m1"<<(m0==m1)<<endl<<endl;
    cout<<"m0&m1"<<(m0&m1)<<endl<<endl;
    cout<<"m1&val"<<(m1&val)<<endl<<endl;
    cout<<"m0.dot(m1)"<<m0.dot(m1)<<endl<<endl;
    cout<<"m0.mul(m1)"<<m0*m1<<endl<<endl;

    //饱和转换 防止溢出
    uchar ch = 'a';
    ch = cv::saturate_cast<uchar>((ch-128)*2 + 128);
    cout<<ch<<endl;

    //其他操作
    cv::Mat mask(3,3,CV_8U,cv::Scalar(1));
    cv::Size sz;
    cv::Point p(1,1);
    int scale = 2, offset = 128;
    m1 = m0.clone();
    m0.copyTo(m1);
    m0.copyTo(m1, mask);//
    m0.convertTo(m1, type, scale, offset);//转换并赋值
    m0.assignTo(m1 ,type);
    m0.setTo(s, mask);
    m0.reshape(2,0);//chanels = 2 rows = 0 表示通道数变为2，行数不变
    m0.push_back(m1);
    m0.pop_back(3);//移除三行
    m0.locateROI(sz, p);
    m0.adjustROI(0,9,0,9);
    m0.total();
    m0.isContinuous();
    m0.elemSize();//返回m0的位长度（三通道浮点矩阵返回12）
    m0.elemSize1();//返回m0的最基本元素的位长度（三通道浮点矩阵将返回12）

    //返回属性
    m0.type();
    m0.depth();
    m0.channels();
    m0.size();
    m0.empty();

    return 0;
}
