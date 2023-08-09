cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(photonsPMT)

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(phpmt phpmt.cc ${sources} ${headers})
target_link_libraries(phpmt ${Geant4_LIBRARIES})

add_custom_target(photonsPMT DEPENDS phpmt)