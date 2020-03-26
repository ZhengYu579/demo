#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include<opencv2/face.hpp>

using namespace  cv;
using namespace cv::face;
using namespace std;

CascadeClassifier cas;

int main(int argc, char *argv[])
{\
    if(cas.load("haarcascade_frontalface_alt.xml") == false){
        cout << "cas is wrong!" << endl;
        return -1;
    }else{
        cout << "cas is ok!" << endl;
    }
    Mat src = imread("test.jpg",0);
    if(src.empty() == true ){
        cout<< " src is wrong!" << endl;
        return -1;
    }else{
        cout << "src is ok!" << endl;
    }
    Mat dst;
    equalizeHist(src,dst);
    vector<Rect> faces;
    cas.detectMultiScale(dst,faces);
    for(int i=0;i<faces.size();i++){
        rectangle(src,faces[i],Scalar(255,0,0));
        Mat dst1 = src(faces[i]);
        resize(dst1,dst1,Size(100,100));
        imwrite(format("test_face%d.jpg",i),dst1);
    }
    namedWindow("test");
    imshow("test",src);
    waitKey();
    return 0;
}
