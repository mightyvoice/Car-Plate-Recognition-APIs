
#include "PlateRecognitionAPI.h"

int main(int argc, char** argv){
    // PlateRecognitionAPI::plateRecoResults(argv[1]);
//    Mat srcImg = imread("11.mp4");
//    cout<<srcImg.raws<<' '<<srcImg.
    // PlateRecognitionAPI::getTheBestMatchedPlate(srcImg);
    // PlateRecognitionAPI::getTheBestMatchedPlate("11.mp4");
    PlateRecognitionAPI::plateRecognizeFromVideo(argv[1]);

	// VideoCapture cap(0); // open the video camera no. 0

 //    if (!cap.isOpened())  // if not success, exit program
 //    {
 //        cout << "ERROR: Cannot open the video file" << endl;
 //        return -1;
 //    }

 // namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

 //   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
 //   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

 //   cout << "Frame Size = " << dWidth << "x" << dHeight << endl;

 //   Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

 // VideoWriter oVideoWriter ("MyVideo.avi", CV_FOURCC('m','p','4','v'), 20, frameSize); //initialize the VideoWriter object 

 //   if ( !oVideoWriter.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
 //   {
 //        cout << "ERROR: Failed to write the video" << endl;
 //        return -1;
 //   }

 //    while (1)
 //    {

 //        Mat frame;

 //        bool bSuccess = cap.read(frame); // read a new frame from video

 //        if (!bSuccess) //if not success, break loop
 //        {
 //             cout << "ERROR: Cannot read a frame from video file" << endl;
 //             break;
 //        }

 //        oVideoWriter.write(frame); //writer the frame into the file

 //        imshow("MyVideo", frame); //show the frame in "MyVideo" window

 //        if (waitKey(1) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
 //        {
 //            cout << "esc key is pressed by user" << endl;
 //            return 0;
 //            break; 
 //        }
 //    }

    return 0;
}
