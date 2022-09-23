#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

using namespace std;
int main(int argc, char const *argv[])
{
    cv::Mat pic = cv::Mat::ones(500,500,CV_8UC3);
    cv::Point2i center(249,249);
    cv::circle(pic,center,249,cv::Scalar(0,0,255));
    cv::Point2i pt1(160,30);
    cv::Point2i pt2(30,190);

    cout<<"cv::clipLine(cv::Rect(50,50,50,50),pt1,pt2):"<<cv::clipLine(cv::Rect(50,50,50,50),pt1,pt2)<<endl;
    cv::Point2f pt3(250,250);
    cv::Size2f sz(100,50);
    cv::Point2i pt5(60,60);
    float angle = 60.0;
    cv::RotatedRect box(pt3,sz,angle);
    cv::ellipse(pic,box,cv::Scalar(0,125,125));

    cv::Size axes(60,40);
    vector<cv::Point> pts;
    cv::ellipse2Poly(center,axes,0.,0.,180.,60,pts);
    
    cv::Point2f pt6(50,50);
    cv::Point2f pt7(100,150);
    cv::Point2f pt8(150,350);
    cv::Point2f pt9(250,50);
    cv::Point2f pt10(200,20);
    vector<cv::Point> ptsarray1 = {pt6,pt7,pt8,pt9,pt10};
    cv::fillConvexPoly(pic,ptsarray1,cv::Scalar(0,255,125));
    cv::fillPoly(pic,ptsarray1,cv::Scalar(125,125,0));

    cv::line(pic,pt2,pt10,cv::Scalar(6,66,166));
    cv::rectangle(pic,pt7,pt8,cv::Scalar(166,66,6));

    cv::Point2f pt11(310,310);
    cv::Point2f pt12(320,360);
    cv::Point2f pt13(360,370);
    cv::Point2f pt14(380,390);
    cv::Point2f pt15(350,30);
    cv::Point2f pt16(200,200);
    vector<cv::Point> ptsarray2={pt11,pt12,pt13,pt14,pt15,pt16};
    int npts[] = {3,3};
    cv::polylines(pic,ptsarray2,npts,cv::Scalar(33,44,55));
    
    cv::LineIterator(pic,pt11,pt16);

    cv::putText(pic,"closecv",cv::Point2f(180,400),cv::FONT_HERSHEY_TRIPLEX,2,cv::Scalar(200,100,50));
    cv::imshow("pic",pic);
    cv::waitKey(0);
    return 0;
}
