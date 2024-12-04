cmake_minimum_required(VERSION 3.10...3.20)


project(MyGeant4Project)

find_package(Geant4 REQUIRED)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(geantExamp main.cc ${sources} ${headers})
target_link_libraries(geantExamp ${Geant4_LIBRARIES})


