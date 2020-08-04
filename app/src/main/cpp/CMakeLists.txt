# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

add_library(binder_lib SHARED IMPORTED)
set_target_properties(binder_lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_LIST_DIR}/../../../libs/${ANDROID_ABI}/libbinder.so)

add_library(utils_lib SHARED IMPORTED)
set_target_properties(utils_lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_LIST_DIR}/../../../libs/${ANDROID_ABI}/libutils.so)

add_library(audio_client SHARED IMPORTED)
set_target_properties(audio_client
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_CURRENT_LIST_DIR}/../../../libs/${ANDROID_ABI}/libaudioclient.so)

#include_directories(${CMAKE_CURRENT_LIST_DIR}/include/)
include_directories(/opt/aosp/system/core/libutils/include/)
include_directories(/opt/aosp/system/core/liblog/include/)
include_directories(/opt/aosp/system/core/base/include/)
include_directories(/opt/aosp/system/core/libcutils/include/)
include_directories(/opt/aosp/frameworks/native/include/)
include_directories(/opt/aosp/frameworks/av/include/)
include_directories(/opt/aosp/system/media/audio/include/)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

        binder_lib
        utils_lib
        audio_client
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )