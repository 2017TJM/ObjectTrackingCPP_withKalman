// Blob.h

#ifndef MY_BLOB
#define MY_BLOB

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
class Blob {
public:
    // member variables ///////////////////////////////////////////////////////////////////////////
    std::vector<cv::Point> contour;

    cv::Rect boundingRect;

    cv::Point ptCurrentCenter;

    double dblDiagonalSize;
    double dblAspectRatio;
    
    std::vector<cv::Point> vectorOfAllActualPoints;

    bool blnStillBeingTracked;
    bool blnCurrentMatchFoundOrNewBlob;

    // function prototypes ////////////////////////////////////////////////////////////////////////
    Blob(std::vector<cv::Point> _contour);

};

#endif    // MY_BLOB


