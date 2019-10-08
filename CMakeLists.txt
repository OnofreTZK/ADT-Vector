cmake_minimum_required(VERSION 3.5)
project( ADT-Vector VERSION 0.1 LANGUAGES CXX)


#=== FIND PACKAGES===#

# Locate Gtest package (library)
find_package(gtest REQUIRED)
# include gtest's include folder in the project
include_directories (${GTEST_INCLUDE_DIRS})

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )
#CMAKE_CXX_FLAGS = "-Wall";

# set the include path

# -------------------------------
# This is for old cmake versions
# set (CMAKE_CXX_STANDARD 11)
# -------------------------------

#set include path
include_directories ( include )

# define the sources for the project

add_executable ( vector_driver
				 src/vector.cpp ) #this is the application and has the main

# define C++11 standard
set_property (TARGET vector_driver PROPERTY CXX_STANDARD 11)

add_executable( selantests
                src/main.cpp )

# Link with the google test libraries
target_link_libraries( selantests PRIVATE ${GTEST_LIBRARIES} )

# define C++11 standard
set_property (TARGET selantests PROPERTY CXX_STANDARD 11)

# the end
