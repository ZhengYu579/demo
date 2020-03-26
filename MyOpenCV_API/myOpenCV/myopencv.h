#ifndef MYOPENCV_H
#define MYOPENCV_H

#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>

using namespace  cv;
using namespace cv::face;
using namespace std;

class MyOpenCV
{
public:
    MyOpenCV();
    Mat getGrayMat(Mat src,bool showRes = false,string saveFileName = "");
    Mat getZoomMat(Mat src,double ratio = 0.5,bool showRes = false,string saveFileName = "");
    Mat getChangeLuminanceMat(Mat src,double ratio = 1.5,bool showRes = false,string saveFileName = "");
    ~MyOpenCV();
    void show(Mat res,bool isShow = true);
    void save(Mat res,string saveFileName = "save");
};

#endif // MYOPENCV_H
