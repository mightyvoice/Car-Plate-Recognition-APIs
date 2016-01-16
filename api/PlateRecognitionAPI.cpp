
#include "PlateRecognitionAPI.h"

easypr::CPlateRecognize *PlateRecognitionAPI::plateRecognizeInstance = NULL;

const float PlateRecognitionAPI::MIN_CHAR_MATCH_VAL = 1.5;

const string PlateRecognitionAPI::SVM_MODEL_PATH = "resources/model/svm.xml";

const string PlateRecognitionAPI::ANN_MODEL_PATH = "resources/model/ann.xml";

vector<easypr::CPlate> PlateRecognitionAPI::allRecognizedPlates = initAllRecognizedPlates();

vector<easypr::CPlate> PlateRecognitionAPI::initAllRecognizedPlates(){
	vector<easypr::CPlate> res;
	return res;
}

easypr::CPlateRecognize *PlateRecognitionAPI::getRecognizeInstance(){
	if(plateRecognizeInstance == NULL){
        plateRecognizeInstance = new easypr::CPlateRecognize();
      	plateRecognizeInstance->LoadSVM(SVM_MODEL_PATH);
      	plateRecognizeInstance->LoadANN(ANN_MODEL_PATH);
      	getRecognizeInstance()->setLifemode(true);
	    getRecognizeInstance()->setDebug(false);
  	}
  	return plateRecognizeInstance;
}

vector<string> PlateRecognitionAPI::plateRecoResults(string picPath){
	// vector<string> ans;
	vector<string> res;
	map<string, int> strMap;
	res = easypr::api::plate_recognize(picPath.c_str(), 
		"resources/model/svm.xml",
		"resources/model/ann.xml",
		true);
	for(auto s: res){
		// ans.push_back(s);
		cout<<"Plate: "<<s<<endl;
		strMap[s]++;
	}
	for(auto s: res){
		cout<<s<<": "<<strMap[s]<<endl;
	}

	return res;
}


void PlateRecognitionAPI::plate_recognize(Mat img, 
                             const char* model_svm,
                             const char* model_ann,
                             const bool life_mode1){
  assert(!img.empty());
  
  vector<string> results;
  // vector<easypr::CPlate> allPlates;
  getRecognizeInstance()->tcl_plateRecognize(img, results, 0, allRecognizedPlates);
  // return allPlates;
}

easypr::CPlate PlateRecognitionAPI::getTheBestMatchedPlate(string picPath){
	// vector<string> ans;
	// vector<easypr::CPlate> res;
	easypr::CPlate returnPlate;
	allRecognizedPlates.clear();
	Mat srcImg = imread(picPath);
	if(srcImg.empty()){
		return returnPlate;
	}
	//find all the plates
	plate_recognize(srcImg, 
		SVM_MODEL_PATH.c_str(),
		ANN_MODEL_PATH.c_str(),
		true);

	//if no plates find, return;
	if(allRecognizedPlates.size() == 0){
		cout<<"No plates find: algorithm does not find any plate"<<endl;
		return returnPlate;
	}

	// cout<<res.size()<<endl;
	int index = -1;
	float maxMatchVal = -100000;
	for(int i = 0; i < allRecognizedPlates.size(); i++){
		// ans.push_back(s);
		easypr::CPlate &plate = allRecognizedPlates[i];
		// cout<<plate.getPlateStr().length()<<endl;
		RotatedRect &rect = plate.m_platePos;
		float matchVal = plate.getTotalMatchVal();

		if(rect.size.width*2 <= rect.size.height){
			swap(rect.size.width, rect.size.height);
		}

		if(matchVal > MIN_CHAR_MATCH_VAL && rect.size.width >= rect.size.height*2 && matchVal > maxMatchVal){
		// if(matchVal > maxMatchVal){
			index = i;
			maxMatchVal = matchVal;
		}
		
		// if(matchVal > MIN_CHAR_MATCH_VAL){
			cout<<"Plate: "<<plate.getPlateStr()<<", Match val: "<<matchVal<<
			   ", Center: "<<rect.center.x<<' '<<rect.center.y<<
			   ", Size: "<<rect.size.width<<' '<<rect.size.height<<endl;
		// }
			// namedWindow("plate", WINDOW_AUTOSIZE);
		 //    imshow("plate", plate.m_plateMat);
		 //    waitKey();
	}

	//if there is a best matched plate
	if(index > -1){
		returnPlate = allRecognizedPlates[index];
		cout<<"The best matched one: "<<allRecognizedPlates[index].getPlateStr()<<' '<<allRecognizedPlates[index].getTotalMatchVal()<<endl;
		Mat plateMat = allRecognizedPlates[index].getPlateMat();
		string plateStr = allRecognizedPlates[index].getPlateStr();
		if(plateStr.length() < 2){
			cout<<"No plates find: The best matched plate's word is to short"<<endl;
			return returnPlate;
		}
		plateStr = plateStr.substr(2, plateStr.length()-2);
		RotatedRect platePos = allRecognizedPlates[index].getPlatePos();
		if(platePos.size.width >= platePos.size.height*1.5){
			float wordX = platePos.center.x - platePos.size.width/2;
			float wordY = platePos.center.y - platePos.size.height;
			float plateX1 = wordX;
			float plateY1 = platePos.center.y - platePos.size.height/2;
			float plateX2 = plateX1 + platePos.size.width;
			float plateY2 = plateY1 + platePos.size.height;
			// cout<<wordX<<' '<<wordY<<endl;
			rectangle(srcImg, Point((int)plateX1, (int)plateY1), Point((int)plateX2, (int)plateY2), Scalar(255,0,0), 3);  
			putText(srcImg, plateStr, Point((int)wordX, (int)wordY), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0), 2); 

			namedWindow("plate", WINDOW_AUTOSIZE);
		    imshow("plate", srcImg);
		    waitKey();
		}
	}
	else{
		cout<<"No plates find: Only find invalid plates"<<endl;
	}
	return returnPlate;
}


