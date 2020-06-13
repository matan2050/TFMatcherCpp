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
	src/Vector2.cpp )
	
# unit test project
ADD_EXECUTABLE( UnitTest
	test/UnitTestEntry.cpp
	test/Vector2.cpp )
	
TARGET_LINK_LIBRARIES (UnitTest TFMatcher)