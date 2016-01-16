#ifndef MY_LIB_HPP
#define MY_LIB_HPP

#include "OpenCVCommon.h"

class MyLib{
public:
	static void reverseStr(string &s);
	static string getNameFromFileName(string fileName);
	static void writeMatToJpgFile(Mat src, string fileName);
	static vector<string> getAllFileNamesFromDir(string dirPath);
	static string int2String(int x);
	static void printRect(Rect a);
	static void limitToBoundary(Rect &img, int row, int cols);
};

#endif
