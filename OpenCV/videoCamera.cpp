#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

/*
Following this tutorial enables us to use OpenCV with Codeblocks C++:
https://medium.com/@sourabhjigjinni/install-opencv-4-0-0-for-c-windows-7-10-code-blocks-tdm-gcc-64-dff65addf162

*/

int main() {

	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "Error initializing video camera!" << endl;
		return -1;
	}

	char* windowName = "Webcam Feed";
	namedWindow(windowName, WINDOW_AUTOSIZE);

	while (1) {

		Mat frame;
		bool bSuccess = cap.read(frame);

		if (!bSuccess) {
			cout << "Error reading frame from camera feed" << endl;
			break;
		}

		imshow(windowName, frame);
		switch (waitKey(10)) {
		case 27:
			return 0;
		}
	}
	return 0;
}