
#include "PlateRecognitionAPI.h"

int main(int argc, char** argv){
    // PlateRecognitionAPI::plateRecoResults(argv[1]);
//    Mat srcImg = imread("11.mp4");
//    cout<<srcImg.raws<<' '<<srcImg.
    // PlateRecognitionAPI::getTheBestMatchedPlate(srcImg);
    // PlateRecognitionAPI::getTheBestMatchedPlate("11.mp4");
    PlateRecognitionAPI::plateRecognizeFromVideo(argv[1]);

    return 0;
}
