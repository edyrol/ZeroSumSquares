# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

project( main )

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Release)

if(UNIX) 
    message(STATUS ">>> Linux")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
elseif(WIN32)
    message(STATUS ">>> Not Linux")
    set(CMAKE_CXX_FLAGS_RELEASE "-Ox")
endif()

# # Boost and its components
# find_package( Boost REQUIRED )
# 
# if ( NOT Boost_FOUND )
# 
#   message(STATUS "This project requires the Boost library, and will not be compiled.")
# 
#   return()  
# 
# endif()

# include_directories( ${PROJECT_SOURCE_DIR}/include )

add_executable( main main.cpp )
