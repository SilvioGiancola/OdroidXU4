cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)

# Set Project Name
PROJECT(testSfM)


include_directories(build) # include the project in se
include_directories(.) # include the project in se

# Add PkgConfig
find_package(PkgConfig REQUIRED)

# add libusb-1.0 with pkg-config
pkg_search_module(LIBUSB1 REQUIRED libusb-1.0)
include_directories(SYSTEM ${LIBUSB1_INCLUDE_DIRS})


# find VTK
set(VTK_DIR "/usr/local/lib")
find_package(VTK 6.2 REQUIRED)
include(${VTK_USE_FILE})

# add pcl
find_package(PCL 1.8 REQUIRED)
IF(PCL_FOUND)
   MESSAGE(STATUS "Found PCL: ${PCL_INCLUDE_DIRS} VERSION : ${PCL_VERSION}")
endif()
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})



#ADD_EXECUTABLE(testPololu first.cpp protocol.h)
#TARGET_LINK_LIBRARIES(testPololu ${LIBUSB1_LIBRARIES})


find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)

QT5_WRAP_CPP(SRC mainwindow.h pololu_controller_widget.h adafruit_widget.h)
QT5_WRAP_UI(UI mainwindow.ui pololu_controller_widget.ui adafruit_widget.ui)

ADD_EXECUTABLE(testPololuGUI ${UI} ${SRC} mainwindow.cpp pololu_controller_widget.cpp adafruit_widget.cpp adafruit_uart.h pololu_controller.h protocol.h)
TARGET_LINK_LIBRARIES(testPololuGUI ${LIBUSB1_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5SerialPort_LIBRARIES} ${PCL_LIBRARIES})
