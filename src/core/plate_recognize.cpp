#include "easypr/plate_recognize.h"

/*! \namespace easypr
    Namespace where all the C++ EasyPR functionality resides
*/
namespace easypr {

CPlateRecognize::CPlateRecognize() {
  // cout << "CPlateRecognize" << endl;
  // m_plateDetect= new CPlateDetect();
  // m_charsRecognise = new CCharsRecognise();
}

// !³µÅÆÊ¶±ðÄ£¿é
int CPlateRecognize::plateRecognize(Mat src, std::vector<string> &licenseVec, int index) {
  // ³µÅÆ·½¿é¼¯ºÏ
  vector<CPlate> plateVec;
  // cout<<"index: "<<index<<endl;

  // ½øÐÐÉî¶È¶¨Î»£¬Ê¹ÓÃÑÕÉ«ÐÅÏ¢Óë¶þ´ÎSobel
  int resultPD = plateDetect(src, plateVec, getPDDebug(), index);

  if (resultPD == 0) {
    int num = plateVec.size();
    int i = 0;

    //ÒÀ´ÎÊ¶±ðÃ¿¸ö³µÅÆÄÚµÄ·ûºÅ
    for (int j = 0; j < num; j++) {
      CPlate item = plateVec[j];
      Mat plate = item.getPlateMat();

      //»ñÈ¡³µÅÆÑÕÉ«
      string plateType = getPlateColor(plate);

      //»ñÈ¡³µÅÆºÅ
      string plateIdentify = "";
      int resultCR = charsRecognise(plate, plateIdentify, index);
      if (resultCR == 0) {
        string license = plateType + ":" + plateIdentify;
        cout<<"shi: "<<license<<endl;
        licenseVec.push_back(license);
      }
    }
    //ÍêÕûÊ¶±ð¹ý³Ìµ½´Ë½áÊø

    //Èç¹ûÊÇDebugÄ£Ê½£¬Ôò»¹ÐèÒª½«¶¨Î»µÄÍ¼Æ¬ÏÔÊ¾ÔÚÔ­Í¼×óÉÏ½Ç
    if (getPDDebug() == true) {
      Mat result;
      src.copyTo(result);

      for (int j = 0; j < num; j++) {
        CPlate item = plateVec[j];
        Mat plate = item.getPlateMat();

        int height = 36;
        int width = 136;
        if (height * i + height < result.rows) {
          Mat imageRoi = result(Rect(0, 0 + height * i, width, height));
          addWeighted(imageRoi, 0, plate, 1, 0, imageRoi);
        }
        i++;

        RotatedRect minRect = item.getPlatePos();
        Point2f rect_points[4];
        minRect.points(rect_points);

        Scalar lineColor = Scalar(255, 255, 255);

        if (item.getPlateLocateType() == SOBEL) lineColor = Scalar(255, 0, 0);

        if (item.getPlateLocateType() == COLOR) lineColor = Scalar(0, 255, 0);

        for (int j = 0; j < 4; j++)
          line(result, rect_points[j], rect_points[(j + 1) % 4], lineColor, 2,
               8);
      }

      //ÏÔÊ¾¶¨Î»¿òµÄÍ¼Æ¬
      showResult(result);
    }
  }

  return resultPD;
}

// !车牌识别模块
int CPlateRecognize::tcl_plateRecognize(Mat src,
                                    std::vector<std::string> &licenseVec,
                                    int index, 
                                    std::vector<CPlate> &plateVec) {
  // 车牌方块集合
  // std::vector<CPlate> plateVec;
  // 进行深度定位，使用颜色信息与二次Sobel
  // int resultPD = plateDetect(src, plateVec, getPDDebug(), 0);

  // ½øÐÐÉî¶È¶¨Î»£¬Ê¹ÓÃÑÕÉ«ÐÅÏ¢Óë¶þ´ÎSobel
  int resultPD = plateDetect(src, plateVec, getPDDebug(), index);

  if (resultPD == 0) {
    int num = plateVec.size();
    int i = 0;

    //ÒÀ´ÎÊ¶±ðÃ¿¸ö³µÅÆÄÚµÄ·ûºÅ
    for (int j = 0; j < num; j++) {
      CPlate &item = plateVec[j];
      Mat plate = item.getPlateMat();

      //»ñÈ¡³µÅÆÑÕÉ«
      string plateType = getPlateColor(plate);

      //»ñÈ¡³µÅÆºÅ
      string plateIdentify = "";
      float totalMatchVal = 0;
      int resultCR = tcl_charsRecognise(plate, plateIdentify, totalMatchVal, index);
      if (resultCR == 0) {
        // string license = plateType + ":" + plateIdentify;
        string license = plateIdentify;
        // cout<<"plate: "<<license<<", Match score: "<<totalMatchVal<<endl;
        item.setPlateStr(license);
        item.setTotalMatchVal(totalMatchVal);
        licenseVec.push_back(license);
      }
    }
    //ÍêÕûÊ¶±ð¹ý³Ìµ½´Ë½áÊø

    //Èç¹ûÊÇDebugÄ£Ê½£¬Ôò»¹ÐèÒª½«¶¨Î»µÄÍ¼Æ¬ÏÔÊ¾ÔÚÔ­Í¼×óÉÏ½Ç
    if (getPDDebug() == true) {
      Mat result;
      src.copyTo(result);

      for (int j = 0; j < num; j++) {
        CPlate item = plateVec[j];
        Mat plate = item.getPlateMat();

        int height = 36;
        int width = 136;
        if (height * i + height < result.rows) {
          Mat imageRoi = result(Rect(0, 0 + height * i, width, height));
          addWeighted(imageRoi, 0, plate, 1, 0, imageRoi);
        }
        i++;

        RotatedRect minRect = item.getPlatePos();
        Point2f rect_points[4];
        minRect.points(rect_points);

        Scalar lineColor = Scalar(255, 255, 255);

        if (item.getPlateLocateType() == SOBEL) lineColor = Scalar(255, 0, 0);

        if (item.getPlateLocateType() == COLOR) lineColor = Scalar(0, 255, 0);

        for (int j = 0; j < 4; j++)
          line(result, rect_points[j], rect_points[(j + 1) % 4], lineColor, 2,
               8);
      }

      //ÏÔÊ¾¶¨Î»¿òµÄÍ¼Æ¬
      showResult(result);
    }
  }
  return resultPD;
}


} /*! \namespace easypr*/
