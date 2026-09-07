cmake_minimum_required(VERSION 3.10)

project("alt-lib" CXX)

# Enable Hot Reload for MSVC compilers if supported
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Make sure CMake knows where to find your include folders
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add source files to this project's executable (include your headers here too so they show up nicely)
add_executable(alt-lib 
    src/main.cpp
    src/alt/array.h
)