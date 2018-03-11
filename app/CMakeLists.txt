# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(src/main/cpp/)

## C++ flags
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti -fexceptions")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
#
## C flags
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -fvisibility=hidden")
#
## Debug/release
#SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} .... ")
#SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ....")
#SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} .... ")
## Linker flags
#

add_library( # Sets the name of the library.
             ndkdemo

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/JNIBridge.cpp
             src/main/cpp/ReferenceTable.cpp
             src/main/cpp/NativeThread.cpp
             src/main/cpp/Exception.cpp
             src/main/cpp/Class1.cpp
             src/main/cpp/Class2.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.


#IMPORTANT C++ compiler flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -frtti -fexceptions -ffunction-sections -fdata-sections -fvisibility=hidden")

find_library( log-lib log )

target_link_libraries( ndkdemo ${log-lib} )