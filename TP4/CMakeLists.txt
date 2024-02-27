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

add_library(threadMutex
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/PosixThread.h
    ${LIB_DIR}/PosixThread.cpp
    ${LIB_DIR}/Thread.h
    ${LIB_DIR}/Thread.cpp
    ${LIB_DIR}/Mutex.h
    ${LIB_DIR}/Mutex.cpp
    ${LIB_DIR}/Monitor.h
    ${LIB_DIR}/Monitor.cpp
    ${LIB_DIR}/Lock.h
    ${LIB_DIR}/Lock.cpp
    ${LIB_DIR}/TryLock.h
    ${LIB_DIR}/TryLock.cpp
    ${LIB_DIR}/IncrThreadMutex.h
    ${LIB_DIR}/IncrThreadMutex.cpp
)

add_library(semaphore
    ${LIB_DIR}/Timespec.h
    ${LIB_DIR}/Timespec.cpp
    ${LIB_DIR}/PosixThread.h
    ${LIB_DIR}/PosixThread.cpp
    ${LIB_DIR}/Thread.h
    ${LIB_DIR}/Thread.cpp
    ${LIB_DIR}/Mutex.h
    ${LIB_DIR}/Mutex.cpp
    ${LIB_DIR}/Monitor.h
    ${LIB_DIR}/Monitor.cpp
    ${LIB_DIR}/Lock.h
    ${LIB_DIR}/Lock.cpp
    ${LIB_DIR}/Semaphore.h
    ${LIB_DIR}/Semaphore.cpp
    ${LIB_DIR}/ProducerThread.h
    ${LIB_DIR}/ProducerThread.cpp
    ${LIB_DIR}/ConsumerThread.h
    ${LIB_DIR}/ConsumerThread.cpp
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
target_link_libraries(MainA PRIVATE thread)
target_link_libraries(MainB PRIVATE threadMutex)
target_link_libraries(MainC PRIVATE semaphore)

# Add the library directory to the include path
target_include_directories(thread PUBLIC ${LIB_DIR})
target_include_directories(threadMutex PUBLIC ${LIB_DIR})
target_include_directories(semaphore PUBLIC ${LIB_DIR})

# Add the library directory to the test include path
target_include_directories(MainA PRIVATE ${LIB_DIR})
target_include_directories(MainB PRIVATE ${LIB_DIR})
target_include_directories(MainC PRIVATE ${LIB_DIR})

# Set the output directories for the library and test executable
set_target_properties(thread PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainA PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set_target_properties(threadMutex PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainB PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set_target_properties(semaphore PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(MainC PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
