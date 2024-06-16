#ifndef VIDEO_PROCESSOR_H
#define VIDEO_PROCESSOR_H

#include <opencv2/opencv.hpp>
#include <string>

void adjustBrightness(cv::Mat& frame, int brightness);
void playVideo(const std::string& videoPath);


#endif
