// Blob.cpp

#include "Blob.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
Blob::Blob(std::vector<cv::Point> _contour) {

    contour = _contour;

    boundingRect = cv::boundingRect(contour);

    ptCurrentCenter.x = (boundingRect.x + boundingRect.x + boundingRect.width) / 2;
    ptCurrentCenter.y = (boundingRect.y + boundingRect.y + boundingRect.height) / 2;

    actualCenterPositions.push_back(cv::Point(ptCurrentCenter.x, ptCurrentCenter.y));

    dblDiagonalSize = sqrt(pow(boundingRect.width, 2) + pow(boundingRect.height, 2));

    dblAspectRatio = (float)boundingRect.width / (float)boundingRect.height;

    blnStillBeingTracked = true;
    blnCurrentMatchFoundOrNewBlob = true;

    kalmanFilter = cv::KalmanFilter(4, 2, 0);

    float fltTransitionMatrixValues[4][4] = { { 1, 0, 1, 0 },           // declare an array of floats to feed into Kalman Filter Transition Matrix, also known as State Transition Model
                                              { 0, 1, 0, 1 },
                                              { 0, 0, 1, 0 },
                                              { 0, 0, 0, 1 } };

    kalmanFilter.transitionMatrix = cv::Mat(4, 4, CV_32F, fltTransitionMatrixValues);       // set Transition Matrix

    float fltMeasurementMatrixValues[2][4] = { { 1, 0, 0, 0 },          // declare an array of floats to feed into Kalman Filter Measurement Matrix, also known as Measurement Model
                                               { 0, 1, 0, 0 } };

    kalmanFilter.measurementMatrix = cv::Mat(2, 4, CV_32F, fltMeasurementMatrixValues);     // set Measurement Matrix

    cv::setIdentity(kalmanFilter.processNoiseCov, cv::Scalar::all(0.0001));           // default is 1, for smoothing try 0.0001
    cv::setIdentity(kalmanFilter.measurementNoiseCov, cv::Scalar::all(10));         // default is 1, for smoothing try 10
    cv::setIdentity(kalmanFilter.errorCovPost, cv::Scalar::all(0.1));               // default is 0, for smoothing try 0.1




}






