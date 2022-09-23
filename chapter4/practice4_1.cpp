#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
// int test[]={1,1,1,1,1,1,1,1,1,1,
//                     1,1,1,1,1,1,1,1,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,0,0,0,0,0,0,1,1,
//                     1,1,1,1,1,1,1,1,1,1,
//                     1,1,1,1,1,1,1,1,1,1};
uint8_t n[4][20][10]={
                   {{255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,0,0,0,0,0,0,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,}},

                   {{0,0,0,255,255,255,0,0,0,0,},
                    {255,255,255,255,255,255,0,0,0,0,},
                    {255,255,255,255,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {0,0,0,0,255,255,0,0,0,0,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,}},

                   {{255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,0,0,0,0,0,0,0,0,},
                    {255,255,0,0,0,0,0,0,0,0,},
                    {255,255,0,0,0,0,0,0,0,0,},
                    {255,255,0,0,0,0,0,0,0,0,},
                    {255,255,0,0,0,0,0,0,0,0,},
                    {255,255,0,0,0,0,0,0,0,0,},
                    {255,255,0,0,0,0,0,0,0,0,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,}},

                   {{255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {0,0,0,0,0,0,0,0,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,},
                    {255,255,255,255,255,255,255,255,255,255,}},};

uint8_t s[7][10] = {
                    {0,0,0,0,255,255,0,0,0,0},
                    {0,0,0,255,0,0,255,0,0,0},
                    {0,0,255,0,0,0,0,255,0,0},
                    {0,255,0,0,0,0,0,0,255,0},
                    {255,0,0,0,0,0,0,0,0,255},
                    {255,0,0,0,0,0,0,0,0,255},
                    {255,255,255,255,255,255,255,255,255,255},

                    };

uint8_t r[20][10]={
                  {0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,0,0,0,0,255,255,0},
                  {0,0,0,255,0,0,0,255,255,0},
                  {0,0,255,255,0,0,0,255,255,0},
                  {0,255,255,255,0,0,0,255,255,0},
                  {255,255,255,255,255,255,255,255,255,0},
                  {255,255,255,255,255,255,255,255,255,0},
                  {0,255,255,255,0,0,0,0,0,0},
                  {0,0,255,255,0,0,0,0,0,0},
                  {0,0,0,255,0,0,0,0,0,0},

                  };
int type = CV_8U;
cv::Point selector = cv::Point2i();
cv::Mat selectorM = cv::Mat(7,10,CV_8U,s);
//打印选择标
void printSel(cv::Mat &img){
    selectorM.copyTo(img(cv::Range(22+0+selector.y,22+7+selector.y),cv::Range(0+selector.x,10+selector.x)));
}
//删除选择标
void deleteSel(cv::Mat &img){
    cv::Mat zero = cv::Mat::zeros(7,10,type);
    zero.copyTo(img(cv::Range(22+0+selector.y,22+7+selector.y),cv::Range(0+selector.x,10+selector.x)));
}
//检查区块的值是否为0
bool checkEmpty(cv::Mat &img){
    // cv::Mat zero = cv::Mat::zeros(20,10,type);
        return sum(img(cv::Range(0+selector.y,20+selector.y),cv::Range(0+selector.x,10+selector.x)))==cv::Scalar(0)?true:false;
}
//检查区块的值
bool checkOne(cv::Mat &img){
    // cv::Mat zero = cv::Mat::zeros(20,10,type);
        return sum(img(cv::Range(0+selector.y,20+selector.y),cv::Range(0+selector.x,10+selector.x)))==cv::Scalar(1)?true:false;
}
//刷新图像
void reflash(cv::Mat &img, vector<int> nums,cv::Point selector ,int pos){
    vector<int>::iterator it = nums.begin()+pos;
    int offsety = selector.y;
    int offsetx = selector.x;
    for(;it!=nums.end();it++){
        if(*it == -1){//-1为换行符
            cv::Mat rImg = cv::Mat(20,10,type,r);
            rImg.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            offsetx += 15;
            // offsetx = 20;
            // offsety +=30;
        }
        else if(*it ==-2){//-2为换行符后的空格
            cv::Mat zero = cv::Mat::zeros(20,10,type);
            zero.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            offsetx += 15;
            // continue;
        }
        else{
            cv::Mat numImg = cv::Mat(20,10,type,n[*it]);
            numImg.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            offsetx += 15;

        }
        if(offsetx > 480){
            offsetx  = 20;
            offsety += 30; 
        }        
    }
}
//保存图片
void saveImg(vector<int> nums){
    vector<cv::Mat> rgb;
    cv::Mat imgr = cv::Mat(500,500,CV_8UC1,cv::Scalar(0));
    cv::Mat imgg = cv::Mat(500,500,CV_8UC1,cv::Scalar(0));
    cv::Mat imgb = cv::Mat(500,500,CV_8UC1,cv::Scalar(0));

    vector<int>::iterator it = nums.begin();
    int offsety = 10;
    int offsetx = 20;
    for(;it!=nums.end();it++){
        if(*it == -1){
            cv::Mat rImg = cv::Mat(20,10,CV_8UC1,r);
            rImg.copyTo(imgr(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            rImg.copyTo(imgg(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            rImg.copyTo(imgb(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));

            offsetx += 15;
        }
        else if(*it ==-2){
            cv::Mat zero = cv::Mat::zeros(20,10,CV_8UC1);
            zero.copyTo(imgr(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            zero.copyTo(imgg(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            zero.copyTo(imgb(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));

            offsetx += 15;
        }
        else{
            cv::RNG rng;
            cv::Mat numImg_r = cv::Mat(20,10,CV_8UC1,n[*it]);
            cv::Mat numImg_g = cv::Mat(20,10,CV_8UC1,n[*it]);
            cv::Mat numImg_b = cv::Mat(20,10,CV_8UC1,n[*it]);

            cv::Mat color_r = cv::Mat(20,10,CV_8UC1,cv::Scalar(rng.uniform(0,255)));
            cv::Mat color_g = cv::Mat(20,10,CV_8UC1,cv::Scalar(rng.uniform(0,255)));
            cv::Mat color_b = cv::Mat(20,10,CV_8UC1,cv::Scalar(rng.uniform(0,255)));
            // cout<<color_r.at<uint8_t>(0,0)<<color_g.at<uint8_t>(0,0)<<color_b.at<uint8_t>(0,0)<<endl;
            // rng.fill(color_r,cv::RNG::UNIFORM,0,255);
            // rng.fill(color_g,cv::RNG::UNIFORM,0,255);
            // rng.fill(color_b,cv::RNG::UNIFORM,0,255);
            uint8_t k = 255;
            uint8_t l = 200;
            numImg_r=numImg_r/k + l;
            numImg_g=numImg_g/k + l;
            numImg_b=numImg_b/k + l;

            numImg_r.copyTo(imgr(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            numImg_g.copyTo(imgg(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            numImg_b.copyTo(imgb(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));

            offsetx += 15;

        }
        if(offsetx > 480){
            offsetx  = 20;
            offsety += 30; 
        }        
    }
    rgb.push_back(imgr);
    rgb.push_back(imgg);
    rgb.push_back(imgb);
    cv::Mat output = cv::Mat(500,500,CV_8UC3);
    cv::merge(rgb,output);
    cv::cvtColor(output,output,cv::COLOR_GRAY2RGB);
    // cout<<imgr<<endl;
    cv::imwrite("num.jpg",output);
}
//输出目前的输入
void printNums(vector<int> nums){
     vector<int>::iterator it = nums.begin();
     for(;it!=nums.end();it++) cout<<*it<<" ";
}

int main(int argc, const char** argv) {
    
    int offsety = 10;
    int offsetx = 20;
    int w = 500;
    int h = 500;
    
    selector.x = offsetx;
    selector.y = offsety;

    // cv::Mat numImg = cv::Mat(20,10,type,n[0]);
    cv::Mat img = cv::Mat::zeros(w,h,type);
    vector<int> nums;

    // vector<int>::iterator pos = nums.begin();
    int pos = 0;
    if(img.empty()) return -1;
    cv::namedWindow("Num1",cv::WINDOW_AUTOSIZE);
    // cout<<num<<endl;
    while(1){
        bool input = false;
        printSel(img);
        cv::imshow("Num1",img);
        char key = NULL;
        key = cv::waitKey(0);


        cout<<nums.size()<<endl;
        if(key == 'q') break;
        if(key == '\b'){//backsapce键
            if(checkOne(img)) continue;
            cv::Mat zero = cv::Mat::zeros(20,10,type);
            // if(offsetx==selector.x&&offsety==selector.y) zero.at<uint8_t>(1,1)=1;
            zero.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            // zero.at<uint8_t>(1,1)=1;
            // deleteSel(img);

            // zero.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
            
            if(pos<nums.size()&&pos>=0){//不为空时才能回退
                
                if(nums[pos] == -1){//删除的是换行符
                    for(vector<int>::iterator it=nums.begin()+pos;*it<0;){//删除换行符以及后面的空格
                        nums.erase(it);
                        cv::Mat zero = cv::Mat::zeros(20,10,type);
                        
                        if(offsetx - 15<20){//判断是否换行
                            offsetx = w-30;
                            offsety -=30;
                        }
                        else{
                            offsetx -= 15;
                        }
                        zero.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));

                    }
                    zero.at<uint8_t>(1,1)=1;
                    zero.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
                }
                else{
                    nums.erase(nums.begin()+pos);
                    if(offsetx - 15<20){
                        offsetx = w-30;
                        offsety -=30;
                    }
                    else{
                        offsetx -= 15;
                    }
                    if(offsety<10){
                        offsety=10;
                        offsetx=20;
                    }
                    zero.at<uint8_t>(1,1)=1;
                    zero.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
                }
                printNums(nums);
            }
            reflash(img,nums,selector,pos);
        } 
        if(key == '\r'){//回车键
            if(selector.y+30<500){//最后一行不能换行
                deleteSel(img); 
                offsetx = offsetx - selector.x + 20;
                offsety += 30;
                cv::Mat zero = cv::Mat::zeros(20,10,type);
                zero.at<uint8_t>(1,1)=1;
                zero.copyTo(img(cv::Range(0+offsety,20+offsety),cv::Range(0+offsetx,10+offsetx)));
                nums.insert(nums.begin()+pos,-1);//-1表示换行符

                int prepos = pos;
                pos++;
                for(int i=0;i<31-prepos%31-1;i++){
                    nums.insert(nums.begin()+pos,-2);//-2表示换行符后的空格
                    pos++;
                }
                cout<<"pos:"<<pos<<endl;
                reflash(img,nums,selector,prepos);
                selector.x = 20;
                selector.y += 30;

            }
        }
        if(key == 'o'){//保存图片
            saveImg(nums);
            continue;
        }
        if(selector.y>500) continue;
        cv::Mat numImg;
        switch (key)//opencv中存在bug这里使用wasd来代替上下左右
        {
        case 'w'://上
            if(selector.y - 30 < 10) continue;
            deleteSel(img);
            selector.y -= 30;
            if(!checkEmpty(img)){
                pos = pos - 31;
                printSel(img);
            }
            else{
                selector.y += 30;
                printSel(img);
            }
            break;
        case 's'://下
            if(selector.y + 30 > 480) continue;
            deleteSel(img);
            selector.y += 30;
            if(!checkEmpty(img)){
                pos = pos + 31;
                printSel(img);
            }
            else{
                selector.y -= 30;
                printSel(img);
            }
            break;
        case 'a'://左
            if(selector.x - 15 < 20) continue;
            deleteSel(img);
            selector.x -= 15;
            if(!checkEmpty(img)){
                pos--;
                printSel(img);
            }
            else{
                selector.x += 15;
                printSel(img);
            }
            break;
        case 'd'://右
            if(selector.x + 15 > 480) continue;
            deleteSel(img);
            selector.x +=15;
            if(!checkEmpty(img)){
                pos++;
                printSel(img);
            }
            else{
                selector.x -= 15;
                printSel(img);
            }
            break;
        case '0':
            numImg = cv::Mat(20,10,type,n[0]);
            numImg.copyTo(img(cv::Range(0+selector.y,20+selector.y),cv::Range(0+selector.x,10+selector.x)));
            input=true;
            if(pos >= nums.size()){
                nums.push_back(0);
            }
            else{
                nums[pos]=0;
            }
            break;
        case '1':
            numImg = cv::Mat(20,10,type,n[1]);
            numImg.copyTo(img(cv::Range(0+selector.y,20+selector.y),cv::Range(0+selector.x,10+selector.x)));
            input=true;
            if(pos >= nums.size()){
                nums.push_back(1);
            }
            else{
                nums[pos]=1;
            }
            break;
        case '2':
            numImg = cv::Mat(20,10,type,n[2]);
            numImg.copyTo(img(cv::Range(0+selector.y,20+selector.y),cv::Range(0+selector.x,10+selector.x)));
            input=true;
            if(pos >= nums.size()){
                nums.push_back(1);
            }
            else{
                nums[pos]=1;
            }
            break;
        case '3':
            numImg = cv::Mat(20,10,type,n[3]);
            numImg.copyTo(img(cv::Range(0+selector.y,20+selector.y),cv::Range(0+selector.x,10+selector.x)));
            input=true;
            if(pos >= nums.size()){
                nums.push_back(1);
            }
            else{
                nums[pos]=1;
            }
            break;
        default:
            continue;
        }
        // cout<<offsetx<<endl;
        // deleteSel(img);
        // selector.x += 15;
        // if(selector.x > 480){
        //     selector.x = 20;
        //     selector.y += 30; 
        // }
        // printSel(img);
        if(selector.x == offsetx && selector.y == offsety && input){//如果选择标在最后一个字符后面自动进行插入
            offsetx += 15;
            if(offsetx > 480){
                offsetx = 20;
                offsety += 30; 
            }
            img.at<uint8_t>(offsety,offsetx)=1;
            deleteSel(img);
            pos++;
            selector.x = offsetx;
            selector.y = offsety;
        }
        cout<<"key:"<<key<<endl;
        cout<<"(os,oy):"<<offsetx<<","<<offsety<<endl;
        cout<<"(sx,sy):"<<selector.x<<","<<selector.y<<endl;
        cout<<"pos:"<<pos<<endl;
        cout<<nums.size()<<endl;
        
    }
    
    cv::destroyWindow("Num1");
    return 0;
}