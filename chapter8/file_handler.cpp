#include<opencv2/opencv.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("pic/vim.jpg");
    cv::Mat dst;
    cv::imwrite("pic/dst.jpg",dst);

    vector<int> params;
    params.resize(3,0);
    params[0]=cv::IMWRITE_JPEG_QUALITY;
    params[1]=95;
    vector<uchar> buf;
    cv::imencode(".jpg",img,buf,params);

    string saveimg = "encode.jpg";
    ofstream file(saveimg.c_str(),ios::out|ios::binary);
    file.write((char*)&buf[0],buf.size()*sizeof(uchar));
    file.close();

    cv::VideoCapture cap(0);
    cv::VideoWriter videowirter;
    cv::FileStorage filesto;//可以读取写入文件，如yaml和xml文件

    //ex8-2 使用cv::FileStorage创建yaml参数文件
    cv::FileStorage fs("test.yaml",cv::FileStorage::WRITE);
    fs << "frameCount" << 5;
    time_t rawtime;
    time(&rawtime);
    fs << "calibrationDate" << asctime(localtime(&rawtime));
    cv::Mat cameraMatrix = (cv::Mat1d(3,3)<<1000,0,320,0,1000,240,0,0,1);
    cv::Mat distCoeffs = (cv::Mat1d(5,1)<<0.1,0.01,-0.001,0,0);
    fs << "cameraMatrix" << cameraMatrix << "distCoeffs" <<distCoeffs;
    fs << "features" <<"{";
    for(int i=0;i<3;i++){
        int x = rand()%640;
        int y = rand()%320;
        uchar lbp = rand()%256;
        fs << "{:" << "x" << x << "y" << y << "lbp" << "{:";
        for(int j=0;j<8;j++)
            fs<<((lbp>>j)&1);
        fs<<"]"<<"}";
    }
    fs<<"]";
    fs.release();

    //ex8-3 使用cv::FileStorage来读取a.yaml
    cv::FileStorage fs2("test.yaml",cv::FileStorage::READ);
    //first method: use(type) operator on FileNode
    int frameCount = (int)fs2["frameCount"];
    //second method: use cv::FileNode::operator >>
    //
    std::string date;
    fs2["calibrationDate"] >> date;

    cv::Mat cameraMatrix2, distCoeffs2;
    fs2["cameraMatrix2"] >> cameraMatrix2;
    fs2["distCoeffs2"] >> distCoeffs2;

    cout<<"frameCount:"<<frameCount<<endl
        <<"calibration date:"<<date<<endl
        <<"camera matrix:"<<cameraMatrix2<<endl
        <<"distortion coeffs"<<distCoeffs2<<endl;

    cv::FileNode features =fs2["features"];
    cv::FileNodeIterator it = features.begin(), it_end = features.end();
    int idx=0;
    vector<uchar> lbpval;
    //iterate through a sequence using FileNodeIterstor
    for(;it!=it_end;++it,idx++){
        cout<<"feature #"<<idx<<":";
        cout<<"x="<<(int)(*it)["x"]<<",y="<<(int)(*it)["y"]<<",lbp:(";
        //(Note:easily read numerical arrays using FileNode>>std::vector.)
        //
        (*it)["lbp"]>>lbpval;
        for(int i=0;i<(int)lbpval.size();i++){
            cout<<" "<<(int)lbpval[i];
        }
        cout<<")"<<endl;
    }
    fs2.release();
    return 0;
}
