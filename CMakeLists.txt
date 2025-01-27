cmake_minimum_required(VERSION 3.10)
project(GeantProject)

# Включаем GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

include_directories(/usr/include)

file(GLOB SRC_SOURCES "src/*.cc")  
add_executable(app ${SRC_SOURCES})

# Собираем исходные файлы для тестов
file(GLOB TEST_SOURCES "tests/*.cpp")  

add_executable(tests ${TEST_SOURCES})

target_link_libraries(app ${Geant4_LIBRARIES})

target_link_libraries(tests PRIVATE gtest_main)

target_include_directories(app PRIVATE include)
target_include_directories(tests PRIVATE include)