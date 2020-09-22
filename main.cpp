#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

using namespace cv;
using namespace std;
int main() {
    double nickels = .05;
    double pennies = .01;
    double quarters = .25;

    Mat original = imread("ezcoin.jpg");
    Mat gray;
    cvtColor(original, gray, CV_BGR2GRAY);
    GaussianBlur(gray,gray, Size(9, 9), -1, -1);
    vector<Vec3f> pennyCount;
    vector<Vec3f> nickelCount;
    vector<Vec3f> quarterCount;
    //above first threshold means it stays no matter what
    HoughCircles(gray, pennyCount, CV_HOUGH_GRADIENT, 1, gray.rows/16, 95,32,70, 90);







    HoughCircles(gray, nickelCount, CV_HOUGH_GRADIENT, 1, gray.rows/10, 90, 35, 98, 107); //101 brings 2 additional pennies

//HoughCircles(gray, nickelCount, CV_HOUGH_GRADIENT, 1, gray.rows/12, 100, 35, 98, 109);
//90



    HoughCircles(gray, quarterCount, CV_HOUGH_GRADIENT, 1, gray.rows/16, 110, 30, 110, 155);
    for( size_t i = 0; i < pennyCount.size(); i++ )
    {
        Vec3i c = pennyCount[i];
        Point center = Point(c[0], c[1]);
        circle( original, center, 1, Scalar(0,100,100), 3, LINE_AA);
        int radius = c[2];
        circle( original, center, radius, Scalar(255,0,255), 3, LINE_AA);
    }

    for( size_t i = 0; i < nickelCount.size(); i++ )
    {
        Vec3i c = nickelCount[i];
        Point center = Point(c[0], c[1]);
        circle( original, center, 1, Scalar(0,100,100), 3, LINE_AA);
        int radius = c[2];
        circle( original, center, radius, Scalar(0,250,174), 3, LINE_AA);
    }

    for( size_t i = 0; i < quarterCount.size(); i++ )
    {
        Vec3i c = quarterCount[i];
        Point center = Point(c[0], c[1]);
        circle( original, center, 1, Scalar(0,100,100), 3, LINE_AA);
        int radius = c[2];
        circle( original, center, radius, Scalar(255,0,0), 3, LINE_AA);
    }
    /*int P=pennyCount.size();
    int N=nickelCount.size();
    int Q=quarterCount.size();

    double totalP = P * pennies;
    double totalN = N * nickels;
    double totalQ = Q * quarters;*/

    double total = (pennyCount.size() * pennies) + (nickelCount.size() * nickels) + (quarterCount.size() * quarters);
    resize(original, original, Size(original.cols/4.5, original.rows/4.5));
    cout << "The total amount of money is  $: " + to_string(total) << endl;
    imshow("money", original);
    waitKey(0);
    return 0;
}
