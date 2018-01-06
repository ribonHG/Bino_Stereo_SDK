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

#### 1.5安装OpenGL及SDL2
##### 快速安装
```
$sudo apt-get install libgl1-mesa-dev
$sudo apt-get install freeglut3-dev
$sudo apt-get install libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev
```
##### [OpenGL详细配置请见OpenGL官网](https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Linux)

##### [SDL2详细配置请见SDL2官网](https://www.libsdl.org/)

## 2.下载Bino_Stereo_SDK
```
$git clone https://github.com/Bino3D/Bino_Stereo_SDK.git
```

## 3.添加Bino_Stereo_SDK到环境变量
```
$echo "export BINO_STEREO_SDK=<sdk directory>" >> ~/.bashrc
$source ~/.bashrc
```

## 4.编译例子程序
```
$cd <sdk directory>
$./build.sh
```
## 5.快速使用例子程序
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

7 运行run_imu.sh 显示IMU姿态
$./run_imu.sh
```
* 注意：例子程序读取的畸变矫正参数在<sdk directory>/params中，若重新标定了镜头，请覆盖这两个文件再运行例子脚本


## 6.API手册
```
使用浏览器打开
<sdk directory>/doc/html/index.html  
查看
```
## 7.购买链接
[链接](https://item.taobao.com/item.htm?spm=a230r.1.14.36.30447e471pexT6&id=562336856228&ns=1&abbucket=1#detail)

