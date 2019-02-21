cmake_minimum_required(VERSION 2.8.4)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME FlexActuator)
set(${PROJECT_NAME}_BOARD mega)
set(ARDUINO_CPU atmega2560)

project(${PROJECT_NAME})
# set(${PROJECT_NAME}_SKETCH FlexActuator.ino)
set(${PROJECT_NAME}_SRCS src/FlexActuator.cpp src/FlexPipe.cpp)
set(${PROJECT_NAME}_HDRS src/FlexActuator.h src/FlexPipe.h)
# set(${PROJECT_NAME}_LIBS)
# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
# add_subdirectory()

# set(${PROJECT_NAME}_PROGRAMMER avrispmkii)
# set(${PROJECT_NAME}_PORT /dev/cu.usbserial-00000000)
# set(${PROJECT_NAME}_AFLAGS -v)
# set(mega.upload.speed 9600)

generate_arduino_library(${PROJECT_NAME})
