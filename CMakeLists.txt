cmake_minimum_required(VERSION 3.29)

project("Team PalLink" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################
# Dependencies #
################

add_subdirectory(deps)
