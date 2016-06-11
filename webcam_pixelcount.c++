#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/videoio/videoio.hpp"

using namespace cv;
using namespace std;

int main(){
    
    cv::VideoCapture cap(0);
    
    if (!cap.isOpened()) {
        cout << "Webcam is not open." << endl;
    }
    
    while (true){
        
        Mat image;
        Mat HSVimage;
        Mat processedImage;
        
        cap.read(image); //assigns mat image to raw footage
        cvtColor(image, HSVimage, CV_BGR2HSV); //concerts the mat to hsv under nat HSVimage
        inRange(HSVimage, Scalar(0,0,0), Scalar(100,255,255), processedImage); //processes HSV images and gets only pixels to scaler range to processed image
        int numPixels = countNonZero(processedImage);
        cout << numPixels << endl;
        
        imshow("Original", image);
        imshow("Processed", processedImage);
        
        
    }
    
}
