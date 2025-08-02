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

###########
# PalLink #
###########

add_library(PalLink SHARED)

set_target_properties(PalLink PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>"
)

target_compile_definitions(PalLink PRIVATE
    "UNICODE"
    "_UNICODE"
    "NOMINMAX"
    "WIN32_LEAN_AND_MEAN"
    "PALLINK_BUILD_DLL"
)

file(GLOB_RECURSE PALLINK_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

file(GLOB_RECURSE PALLINK_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" FILES ${PALLINK_HEADERS} PREFIX "Public")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/source" FILES ${PALLINK_SOURCES} PREFIX "Private")

target_sources(PalLink
    PUBLIC
        "${PALLINK_HEADERS}"
    PRIVATE
        "${PALLINK_SOURCES}"
)

target_include_directories(PalLink
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/source"
)

target_link_libraries(PalLink
    PRIVATE
        spdlog::spdlog
)

set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT PalLink)