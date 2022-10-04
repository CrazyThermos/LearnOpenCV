#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
cv::Mat img = cv::imread("pic/vim.jpg");
// cv::Mat bak = background.clone();
cv::Mat bak = img(cv::Rect(100,100,800,800)).clone();

vector<cv::Point> ptarray;

void onMouse(int event, int x, int y, int flags, void* param);
void onMouse(int event, int x, int y, int flags, void* param){
    cv::Mat *im = reinterpret_cast<cv::Mat*>(param);
    cv::Mat copy;
    cv::Point pop;
    cv::Rect rect;
    
    int radius = 10;
	switch (event)
	{
		case cv::EVENT_LBUTTONDOWN:     //鼠标左键按下响应：返回坐标和灰度
			cout<<"at("<<x<<","<<y<<")value is:"<<endl;
            if(ptarray.empty()) break;
            pop = ptarray.back();
            rect = cv::Rect2i(pop.x-radius,pop.y-radius,2*radius,2*radius);
            // ones = cv::Mat(rect.height,rect.width,CV_8UC3,cv::Scalar(1,1,1));
            // mask = cv::Mat::zeros(im->rows,im->cols,CV_8UC3);
            copy = bak(rect);
            // ones.copyTo(mask);
            cv::imshow("mask",copy);
            copy.copyTo((*im)(rect));
            ptarray.pop_back();
			break;
		case cv::EVENT_RBUTTONDOWN:    //鼠标右键按下响应：输入坐标并返回该坐标的灰度
			// std::cout<<"input(x,y)"<<endl;
			// std::cout<<"x ="<<endl;
			// // cin>>x;
			// std::cout<<"y ="<<endl;
			// cin>>y;
			cout<<"at("<<x<<","<<y<<")"<<endl;
            cv::circle(*im,cv::Point2i(x,y),radius,cv::Scalar(255,0,255));
			ptarray.push_back(cv::Point2i(x,y));
            break;			
	}

}

int main(int argc, char const *argv[])
{
    cv::namedWindow("Practice6_4",cv::WINDOW_AUTOSIZE);
    cv::createAlignMTB();
    cv::Mat background = img(cv::Rect(100,100,800,800)).clone();

    cv::setMouseCallback("Practice6_4",onMouse,reinterpret_cast<void*> (&background));
    while(1){
        cv::imshow("Practice6_4",background);
        char c = cv::waitKey(10);
        if(c == 'q') break;        
        if(c == 's'){
            cv::polylines(background,ptarray,true,cv::Scalar(255,0,0));
            bak = background.clone();
        }
    }

    return 0;
}
