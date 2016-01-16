
#include "MyLib.hpp"

void MyLib::reverseStr(string &s){
	int l = 0, r = s.length()-1;
	while(l < r) swap(s[l++], s[r--]);
}

string MyLib::getNameFromFileName(string fileName){
	string res = "";
	int r = fileName.length()-1;
	int l = 0;
	while(r >= 0 && fileName[r] != '.') r--;
	r--;
	while(l < fileName.length() && fileName[l] != '/') l++;
	if(l == fileName.length()) l = 0;
	if(r < 0) r = fileName.length()-1;
	for(int i = l; i <= r; i++){
		res += fileName[i];
	}
	return res;
}

void MyLib::writeMatToJpgFile(Mat src, string fileName){
	vector<uchar> buff;
	vector<int> param = vector<int>(2);
	param[0] = CV_IMWRITE_JPEG_QUALITY;
	param[1] = 95;

	// imencode(".jpg", src, buff, param);
	// Mat jpgImg = imdecode(Mat(buff), CV_LOAD_IMAGE_COLOR);
	imwrite(fileName, src, param);
}

string MyLib::int2String(int x){
	if(x == 0) return "0";
	string ans = "";
	while(x){
		ans += (char)('0'+x%10);
		x /= 10;
	}
	reverseStr(ans);
	return ans;
}

void MyLib::printRect(Rect a){
	cout<<"x: "<<a.x<<"; ";
	cout<<"y: "<<a.y<<"; ";
	cout<<"width: "<<a.width<<"; ";
	cout<<"height: "<<a.height<<endl;
}

void MyLib::limitToBoundary(Rect &body, int rows, int cols){
    body.x = std::max(0, body.x);
    body.y = std::max(0, body.y);
    body.y = std::min(rows-1, body.y);
    body.width = std::min(cols-body.x-1, body.width);
    body.height = std::min(rows-body.y-1, body.height);
}


vector<string> MyLib::getAllFileNamesFromDir(string dirPath){
    vector<string> res;
    DIR* dir;
    struct dirent* file;

    if( (dir = opendir(dirPath.c_str())) == NULL){
        cout<<"Can't open the directory: "<<dirPath<<endl;
    }

    while( (file = readdir(dir)) != NULL){
        if(file->d_type == 8 && file->d_name[0] != '.'){
            res.push_back(file->d_name);
            // cout<<file->d_name<<endl;
        }
    }
    closedir(dir);
    return res;
}


