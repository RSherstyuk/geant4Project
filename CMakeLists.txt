cmake_minimum_required(VERSION 3.10)
project(GeantProject)

# Включаем GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Указываем директорию с заголовочными файлами
include_directories(/usr/include)

# Собираем исходные файлы для основной программы
file(GLOB SRC_SOURCES "src/*.cc")  # Используем .cc вместо .cpp, если это Geant4
add_executable(app ${SRC_SOURCES})

# Собираем исходные файлы для тестов
file(GLOB TEST_SOURCES "tests/*.cpp")  # Используем правильный синтаксис

add_executable(tests ${TEST_SOURCES})

# Линкуем библиотеки для основной программы
target_link_libraries(app ${Geant4_LIBRARIES})

# Линкуем библиотеки для тестов
target_link_libraries(tests PRIVATE gtest_main)

# Указываем директории с заголовочными файлами
target_include_directories(app PRIVATE include)
target_include_directories(tests PRIVATE include)