# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(timespec_library CXX)

# Set the source and build directories
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Library configuration
add_library(incr
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/CounterIncrementer.h
    ${LIB_DIR}/CounterIncrementer.cpp
)

add_library(incrMutex
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/CounterIncrementer.h
    ${LIB_DIR}/CounterIncrementer.cpp
)


# Test file configuration
add_executable(MainA
    ${LIB_DIR}/MainA.cpp
)

add_executable(MainB
    ${LIB_DIR}/MainB.cpp
)


# Link the library to the test executable
target_link_libraries(MainA PRIVATE incr)
target_link_libraries(MainB PRIVATE incrMutex)

# Add the library directory to the include path
target_include_directories(incr PUBLIC ${LIB_DIR})
target_include_directories(incrMutex PUBLIC ${LIB_DIR})

# Add the library directory to the test include path
target_include_directories(MainA PRIVATE ${LIB_DIR})
target_include_directories(MainB PRIVATE ${LIB_DIR})

# Set the output directories for the library and test executable
set_target_properties(incr PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainA PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set_target_properties(incrMutex PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainB PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
