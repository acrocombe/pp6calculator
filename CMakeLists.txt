# Main CMake script for pp6calculator
#
# Require latest generation of CMake
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Declare the project
project(pp6calculator)

# Use the standard flag set when using the GNU/Clang compiler
include(CheckCXXCompilerFlag)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNUIClang")
	# Check for C++11 support, activating it if available
	check_cxx_compiler_flag(-std=c++11 HAS_GNUSTYLE_CPP11)
	if(HAS_GNUSTYLE_CPP11)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
	endif()
	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors -Wall -Wextra - Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

# Tell compiler where to find headers
include_directories(PP6Lib)

# Add the PP6Lib library
add_subdirectory(PP6Lib)

# Add the pp6calculator program
add_executable(pp6calculator pp6calculator.cpp PP6Lib/PP6Math.cpp PP6Lib/PP6Math.hpp PP6Lib/PP6Menus.cpp PP6Lib/PP6Menus.hpp)

# Link pp6calculator to the pp6lib library
target_link_libraries(pp6calculator pp6lib)

# Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

# Package pp6calculator sources and executable
include(CPack)
