#include "myopencv.h"


MyOpenCV::MyOpenCV()
{

}

void MyOpenCV::show(Mat res,bool isShow)
{
    if(isShow == true){
        namedWindow("show");
        imshow("show",res);
        waitKey();
    }
}

void MyOpenCV::save(Mat res,string saveFileName)
{
    if(saveFileName.empty() == false){
        saveFileName += ".jpg";
        imwrite(saveFileName,res);
    }
}

Mat MyOpenCV::getGrayMat(Mat src,bool showRes, string saveFileName)
{
    cvtColor(src,src,CV_BGR2GRAY);
    save(src,saveFileName);
    show(src,showRes);
    return src;
}

Mat MyOpenCV::getZoomMat(Mat src, double ratio, bool showRes, string saveFileName)
{
    resize(src,src,Size(src.cols*ratio,src.rows*ratio));
    save(src,saveFileName);
    show(src,showRes);
    return src;
}

Mat MyOpenCV::getChangeLuminanceMat(Mat src, double ratio, bool showRes, string saveFileName)
{
    int rows = src.rows;
    int cols = src.cols;
    int channels = src.channels();
    if(channels == 1){
        for(int row=0;row<rows;row++){
            for(int col = 0; col < cols; col++){
                uchar gray = src.at<uchar>(row, col);
                src.at<uchar>(row, col) = saturate_cast<uchar>(gray * ratio);
            }
        }
    }
    if(channels == 3){
        for(int row=0;row<rows;row++){
            for(int col = 0; col < cols ; col++){
                uchar b = src.at<Vec3b>(row, col)[0];
                uchar g = src.at<Vec3b>(row, col)[1];
                uchar r = src.at<Vec3b>(row, col)[2];
                src.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * ratio);
                src.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * ratio);
                src.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * ratio);
            }
        }
    }
    save(src,saveFileName);
    show(src,showRes);
    return src;
}

MyOpenCV::~MyOpenCV()
{

}

