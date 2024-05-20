#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // g++ -o a main.cpp `pkg-config --cflags --libs opencv4`

    std::string inputFile1 = "InputFile1.bmp";
    std::string inputFile2 = "InputFile2.bmp";
    std::string outputFile = "OutputFile.bmp";

    cv::Mat image1 = cv::imread(inputFile1);
    cv::Mat image2 = cv::imread(inputFile2);

    if (image1.empty()) {
        return -1;
    }

    if (image2.empty()) {
        return -1;
    }

    if (image1.size() != image2.size()) {
        return -1;
    }

    for (int y = 0; y < image1.rows; ++y) {
        for (int x = 0; x < image1.cols; ++x) {
            cv::Vec3b &pixel1 = image1.at<cv::Vec3b>(y, x);
            cv::Vec3b pixel2 = image2.at<cv::Vec3b>(y, x);
            if (pixel2[0] == 0 && pixel2[1] == 0 && pixel2[2] == 0) {
                pixel1[0] = 0;
                pixel1[1] = 0;
                pixel1[2] = 0;
            }
        }
    }

    if (!cv::imwrite(outputFile, image1)) {
        return -1;
    }

    return 0;
}