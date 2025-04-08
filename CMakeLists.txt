cmake_minimum_required(VERSION 3.15)
project(AnalysisToolkit LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Includes
include_directories(${CMAKE_SOURCE_DIR}/include)

# Gather source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cc
)

# Define executable
add_executable(AnalysisToolkit ${SOURCES})

# ROOT dependencies
find_package(ROOT REQUIRED COMPONENTS Core Hist RIO Graf Gpad)

# Link against ROOT
target_link_libraries(AnalysisToolkit PRIVATE ROOT::Core ROOT::Hist ROOT::RIO ROOT::Graf ROOT::Gpad)
