cmake_minimum_required(VERSION 3.7)
project(Observer)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCE_FILES src/main.cpp include/stock_model.h include/stock_observer.h src/stock_observer.cpp src/stock_model.cpp include/stock_view.h src/stock_view.cpp)
add_executable(Observer ${SOURCE_FILES})