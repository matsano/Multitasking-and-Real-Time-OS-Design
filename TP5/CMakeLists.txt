# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(timespec_library CXX)

# Set the source and build directories
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Library configuration

add_library(inversion
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/Timer.h
    ${LIB_DIR}/Timer.cpp
    ${LIB_DIR}/Chrono.h
    ${LIB_DIR}/Chrono.cpp
    ${LIB_DIR}/PeriodicTimer.h
    ${LIB_DIR}/PeriodicTimer.cpp
    ${LIB_DIR}/Calibrator.h
    ${LIB_DIR}/Calibrator.cpp
    ${LIB_DIR}/Looper.h
    ${LIB_DIR}/Looper.cpp
    ${LIB_DIR}/CpuLoop.h
    ${LIB_DIR}/CpuLoop.cpp
    ${LIB_DIR}/PosixThread.h
    ${LIB_DIR}/PosixThread.cpp
    ${LIB_DIR}/Thread.h
    ${LIB_DIR}/Thread.cpp
    ${LIB_DIR}/Monitor.h
    ${LIB_DIR}/Monitor.cpp
    ${LIB_DIR}/Lock.h
    ${LIB_DIR}/Lock.cpp
    ${LIB_DIR}/Mutex.h
    ${LIB_DIR}/Mutex.cpp
    ${LIB_DIR}/ExampleThread.h
    ${LIB_DIR}/ExampleThread.cpp
)

# Test file configuration

add_executable(Main
    ${LIB_DIR}/Main.cpp
)

# Link the library to the test executable
target_link_libraries(Main PRIVATE inversion)

# Add the library directory to the include path
target_include_directories(inversion PUBLIC ${LIB_DIR})

# Add the library directory to the test include path
target_include_directories(Main PRIVATE ${LIB_DIR})

# Set the output directories for the library and test executable
set_target_properties(inversion PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
