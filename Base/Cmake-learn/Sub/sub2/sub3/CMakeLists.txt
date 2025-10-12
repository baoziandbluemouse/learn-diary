add_library(multi multi.cpp)
# 设置头文件搜索路径
target_include_directories(multi
        PRIVATE ${PROJECT_SOURCE_DIR}/include
        INTERFACE ${PROJECT_SOURCE_DIR}/include12
)
