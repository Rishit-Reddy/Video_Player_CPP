#include "video_processor.h"
#include <opencv2/opencv.hpp>
#include <iostream>


void adjustBrightness(cv::Mat& frame, int brightness){
    frame.convertTo(frame, -1, brightness, 1.0);
}


void playVideo(const std::string& videoPath){
    
    //Open the video file
    cv::VideoCapture cap(videoPath);
    if(!cap.isOpened()){
        std::cout<<"Error: Could not open the video file"<<std::endl;
        return;
    }
    
    std::cout<<"File Opened"<<std::endl;

    int brightness = 50; //Ranges [-100, 100]

    cv::Mat frame;
    while(true){
        cap >> frame;

        if(frame.empty()){
            break;
        }

        // adjustBrightness(frame, brightness);

        cv::namedWindow("Video Playback", cv::WINDOW_NORMAL);
        cv::imshow("Video Playback", frame);

        int key = cv::waitKey(30);

        if(key == 27){
            //Exits when 'Esc' is pressed
            break;
        }else if(key == 'b'){
            brightness = std::min(brightness + 5, 100);
        }else if(key == 'n'){
            brightness = std::max(brightness - 5, -100);
        }
    }

    cap.release();
    cv::destroyAllWindows();

    std::cout<<"End";
}
