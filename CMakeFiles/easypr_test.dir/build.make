# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lj/Code/TCL-Project/EasyPR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lj/Code/TCL-Project/EasyPR

# Include any dependencies generated for this target.
include CMakeFiles/easypr_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/easypr_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/easypr_test.dir/flags.make

CMakeFiles/easypr_test.dir/api/main.cpp.o: CMakeFiles/easypr_test.dir/flags.make
CMakeFiles/easypr_test.dir/api/main.cpp.o: api/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lj/Code/TCL-Project/EasyPR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/easypr_test.dir/api/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/easypr_test.dir/api/main.cpp.o -c /Users/lj/Code/TCL-Project/EasyPR/api/main.cpp

CMakeFiles/easypr_test.dir/api/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/easypr_test.dir/api/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lj/Code/TCL-Project/EasyPR/api/main.cpp > CMakeFiles/easypr_test.dir/api/main.cpp.i

CMakeFiles/easypr_test.dir/api/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/easypr_test.dir/api/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lj/Code/TCL-Project/EasyPR/api/main.cpp -o CMakeFiles/easypr_test.dir/api/main.cpp.s

CMakeFiles/easypr_test.dir/api/main.cpp.o.requires:

.PHONY : CMakeFiles/easypr_test.dir/api/main.cpp.o.requires

CMakeFiles/easypr_test.dir/api/main.cpp.o.provides: CMakeFiles/easypr_test.dir/api/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/easypr_test.dir/build.make CMakeFiles/easypr_test.dir/api/main.cpp.o.provides.build
.PHONY : CMakeFiles/easypr_test.dir/api/main.cpp.o.provides

CMakeFiles/easypr_test.dir/api/main.cpp.o.provides.build: CMakeFiles/easypr_test.dir/api/main.cpp.o


# Object files for target easypr_test
easypr_test_OBJECTS = \
"CMakeFiles/easypr_test.dir/api/main.cpp.o"

# External object files for target easypr_test
easypr_test_EXTERNAL_OBJECTS =

easypr_test: CMakeFiles/easypr_test.dir/api/main.cpp.o
easypr_test: CMakeFiles/easypr_test.dir/build.make
easypr_test: /usr/local/lib/libopencv_core.a
easypr_test: /usr/local/lib/libopencv_flann.a
easypr_test: /usr/local/lib/libopencv_imgproc.a
easypr_test: /usr/local/lib/libopencv_highgui.a
easypr_test: /usr/local/lib/libopencv_features2d.a
easypr_test: /usr/local/lib/libopencv_calib3d.a
easypr_test: /usr/local/lib/libopencv_ml.a
easypr_test: /usr/local/lib/libopencv_video.a
easypr_test: /usr/local/lib/libopencv_legacy.a
easypr_test: /usr/local/lib/libopencv_objdetect.a
easypr_test: /usr/local/lib/libopencv_photo.a
easypr_test: /usr/local/lib/libopencv_gpu.a
easypr_test: /usr/local/lib/libopencv_videostab.a
easypr_test: /usr/local/lib/libopencv_ts.a
easypr_test: /usr/local/lib/libopencv_ocl.a
easypr_test: /usr/local/lib/libopencv_superres.a
easypr_test: /usr/local/lib/libopencv_nonfree.a
easypr_test: /usr/local/lib/libopencv_stitching.a
easypr_test: /usr/local/lib/libopencv_contrib.a
easypr_test: libeasypr.a
easypr_test: /usr/local/lib/libopencv_nonfree.a
easypr_test: /usr/local/lib/libopencv_gpu.a
easypr_test: /usr/local/lib/libopencv_legacy.a
easypr_test: /usr/local/lib/libopencv_photo.a
easypr_test: /usr/local/lib/libopencv_ocl.a
easypr_test: /usr/local/lib/libopencv_calib3d.a
easypr_test: /usr/local/lib/libopencv_features2d.a
easypr_test: /usr/local/lib/libopencv_flann.a
easypr_test: /usr/local/lib/libopencv_ml.a
easypr_test: /usr/local/lib/libopencv_video.a
easypr_test: /usr/local/lib/libopencv_objdetect.a
easypr_test: /usr/local/lib/libopencv_highgui.a
easypr_test: /usr/local/lib/libopencv_imgproc.a
easypr_test: /usr/local/lib/libopencv_core.a
easypr_test: /usr/local/share/OpenCV/3rdparty/lib/liblibjpeg.a
easypr_test: /usr/local/share/OpenCV/3rdparty/lib/liblibpng.a
easypr_test: /usr/local/share/OpenCV/3rdparty/lib/liblibtiff.a
easypr_test: /usr/local/share/OpenCV/3rdparty/lib/liblibjasper.a
easypr_test: /usr/local/share/OpenCV/3rdparty/lib/libIlmImf.a
easypr_test: /usr/local/share/OpenCV/3rdparty/lib/libzlib.a
easypr_test: CMakeFiles/easypr_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lj/Code/TCL-Project/EasyPR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable easypr_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/easypr_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/easypr_test.dir/build: easypr_test

.PHONY : CMakeFiles/easypr_test.dir/build

CMakeFiles/easypr_test.dir/requires: CMakeFiles/easypr_test.dir/api/main.cpp.o.requires

.PHONY : CMakeFiles/easypr_test.dir/requires

CMakeFiles/easypr_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/easypr_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/easypr_test.dir/clean

CMakeFiles/easypr_test.dir/depend:
	cd /Users/lj/Code/TCL-Project/EasyPR && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lj/Code/TCL-Project/EasyPR /Users/lj/Code/TCL-Project/EasyPR /Users/lj/Code/TCL-Project/EasyPR /Users/lj/Code/TCL-Project/EasyPR /Users/lj/Code/TCL-Project/EasyPR/CMakeFiles/easypr_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/easypr_test.dir/depend

