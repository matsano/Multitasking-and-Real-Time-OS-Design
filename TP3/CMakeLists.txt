# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(timespec_library CXX)

# Set the source and build directories
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Library configuration
add_library(crono
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/Chrono.h
    ${LIB_DIR}/Chrono.cpp
)

add_library(timer
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/Timer.h
    ${LIB_DIR}/Timer.cpp
    ${LIB_DIR}/CountDown.h
    ${LIB_DIR}/CountDown.cpp
)

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
add_executable(MainA
    ${LIB_DIR}/MainA.cpp
)

add_executable(MainB
    ${LIB_DIR}/MainB.cpp
)

add_executable(MainC
    ${LIB_DIR}/MainC.cpp
)

# Link the library to the test executable
target_link_libraries(MainA PRIVATE crono)
target_link_libraries(MainB PRIVATE timer)
target_link_libraries(MainC PRIVATE calib)

# Add the library directory to the include path
target_include_directories(crono PUBLIC ${LIB_DIR})
target_include_directories(timer PUBLIC ${LIB_DIR})
target_include_directories(calib PUBLIC ${LIB_DIR})

# Add the library directory to the test include path
target_include_directories(MainA PRIVATE ${LIB_DIR})
target_include_directories(MainB PRIVATE ${LIB_DIR})
target_include_directories(MainC PRIVATE ${LIB_DIR})

# Set the output directories for the library and test executable
set_target_properties(crono PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainA PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set_target_properties(timer PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainB PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set_target_properties(calib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainC PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
