cmake_minimum_required(VERSION 3.24)
project("Graph_Coloring")

enable_language(CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}\\bin")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}\\lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}\\lib")

# Prevent building in the source directory
#
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n"
  )
endif()

# Generate compile_commands.json for clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("src")

#
# Static analyzers
#
# Currently supporting: Clang-Tidy, Cppcheck.
# option(${PROJECT_NAME}_ENABLE_CLANG_TIDY
#        "Enable static analysis with Clang-Tidy." ON)
# option(${PROJECT_NAME}_ENABLE_CPPCHECK "Enable static analysis with Cppcheck."
#        OFF)
# include(cmake/StaticAnalyzers.cmake)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(${PROJECT_NAME})
#
# Unit testing setup
#
enable_testing()
add_subdirectory("test")
