# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name and language
project(timespec_library CXX)

# Set the source and build directories
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Library configuration
add_library(thread
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/PosixThread.h
    ${LIB_DIR}/PosixThread.cpp
    ${LIB_DIR}/Thread.h
    ${LIB_DIR}/Thread.cpp
    ${LIB_DIR}/IncrThread.h
    ${LIB_DIR}/IncrThread.cpp
)

# Test file configuration
add_executable(MainA
    ${LIB_DIR}/MainA.cpp
)


# Link the library to the test executable
target_link_libraries(MainA PRIVATE thread)

# Add the library directory to the include path
target_include_directories(thread PUBLIC ${LIB_DIR})

# Add the library directory to the test include path
target_include_directories(MainA PRIVATE ${LIB_DIR})

# Set the output directories for the library and test executable
set_target_properties(thread PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainA PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
