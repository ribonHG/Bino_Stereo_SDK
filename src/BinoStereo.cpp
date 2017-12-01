#include <iostream>
#include <stdio.h>
#include<opencv2/opencv.hpp>
#include <BinoCamera.h>
#include <memory>
using namespace std;

int main(int argc, char **argv){
	if(argc != 5)
	{
		cerr << endl << "Usage: ./stereo_bino /dev/video* path_to_intrinsics path_to_extrinsics raw/rect/disparity" << endl;
		return 1;
	}

    BinoCameraParameterList paraList;
    paraList.devPath = argv[1];
    paraList.intParameterPath = argv[2];
    paraList.extParameterPath = argv[3];

    std::string run_para = argv[4];
    cv::Mat left;
	cv::Mat right;
	cv::Mat para;
    cv::Mat disp;

    std::shared_ptr<BinoCamera> camera(new BinoCamera(paraList));
	for(;;){
		if(run_para == "rect"){
            camera->getRectImage(left, right);
            cv::imshow("image_rect_left", left);
            cv::imshow("image_rect_right", right);
        }
		else if(run_para == "raw"){
			camera->getOrgImage(left, right);
		cv::imshow("image_left", left);
		cv::imshow("image_right", right);
        }
        else if(run_para == "disparity"){
			camera->getRectImage(left, right);
            camera->getDisparity(left, right, disp);
            disp.convertTo( disp, CV_8U, 255.0/(48*8) );
            cv::applyColorMap( disp, disp, cv::COLORMAP_JET );
            cv::imshow("image_disparity", disp);
        }

	    int key = cv::waitKey(1);
        if(key == 'q')
            break;
	}
	return 0;
}
