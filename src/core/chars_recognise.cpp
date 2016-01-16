#include "easypr/chars_recognise.h"
#include "easypr/util.h"

/*! \namespace easypr
Namespace where all the C++ EasyPR functionality resides
*/
namespace easypr {

CCharsRecognise::CCharsRecognise() {
  m_charsSegment = new CCharsSegment();
  m_charsIdentify = new CCharsIdentify();
}

CCharsRecognise::~CCharsRecognise() {
  SAFE_RELEASE(m_charsSegment);
  SAFE_RELEASE(m_charsIdentify);
}

void CCharsRecognise::LoadANN(string s) {
  m_charsIdentify->LoadModel(s.c_str());
}

string CCharsRecognise::charsRecognise(Mat plate) {
  return m_charsIdentify->charsIdentify(plate);
}

//recognize all chars
int CCharsRecognise::charsRecognise(Mat plate, string& plateLicense, int index) {
  //车牌字符方块集合
  vector<Mat> matVec;

  string plateIdentify = "";

  int result = m_charsSegment->charsSegment(plate, matVec, index);
  if (result == 0) {
    int num = matVec.size();
    for (int j = 0; j < num; j++) {
      Mat charMat = matVec[j];
      bool isChinses = false;
      bool isSpeci = false;

      //默认首个字符块是中文字符
      if (j == 0) isChinses = true;
      if (j == 1) isSpeci = true;

      string charcater =
          m_charsIdentify->charsIdentify(charMat, isChinses, isSpeci);

      plateIdentify = plateIdentify + charcater;
    }
  }

  plateLicense = plateIdentify;

  if (plateLicense.size() < 7) {
    return -1;
  }

  return result;
}

//recognize all chars
int CCharsRecognise::tcl_charsRecognise(Mat plate, string& plateLicense, 
                                        float &totalMatchVal, int index) {
  //车牌字符方块集合
  vector<Mat> matVec;

  string plateIdentify = "";

  int result = m_charsSegment->charsSegment(plate, matVec, index);
  totalMatchVal = 0;
  if (result == 0) {
    int num = matVec.size();
    for (int j = 0; j < num; j++) {
      Mat charMat = matVec[j];
      bool isChinses = false;
      bool isSpeci = false;
      float matchVal = 0;

      //默认首个字符块是中文字符
      if (j == 0) isChinses = true;
      if (j == 1) isSpeci = true;

      string charcater =
          m_charsIdentify->tcl_charsIdentify(charMat, isChinses, isSpeci, matchVal);

        // cout<<charcater<<endl;

      plateIdentify = plateIdentify + charcater;
      // cout<<matchVal<<endl;
      if(matchVal != -2) totalMatchVal += matchVal;
    }
  }

  plateLicense = plateIdentify;

  if (plateLicense.size() < 5) {
    return -1;
  }

  return result;
}

} /*! \namespace easypr*/