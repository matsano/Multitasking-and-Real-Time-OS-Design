# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(timespec_library CXX)

# Set the source and build directories
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Library configuration

add_library(calib
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/Timer.h
    ${LIB_DIR}/Timer.cpp
    ${LIB_DIR}/PeriodicTimer.h
    ${LIB_DIR}/PeriodicTimer.cpp
    ${LIB_DIR}/Calibrator.h
    ${LIB_DIR}/Calibrator.cpp
    ${LIB_DIR}/Looper.h
    ${LIB_DIR}/Looper.cpp
    ${LIB_DIR}/CpuLoop.h
    ${LIB_DIR}/CpuLoop.cpp
)

# Test file configuration

add_executable(MainC
    ${LIB_DIR}/MainC.cpp
)

# Link the library to the test executable
target_link_libraries(MainC PRIVATE calib)

# Add the library directory to the include path
target_include_directories(calib PUBLIC ${LIB_DIR})

# Add the library directory to the test include path
target_include_directories(MainC PRIVATE ${LIB_DIR})

# Set the output directories for the library and test executable
set_target_properties(calib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainC PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
