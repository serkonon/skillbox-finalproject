cmake_minimum_required(VERSION 3.24)
project(SkillboxSearchEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PRJ_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(nlohmann_json)
add_subdirectory(google_tests)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
