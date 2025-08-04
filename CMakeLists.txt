cmake_minimum_required(VERSION 3.16)

project("Team PalLink" LANGUAGES CXX)

# C++ Standard and general build settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################
# Dependencies #
################
add_subdirectory(deps)

###########
# PalLink #
###########
add_library(PalLink SHARED)


# Output configuration
if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo" CACHE STRING "Available build configurations" FORCE)

    set(config_dir "$<CONFIG>")
else()
    set(config_dir "${CMAKE_BUILD_TYPE}")
endif()

set(output_dir "${PROJECT_SOURCE_DIR}/bin/${config_dir}")
set_target_properties(PalLink PROPERTIES
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${output_dir}"
    RUNTIME_OUTPUT_DIRECTORY "${output_dir}"
)


# Preprocessor definitions
target_compile_definitions(PalLink PRIVATE PALLINK_BUILD_DLL)

if (WIN32)
    target_compile_definitions(PalLink PRIVATE
        "UNICODE"
        "_UNICODE"
        "NOMINMAX"
        "WIN32_LEAN_AND_MEAN"
    )
endif()


# Source and header file collection
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


# Organize in Visual Studio solution folders
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" FILES ${PALLINK_HEADERS} PREFIX "Public")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/source" FILES ${PALLINK_SOURCES} PREFIX "Private")


# Source setup
target_sources(PalLink
    PUBLIC
        "${PALLINK_HEADERS}"
    PRIVATE
        "${PALLINK_SOURCES}"
)


# Include setup
target_include_directories(PalLink
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/source"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/PolyHook_2_0/include"
)


# Link libraries
target_link_libraries(PalLink
    PRIVATE
        spdlog::spdlog
        PolyHook_2
)


# Set startup project in Visual Studio
set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT PalLink)
