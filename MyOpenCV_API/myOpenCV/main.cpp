#include <QApplication>
#include"myopencv.h"

int main(int argc, char *argv[])
{
    MyOpenCV cv;
    Mat src = imread("F:/images/01.jpg");
    src = cv.getZoomMat(src,0.1);

    src = cv.getGrayMat(src);
    cv.getChangeLuminanceMat(src,0.8,1,"test");
    return 0;
}
