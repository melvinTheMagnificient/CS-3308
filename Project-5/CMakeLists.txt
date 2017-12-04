#Melissa Coblentz
#Project 5

cmake_minimum_required (VERSION 2.6)
project (DYNAMICARRAY)

#------------------------------------------------------------
# Use C++ 2011
#------------------------------------------------------------
if(WIN32)
  message(STATUS "Please verify you are using a compiler with C++11 support.")
else()
  include(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
  CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
  if(COMPILER_SUPPORTS_CXX11)
  	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  elseif(COMPILER_SUPPORTS_CXX0X)
  	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  else()
          message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
  endif()
endif()

#------------------------------------------------------------
# Source files
#------------------------------------------------------------
SET(SRCS
  ./main.cpp
	./Student.cpp
	./Button.cpp
		./RadioButton.cpp
)

ADD_EXECUTABLE(dynarray ${SRCS})

