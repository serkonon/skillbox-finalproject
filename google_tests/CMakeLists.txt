# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
add_executable(Google_Tests_run test1.cpp ${PRJ_INCLUDE_DIR}/invertedindex.h ${PRJ_SOURCE_DIR}/invertedindex.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main nlohmann_json::nlohmann_json)
target_include_directories(Google_Tests_run PUBLIC ${PRJ_INCLUDE_DIR})