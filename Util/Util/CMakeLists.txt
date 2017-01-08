#****************************This is Project Info****************************
PROJECT(Util)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#****************************This is Compile Flag****************************
if(DEBUG)
    message( STATUS "==============================debug==============================" )
    ADD_DEFINITIONS(-g)
else(DEBUG)
	message( STATUS "==============================release============================" )
    ADD_DEFINITIONS(-O2)
endif()

ADD_DEFINITIONS(-Wno-sign-compare -Wno-enum-compare)
ADD_DEFINITIONS("-std=c++11")


#****************************This is Include File/Directories****************
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/)

#****************************This is Source File/Directories*****************
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#****************************This is 3Party Library   Directories**************************
LINK_DIRECTORIES(./)

#****************************This is 3Party Library **************************


#****************************This is Output Directory************************
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/)

#****************************This is Output Library**************************

ADD_LIBRARY(${PROJECT_NAME} SHARED ${DIR_SRCS} )











