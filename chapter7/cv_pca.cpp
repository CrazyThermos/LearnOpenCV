#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace std;
void drawAxis(cv::Mat &,cv::Point,cv::Point,cv::Scalar,const float);
double getOrientation(const vector<cv::Point> &, cv::Mat &);
void drawAxis(cv::Mat &img,cv::Point p,cv::Point q,cv::Scalar colour,const float scale = 0.2){
    double angle;
    double hypotenuse;
    angle = atan2((double)p.y-q.y,(double)p.x-q.x);
    hypotenuse = cv::sqrt((double)(p.y-q.y)*(p.y-q.y)+(p.x-q.x)*(p.x-q.x));
    q.x = (int)(p.x-scale*hypotenuse*cos(angle));
    q.y = (int)(p.y-scale*hypotenuse*sin(angle));
    cv::line(img,p,q,colour,1,cv::LINE_AA);

    p.x = (int)(q.x+9*cos(angle+CV_PI/4));
    p.y = (int)(q.y+9*sin(angle+CV_PI/4));
    cv::line(img,p,q,colour,1,cv::LINE_AA);
    p.x = (int)(q.x+9*cos(angle-CV_PI/4));
    p.y = (int)(q.y+9*sin(angle-CV_PI/4));
    cv::line(img,p,q,colour,1,cv::LINE_AA);

}

double getOrientation(const vector<cv::Point> &pts, cv::Mat &img){
    int sz = static_cast<int>(pts.size());
    cv::Mat data_pts = cv::Mat(sz,2,CV_64FC1);
    for (size_t i = 0; i < data_pts.rows; i++)
    {
        data_pts.at<double>(i,0)=pts[i].x;
        data_pts.at<double>(i,1)=pts[i].y;
    }
    cv::PCA pca_analysis(data_pts,cv::Mat(),cv::PCA::DATA_AS_ROW);
    cv::Point cntr = cv::Point(static_cast<int>(pca_analysis.mean.at<double>(0,0)),static_cast<int>(pca_analysis.mean.at<double>(0,1)));
    vector<cv::Point2d> eigen_vecs(2);
    vector<double> eigen_val(2);
    for(size_t i = 0; i < 2; i++){
        eigen_vecs[i] = cv::Point2d(pca_analysis.eigenvectors.at<double>(i,0),pca_analysis.eigenvectors.at<double>(i,1));
        eigen_val[i]  = pca_analysis.eigenvalues.at<double>(i); 
    }
    cv::circle(img,cntr,3,cv::Scalar(255,0,255),2);
    cv::Point p1 = cntr + 0.02*cv::Point(static_cast<int>(eigen_vecs[0].x*eigen_val[0]),static_cast<int>(eigen_vecs[0].y*eigen_val[0]));
    cv::Point p2 = cntr - 0.02*cv::Point(static_cast<int>(eigen_vecs[1].x*eigen_val[1]),static_cast<int>(eigen_vecs[1].y*eigen_val[1]));
    drawAxis(img,cntr,p1,cv::Scalar(0,255,0),1);
    drawAxis(img,cntr,p2,cv::Scalar(255,255,0),5);
    double angle = atan2(eigen_vecs[0].y,eigen_vecs[0].x);
    return angle;
}


int main(int argc, char const *argv[])
{
    cv::Mat img = cv::imread("pic/pca.jpg");
    // int num_components = 5;
    // cv::PCA pca(img,cv::Mat(),0,num_components);
    cv::Mat gray;
    cv::cvtColor(img,gray,cv::COLOR_BGR2GRAY);
    cv::Mat bw;
    cv::threshold(gray,bw,50,255,cv::THRESH_BINARY|cv::THRESH_OTSU);
    vector<cv::Vec4i> hierarchy;
    vector<vector<cv::Point>> contours;
    cv::findContours(bw,contours,hierarchy,cv::RETR_LIST,cv::CHAIN_APPROX_NONE);
    for (size_t i = 0; i < contours.size(); i++)
    {
        double area = cv::contourArea(contours[i]);
        if(area<1e2||1e5<area) continue;
        cv::drawContours(img,contours,static_cast<int>(i),cv::Scalar(0,0,255),2,8,hierarchy,0);
        getOrientation(contours[i],img);
    }
    cv::imshow("output",img);
    cv::waitKey(0);
    return 0;
}
