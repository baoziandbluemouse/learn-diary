cmake_minimum_required(VERSION 3.31)
project(Cmake_learn)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Sub)


add_executable(Cmake_learn main.cpp)

target_link_libraries(Cmake_learn PRIVATE add)

target_include_directories(Cmake_learn PUBLIC ${PROJECT_SOURCE_DIR}/include PUBLIC ${PROJECT_SOURCE_DIR}/include12)