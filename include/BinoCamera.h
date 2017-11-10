/*
 * StereoCamera.h
 *
 *  Created on: 2017年11月6日
 *      Author: Jiangbo
 */

#ifndef SDKLINK_SDKSRC_BINOCAMERA_H_
#define SDKLINK_SDKSRC_BINOCAMERA_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <functional>
#include <thread>
#include <mutex>

/**
 *@brief 相机参数表述结构体 
 *其中包含相
 * */
struct BinoCameraParameterList{
    std::string devPath = "/dev/video0";  /**< 设备节点地址 */
    std::string extParameterPath = "";    /**< 相机标定外参文件所在地址*/
    std::string intParameterPath = "";    /**< 相机标定内参文件所在地址*/
};

/**
 *@brief BinoCamera 类头文件 
 *
 * */
class BinoCamera {
public:
    /*
     *@brief BinoCamera 构造函数
     *@param paraList 传入的相机启动参数
     * */
	BinoCamera(BinoCameraParameterList paraList);
	virtual ~BinoCamera();
    /**
     *@brief 得到双目原始图像
     *@param L 返回左相机图像
     *@param R 返回右相机图像
     * */
	void getOrgImage(cv::Mat& L, cv::Mat& R);
    /**
     @brief 得到双目畸变矫正后图像
     @param L 返回左相机矫正后图像
     @param R 返回右相机矫正后图像
     * */
	void getRectImage(cv::Mat& L, cv::Mat& R);
    /**
     @brief 得到得到视差图 
     @param rectLeft 输入左相机矫正后图像
     @param rectRight 输入右相机矫正后图像
     @param disparateU16Mat 返回uint16类型的视差图，想得到真实视差值需要转换为float型数据，转换例子：
      matU16.convertTo( matF32, CV_32F, 1.0/16);
     * */
	void getDisparity(const cv::Mat& rectLeft,
			const cv::Mat& rectRight,
			cv::Mat& disparateU16Mat);
    /**
     @brief 获取相机参数 
     @param para 返回Mat数据的类型为CV_64FC1，row = 1, col = 7，数据内容为：
     fx,fy,cx,cy,image_wideth,image_height,bf
     * */
    bool getCameraParameter(cv::Mat& para);
};

#endif /* SDKLINK_SDKSRC_BINOCAMERA_H_ */
