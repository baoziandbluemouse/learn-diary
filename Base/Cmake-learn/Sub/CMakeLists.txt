add_subdirectory(sub2)

add_library(add add.cpp)

target_link_directories(add PUBLIC minus)

target_include_directories(add PUBLIC .)