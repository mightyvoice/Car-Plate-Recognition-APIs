#ifndef PLATE_RECOGNITION_APP_H
#define PLATE_RECOGNITION_APP_H

#include "OpenCVCommon.h"
#include "../include/easypr/api.hpp"

class PlateRecognitionAPI{
private:
	static const float MIN_CHAR_MATCH_VAL;

	static const string SVM_MODEL_PATH;

	static const string ANN_MODEL_PATH;

	static easypr::CPlateRecognize *plateRecognizeInstance;

	static vector<easypr::CPlate> initAllRecognizedPlates();

	static void plate_recognize(Mat img, 
                             const char* model_svm,
                             const char* model_ann,
                             const bool life_mode1 = true);

public:
	static vector<easypr::CPlate> allRecognizedPlates;

	static easypr::CPlateRecognize *getRecognizeInstance();
	static vector<string> plateRecoResults(string picPath);
	static vector<string> plateRecoResults(Mat img);
	static void getAllRecognizedPlates(Mat srcImg);
	static easypr::CPlate getTheBestMatchedPlate(string picPath);
	static void getTheBestMatchedPlate(Mat &srcImg);
	static void plateRecognizeFromVideo(string videoPath);
};

#endif


// namespace easypr {

// class CPlate {
//  public:
//   bool bColored;

//   
//   CPlate();

//   //setter and getter
//   inline void setPlateMat(Mat param) { m_plateMat = param; }
//   inline Mat getPlateMat() const { return m_plateMat; }

//   inline void setPlatePos(RotatedRect param) { m_platePos = param; }
//   inline RotatedRect getPlatePos() const { return m_platePos; }

//   inline void setPlateStr(String param) { m_plateStr = param; }
//   inline String getPlateStr() const { return m_plateStr; }

//   inline void setPlateLocateType(LocateType param) { m_locateType = param; }
//   inline LocateType getPlateLocateType() const { return m_locateType; }

//   //set and get total Match Value
//   inline void setTotalMatchVal(float param) { m_totalMatchVal = param; }
//   inline float getTotalMatchVal() const { return m_totalMatchVal; }

//  // private:
//   //plate Mat
//   Mat m_plateMat;

//   //plate position
//   RotatedRect m_platePos;

//   //plate words
//   String m_plateStr;

//   //method to locate
//   LocateType m_locateType;

//   //total mactch val of each char of the plate from SVM
//   float m_totalMatchVal;
// };

// } /*! \namespace easypr*/


