add_subdirectory(sub3)

add_library(minus minus.cpp)

target_link_libraries(minus PRIVATE multi)

target_include_directories(minus INTERFACE ${PROJECT_SOURCE_DIR}/include)