void PlateRecognitionAPI::getTheBestMatchedPlate(Mat &srcImg){
	// vector<string> ans;
	// vector<easypr::CPlate> res;
	allRecognizedPlates.clear();
	//find all the plates
	plate_recognize(srcImg, 
		SVM_MODEL_PATH.c_str(),
		ANN_MODEL_PATH.c_str(),
		true);

	//if no plates find, return;
	if(allRecognizedPlates.size() == 0){
		return;
	}

	// cout<<res.size()<<endl;
	int index = -1;
	float maxMatchVal = -100000;
	for(int i = 0; i < allRecognizedPlates.size(); i++){
		// ans.push_back(s);
		easypr::CPlate &plate = allRecognizedPlates[i];
		// cout<<plate.getPlateStr().length()<<endl;
		RotatedRect &rect = plate.m_platePos;
		float matchVal = plate.getTotalMatchVal();

		if(rect.size.width*2 <= rect.size.height){
			swap(rect.size.width, rect.size.height);
		}

		if(matchVal > MIN_CHAR_MATCH_VAL && rect.size.width >= rect.size.height*2 && matchVal > maxMatchVal){
		// if(matchVal > maxMatchVal){
			index = i;
			maxMatchVal = matchVal;
		}
		
		if(matchVal > MIN_CHAR_MATCH_VAL){
			cout<<"Plate: "<<plate.getPlateStr()<<", Match val: "<<matchVal<<
			   ", Center: "<<rect.center.x<<' '<<rect.center.y<<
			   ", Size: "<<rect.size.width<<' '<<rect.size.height<<endl;
		}
	}

	//if there is a best matched plate
	if(index > -1){
		cout<<"The best matched one: "<<allRecognizedPlates[index].getPlateStr()<<' '<<allRecognizedPlates[index].getTotalMatchVal()<<endl;
		Mat plateMat = allRecognizedPlates[index].getPlateMat();
		string plateStr = allRecognizedPlates[index].getPlateStr();
		if(plateStr.length() < 2) return;
		plateStr = plateStr.substr(2, plateStr.length()-2);
		RotatedRect platePos = allRecognizedPlates[index].getPlatePos();
		if(platePos.size.width >= platePos.size.height*1.5){
			float wordX = platePos.center.x - platePos.size.width/2;
			float wordY = platePos.center.y - platePos.size.height;
			float plateX1 = wordX;
			float plateY1 = platePos.center.y - platePos.size.height/2;
			float plateX2 = plateX1 + platePos.size.width;
			float plateY2 = plateY1 + platePos.size.height;
			rectangle(srcImg, Point((int)plateX1, (int)plateY1), Point((int)plateX2, (int)plateY2), Scalar(255,0,0), 3);  
			putText(srcImg, plateStr, Point((int)wordX, (int)wordY), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0), 2);  
		}
	}
}

vector<string> PlateRecognitionAPI::plateRecoResults(Mat img){
  assert(!img.empty());
  easypr::CPlateRecognize pr;
  pr.LoadSVM("resources/model/svm.xml");
  pr.LoadANN("resources/model/ann.xml");
  pr.setLifemode(true);
  pr.setDebug(false);
  std::vector<std::string> results;
  pr.plateRecognize(img, results);
  return std::move(results);
}

void PlateRecognitionAPI::getAllRecognizedPlates(Mat srcImg){
	plate_recognize(srcImg, SVM_MODEL_PATH.c_str(), ANN_MODEL_PATH.c_str(), true);
}

void PlateRecognitionAPI::plateRecognizeFromVideo(string videoPath){
	VideoCapture vc;
	vc.open(videoPath.c_str());
	string window_name = "processed_video";
	int count = 0;
	const int COUNT_TO_SAMPLE = 5;
	if(vc.isOpened()){

		////////////////////write video initialization
		VideoWriter vw;  
        vw.open( "./output.mp4", // 输出视频文件名  
                (int)vc.get( CV_CAP_PROP_FOURCC ), // 也可设为CV_FOURCC_PROMPT，在运行时选取  
                (double)vc.get( CV_CAP_PROP_FPS ), // 视频帧率  
                cv::Size( (int)vc.get( CV_CAP_PROP_FRAME_WIDTH ), (int)vc.get( CV_CAP_PROP_FRAME_HEIGHT ) ), // 视频大小  
                true ); // 是否输出彩色视频 
		////////////////////write video initialization

		Mat frame;
		while(true){
			vc >> frame;
			// vc.read(frame);
			count++;
			long bt;
			if(count == 1) bt = clock();
			if(count >= COUNT_TO_SAMPLE){
				count = 0;
				if(frame.empty()){
					break;
				}
				long beginTime = clock();
				// cout<<"Sample Time: "<<(beginTime-bt)*1.0/CLOCKS_PER_SEC<<endl;
				getTheBestMatchedPlate(frame);
				long endTime = clock();
				cout<<"Recognize Time: "<<(endTime-beginTime)*1.0/CLOCKS_PER_SEC<<endl;
				cout<<endl<<endl;
				vw<<frame;
				imshow(window_name, frame);
				int c = waitKey(10);
            	if( (char)c == 'c' ){
            		break;
            	}
            }
		}
	}
	vc.release();
}


