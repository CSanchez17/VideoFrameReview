 cmake_minimum_required(VERSION 3.5)

project(cvTest LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
set(OpenCv_DIR "C:\\Users\\Home\\Desktop\\Repos\\opencv-4.2.0\\bin")
find_package(OpenCV REQUIRED)
message("OpenCv Pakage: " ${OpenCv_DIR})

set(${OpenCV_INCLUDE_DIRS} ${OpenCv_DIR}/include)
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(OPENCV_LIBRARIES ${OpenCv_DIR}/x64/vc15/bin)
message("OpenCv includes: " ${OpenCV_INCLUDE_DIRS})
message("#############: ")
message("OPENCV_LIBRARIES: " ${OPENCV_LIBRARIES})



# Sources
set (SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/cvclass.cpp
    ${CMAKE_SOURCE_DIR}/src/frameprovider.cpp
    ${CMAKE_SOURCE_DIR}/src/framemodel.cpp
    ${CMAKE_SOURCE_DIR}/src/threadgetframes.cpp
    ${CMAKE_SOURCE_DIR}/src/modelmanager.cpp)

# Headers
set (HEADERS
    ${CMAKE_SOURCE_DIR}/src/cvclass.h
    ${CMAKE_SOURCE_DIR}/src/frameprovider.h
    ${CMAKE_SOURCE_DIR}/src/framemodel.h
    ${CMAKE_SOURCE_DIR}/src/threadgetframes.h
    ${CMAKE_SOURCE_DIR}/src/modelmanager.h)

# Qt Resources
qt5_add_resources(RES
        ${CMAKE_SOURCE_DIR}/res/views.qrc
    )


if(ANDROID)
    add_library(cvTest SHARED
      main.cpp
      qml.qrc
    )
else()
#    add_executable(cvTest
#      main.cpp
#      qml.qrc
#      cvclass.cpp
#      cvclass.h
#      myimageprovider.cpp
#      myimageprovider.h
#      idimagesmodel.cpp
#      idimagesmodel.h
#    )
    add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${RES})
endif()

target_compile_definitions(cvTest
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(cvTest
  PRIVATE Qt5::Core Qt5::Quick
  ${OpenCV_LIBS})
