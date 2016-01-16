#PlateRecognitionAPIs

##Introduction
Based on the project [***EasyPR***](https://github.com/liuruoze/EasyPR), ***OpenCV 2.4***, and ***Cmake***.
Currently, it seems that ***both [***EasyPR***](https://github.com/liuruoze/EasyPR) and my project can work only on Chinese car plates***.
Sorry about this because the various features of car plates all over the world.

My source code locates in the /api directory, which contains my APIs.

The original [***EasyPR***](https://github.com/liuruoze/EasyPR) only provides the APIs returing the words on the plate.
Therefore, I also changed some code so that people can not only get the words, 
but also the position and Mat of a plate.

##Source Code Structure
###/include
All the include files from the [***EasyPR***](https://github.com/liuruoze/EasyPR) project. However, you do not need include any file from this directory.
You can just include /api/PlateRecognitionAPI.h in which I include everthing. I also include the defintion
of a recognized plate in /api/PlateRecognitionAPI.h so that you can access the data in a recognized plate.
Please refer to the /api/PlateRecognitionAPI.h file for more details.

###/src
All the cpp files from the [***EasyPR***](https://github.com/liuruoze/EasyPR) project. You do not need to change any file there since I already changed some
source code here in order to write my APIs. To understand all the cpp files in /src, please refer the original
[***EasyPR***](https://github.com/liuruoze/EasyPR) project's page for more details.

###/api
All the sources I wrote in order to provide APIs for plate recognization.
All the APIs locate in the file ./api/PlateRecognitionAPI.h.

###/test
The directory comes from [***EasyPR***](https://github.com/liuruoze/EasyPR). please refer the original
[***EasyPR***](https://github.com/liuruoze/EasyPR) project's page for more details

###/resource
The directory comes from [***EasyPR***](https://github.com/liuruoze/EasyPR). please refer the original
[***EasyPR***](https://github.com/liuruoze/EasyPR) project's page for more details

###/CmakeFiles
Directory created by Cmake

###/CMakeLists.txt
The Cmake file, you can change it based on your needs.

###/problem_findings.txt
Contains what the problems I find for current plate recognition algorithm

##APIs
I provid the following APIs:

```cpp
void PlateRecognitionAPI::getAllRecognizedPlates(Mat srcImg);
/*
 Get all the recognized plates. the results are saved in the 
 public member: allRecognizedPlates. You can then access all the
 properties of all the plates.
*/
```

```cpp
easypr::CPlate PlateRecognitionAPI::getTheBestMatchedPlate(string picPath);
/*    
Return the best matched plate from by inputting the 
picture's path. The CPlate structure is also included 
in ./app/PlateRecognitionApp.h with annotations for users 
to get userful information easily.
*/
```

```cpp
void PlateRecognitionAPI:: getTheBestMatchedPlate(Mat &srcImg);
/*
Process the input image and show the recognition result by 
adding a rectangle to show the plate with words above.
*/
```

```cpp
void PlateRecognitionAPI::plateRecognizeFromVideo(string videoPath);
/*
Recognize plates in a video and show the results instantly.
*/
```