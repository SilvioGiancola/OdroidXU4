cmake_minimum_required (VERSION 2.8.12 FATAL_ERROR)

# Set Project Name
PROJECT(OdroidXU4)

# include the current directory
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# Add PkgConfig (for libusb-1.0)
find_package(PkgConfig REQUIRED)

# add libusb-1.0 with pkg-config
pkg_search_module(LIBUSB1 REQUIRED libusb-1.0)
include_directories(SYSTEM ${LIBUSB1_INCLUDE_DIRS})


#ADD_EXECUTABLE(testPololu first.cpp protocol.h)
#TARGET_LINK_LIBRARIES(testPololu ${LIBUSB1_LIBRARIES})


find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)
find_package(Qt5Network REQUIRED)

QT5_WRAP_CPP(QT_HEADERS mainwindow.h pololu_controller_widget.h adafruit_widget.h yei_widget.h yei_imu.h)
QT5_WRAP_UI(QT_UIS mainwindow.ui pololu_controller_widget.ui adafruit_widget.ui yei_widget.ui)
set(HEADERS adafruit_uart.h pololu_controller.h protocol.h yei_imu.h)
set(SOURCES main.cpp mainwindow.cpp pololu_controller_widget.cpp adafruit_widget.cpp yei_widget.cpp)

ADD_EXECUTABLE(OdroidSfM ${SOURCES} ${HEADERS} ${QT_HEADERS} ${QT_UIS}  )
TARGET_LINK_LIBRARIES(OdroidSfM ${LIBUSB1_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5SerialPort_LIBRARIES} ${Qt5Network_LIBRARIES})
