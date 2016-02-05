// Blob.h

#ifndef MY_BLOB
#define MY_BLOB

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/video/tracking.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
class Blob {
public:
    // member variables ///////////////////////////////////////////////////////////////////////////
    std::vector<cv::Point> contour;

    cv::Rect boundingRect;

    cv::Point ptCurrentCenter;

    std::vector<cv::Point> predictedCenterPositions;                 // declare 3 vectors for predicted, actual, and corrected positions
    std::vector<cv::Point> actualCenterPositions;
    std::vector<cv::Point> correctedCenterPositions;

    double dblDiagonalSize;
    double dblAspectRatio;
    
    //std::vector<cv::Point> vectorOfAllActualPoints;

    bool blnStillBeingTracked;
    bool blnCurrentMatchFoundOrNewBlob;

    cv::KalmanFilter kalmanFilter;

    // function prototypes ////////////////////////////////////////////////////////////////////////
    Blob(std::vector<cv::Point> _contour);

};

#endif    // MY_BLOB


