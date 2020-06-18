#------------------------------------------------------------------------------------#
# CMake settings
#------------------------------------------------------------------------------------#
cmake_minimum_required(VERSION 3.17)

project("TFMatcher" CXX)

# TFMatcher library
ADD_LIBRARY( TFMatcher STATIC 
	src/AlignedTF.cpp 
	src/Matcher.cpp 
	src/Polygon.cpp 
	src/StringUtils.cpp 
	src/TurningFunction.cpp 
	src/Vector2.cpp
	include/AlignedTF.h
	include/Matcher.h
	include/Polygon.h
	include/StringUtils.h
	include/TurningFunction.h
	include/Vector2.h )
	
# unit test project
ADD_EXECUTABLE( UnitTest
	test/UnitTestEntry.cpp
	test/Vector2.cpp
    test/Polygon.cpp )
	
TARGET_LINK_LIBRARIES (UnitTest TFMatcher)