cmake_minimum_required(VERSION 2.8)
project (easypr)

# c++11 required
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn’t support C++11. Please upgrade or use a different C++ compiler.")
endif()

# opencv package required
find_package(OpenCV REQUIRED)

# easypr library
include_directories(include)
set(SOURCE_FILES
    src/core/core_func.cpp
    src/core/chars_identify.cpp
    src/core/chars_recognise.cpp
    src/core/chars_segment.cpp
    src/core/feature.cpp
    src/core/plate.cpp
    src/core/plate_detect.cpp
    src/core/plate_judge.cpp
    src/core/plate_locate.cpp
    src/core/plate_recognize.cpp
    src/train/ann_train.cpp
    src/train/svm_train.cpp
    src/preprocess/deface.cpp
    src/preprocess/gdts.cpp
    src/preprocess/mc_data.cpp
    src/util/util.cpp
    src/util/program_options.cpp
    api/PlateRecognitionAPI.cpp
    api/MyLib.cpp
)
add_library(easypr STATIC ${SOURCE_FILES})

# test cases
add_executable(easypr_test api/main.cpp)

target_link_libraries(easypr_test ${OpenCV_LIBS} easypr)
