#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int type = CV_32F;
    size_t* hashval = 0;
    cv::Mat m = cv::Mat::ones(3,3,type);
    cv::SparseMat sm = cv::SparseMat(m);
    // uchar* k = sm.ptr(1,false,hashval);
    sm.ref<float>(0,2) += 1.0f;
    cout<<sm.find<float>(0,2)<<endl;

    //exp4-3 打印所有非零元素
    int size[] = {10,10};
    cv::SparseMat sm1(2, size, CV_32F);

    for(int i=0; i<10; i++){
        int idx[2];
        idx[0] = size[0]*rand();
        idx[1] = size[1]*rand();
        sm1.ref<float>(idx) += 1.0f;
    }
    
    cv::SparseMatConstIterator_<float> it = sm1.begin<float>();
    cv::SparseMatConstIterator_<float> it_end = sm1.end<float>();
    // cv::SparseMatIterator_<float> it = sm1.begin<float>();
    // cv::SparseMatIterator_<float> it_end = sm1.end<float>();
    for(; it!=it_end; ++it){
        const cv::SparseMat::Node* node = it.node();
        cout<<"("<<node->idx[0]<<","<<node->idx[1]<<") "<<*it<<endl;
        // it.node()->hashval;
        // it.node()->next;
    }

    int idx[] = {1,3,5,7,9};
    float f = 0;
    float p = 0;
    size_t n = sm.nzcount();
    size_t h = sm.hash(idx);//返回一维稀疏矩阵索引idx数组所指向的数据的哈希值 
    sm.ref<float>(idx) = 42.f;//设置一维稀疏矩阵索引在idx数组中的元素值为42.0
    f = sm.value<float>(idx);//设置一维稀疏矩阵索引在idx数组中的元素值为f
    // p = sm.find<float>(idx);
    sm.erase(idx);//移除多维稀疏矩阵中索引为数组idx的元素

    return 0;
}

//exp4-4 打印稀疏数组
template <class T> void print_matrix(const cv::SparseMat_<T>* sm){
    cv::SparseMatConstIterator_<T> it = sm->begin();
    cv::SparseMatConstIterator_<T> it_end = sm->end();

    for(; it != it_end; ++it){
        const typename cv::SparseMat_<T>::Node* node = it.node();
        cout<<"( "<<node->idx[0]<<","<<node->idx[1]<<" ) = "<<*it<<endl;
    }

}