#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image2, image3;
    image3 = imread("G:\\C++\\opencv\\images\\staged-lena.jpg");
    //图像的高，行数
    int numberRows = image3.rows;
    //图像的宽，列数
    int numberCols = image3.cols;
    //产生解密文件
    image2.create(numberRows, numberCols, image3.type());
    Mat tHidden_image;
    Mat hidden_mast(numberRows, numberCols, image3.type(), Scalar(0x0F, 0x0F, 0x0F));
    bitwise_and(image3, hidden_mast, image2);
    //换原加密处理
    for (int j = 0; j < numberRows; j++) {
        for (int i = 0; i < numberCols; i++) {
            image2.at<Vec3b>(j, i)[0] = image2.at<Vec3b>(j, i)[0] << 4;
            image2.at<Vec3b>(j, i)[1] = image2.at<Vec3b>(j, i)[1] << 4;
            image2.at<Vec3b>(j, i)[2] = image2.at<Vec3b>(j, i)[2] << 4;
        }
    }
    imshow("Staged Image", image3);
    imshow("Hidden Image", image2);
    waitKey(0);

    return 0;
}

