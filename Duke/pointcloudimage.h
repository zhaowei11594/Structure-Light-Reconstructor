#ifndef POINTCLOUDIMAGE_H
#define POINTCLOUDIMAGE_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "utilities.h"

class PointCloudImage
{
public:
    PointCloudImage(int imageW,int imageH, bool color);
    ~PointCloudImage(void);

    bool setPoint(int i_w, int j_h, cv::Point3f point, cv::Vec3i colorgray);//灰度，改cv::Vec3f colorBGR，下同，vec3b表示3维uchar向量
    bool setPoint(int i_w, int j_h, cv::Point3f point);

    bool getPoint(int i_w, int j_h, cv::Point3f &pointOut);
    bool getPoint(int i_w, int j_h, cv::Point3f &pointOut, cv::Vec3i &colorgray);

    bool addPoint(int i_w, int j_h, cv::Point3f point, cv::Vec3i colorgray);
    bool addPoint(int i_w, int j_h, cv::Point3f point);

    void exportNumOfPointsPerPixelImg(char path[]);
    void exportXYZ(char *path,bool exportOffPixels=true, bool colorFlag=true);

    int getWidth();
    int getHeight();

private:
    int w;
    int h;
    cv::Mat points;
    cv::Mat numOfPointsForPixel;
    cv::Mat color;
};

#endif // POINTCLOUDIMAGE_H
