cmake_minimum_required(VERSION 3.10)

project(SweetPotato)


INCLUDE_DIRECTORIES(OS/include)
INCLUDE_DIRECTORIES(MEDIA/include)
#if($(var) STREQUAL "ON")

#else()
#SET(CMAKE_CXX_STANDARD 11)
#SET(CMAKE_C_COMPILER c++)
#endif()

#include_directories(PROC_ALARM/include)
#include_directories(PROC_IOT/include)
#ADD_SUBDIRECTORY(SP_ClientTest)
ADD_SUBDIRECTORY(OS)
ADD_SUBDIRECTORY(MEDIA)
ADD_SUBDIRECTORY(SP_Tools)




#ADD_SUBDIRECTORY(PROC_AAWANT)


