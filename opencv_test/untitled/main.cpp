#include "mainwindow.h"
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
{
        string filename = "test.csv";
        ifstream file(filename.c_str());
        if(file == NULL){
            cout << "file is wrong!" << endl;
            return -1;
        }else{
            cout << "flie is ok!" << endl;
        }
        string line;
        string path;
        string label;
        vector<Mat> images;
        vector<int> labels;
        while(getline(file,line)){
            stringstream liness(line);
            getline(liness,path,';');
            getline(liness,label);
            Mat tempFace;
            resize(imread(path,0),tempFace,Size(100,100));
            images.push_back(tempFace);
            labels.push_back(atoi(label.c_str()));
        }
        cout << images.size() << "   " << labels.size() << endl;
        Mat testMat = imread("test_face.jpg",0);
        resize(testMat,testMat,Size(100,100));
        namedWindow("show");
        imshow("show",testMat);
        Ptr<EigenFaceRecognizer> model = EigenFaceRecognizer::create();
        model->train(images,labels);
        int id = model->predict(testMat);
        cout << "id:" << id << endl;
        waitKey();
    return 0;
}
