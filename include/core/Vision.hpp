#pragma once

#include <opencv2/objdetect/aruco_detector.hpp>
#include <opencv2/opencv.hpp>

class Vision {
private:
  int cameraID;
  cv::Mat framebuffer;
  cv::VideoCapture stream;
  cv::aruco::Dictionary aruco_dict;
  cv::Ptr<cv::aruco::Dictionary> aruco_dict_ptr;
  cv::aruco::DetectorParameters aruco_params;
  cv::Ptr<cv::aruco::DetectorParameters> aruco_params_ptr;

public:
  std::vector< std::vector<cv::Point2f> > tags_corners;
  std::vector<int> tag_IDs;

  Vision(int camID);
  
  void open();
  void close();
  
  bool read();
  cv::Mat getFramebuffer();

  bool detectAprilTags();
};
