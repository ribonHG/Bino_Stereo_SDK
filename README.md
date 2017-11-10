# Bino_Camera_SDK
## 1.使用前准备
本SDK目前只支持linux,测试版本为[ubuntu16.04](https://www.ubuntu.com/download/desktop)
#### 1.1安装build工具
```
$sudo apt-get install build-essential cmake git
```
#### 1.2安装OpenCV依赖
```
$sudo apt-get install pkg-config libgtk2.0-dev
```
#### 1.3安装摄像头驱动依赖
```
$sudo apt-get install libssl-dev libv4l-dev v4l-utils
```

#### 1.4安装OpenCV
##### 快速安装
```
$git clone https://github.com/opencv/opencv.git
$cd opencv/
$git checkout tags/3.2.0
$mkdir build
$cd build/
$cmake ..
$make
```
##### [OpenCV详细配置请见OpenCV官方Git](https://github.com/opencv/opencv)

## 2.下载Bino_Stereo_SDK
```
$git clone https://github.com/Bino3D/Bino_Stereo_SDK.git
```

## 3.编译例子程序
```
$cd <sdk directory>
$mkdir build
$cd build
$cmake ..
$make
```
## 4.快速使用例子程序
```
1 将摄像头插入主机
2 查看摄像头设备ID
$ll /dev/video*
3 将sdk目录下run_raw.sh 摄像头设备额ID修改为刚查看到的设备ID
$cd <sdk directory>
$vim run_raw.sh
```
<img src="https://github.com/Bino3D/Bino_Stereo_SDK/blob/master/editDevID.png"
alt="修改设备id的位置" width="640" height="480" border="10" />

```
4 运行run_raw.sh 显示畸变矫正前图像
$./run_raw.sh

5 运行run_rect.sh 显示畸变矫正后图像
$./run_rect.sh

6 运行run_disp.sh 显示视差图
$./run_disp.sh
```
* 注意：例子程序读取的畸变矫正参数在<sdk directory>/params中，若重新标定了镜头，请覆盖这两个文件再运行例子脚本


## 5.API手册
```
使用浏览器打开
<sdk directory>/doc/html/index.html  
查看
```
