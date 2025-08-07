enable_language(ASM_MASM)

function(add_dll_wrapper_library MODULE_NAME)
    set(TARGET_NAME "${MODULE_NAME}")

    add_library(${TARGET_NAME} SHARED)
    add_dependencies(${TARGET_NAME} spdlog)

    set_target_properties(${TARGET_NAME} 
        PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>/wrapper"
    )

    target_compile_definitions(${TARGET_NAME} PRIVATE
        NOMINMAX
        WIN32_LEAN_AND_MEAN
        _WIN32_WINNT=0x0A00
        DLL=${TARGET_NAME}
        DLL_NAME=\"${TARGET_NAME}\"
    )

    file(GLOB WRAPPER_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}/${MODULE_NAME}_asm.asm"
        "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}/${MODULE_NAME}.def"
        "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}/${MODULE_NAME}.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/DllMain.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/DllMain.cpp"
    )

    target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE_NAME}")
    target_sources(${TARGET_NAME} PRIVATE ${WRAPPER_SOURCES})

    source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${WRAPPER_SOURCES} PREFIX "Code")

    set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "DLL Wrappers")
    
    target_link_options(${TARGET_NAME} PRIVATE /ignore:4104)

    target_link_libraries(${TARGET_NAME} 
        PRIVATE
            spdlog::spdlog
    )
endfunction()

add_dll_wrapper_library("d3d9")
add_dll_wrapper_library("dsound")
add_dll_wrapper_library("dwmapi")
add_dll_wrapper_library("gdi32")
add_dll_wrapper_library("psapi")
add_dll_wrapper_library("version")
add_dll_wrapper_library("xinput1_3")

if(NOT "${USED_DLL_WRAPPER}" STREQUAL "")
    set_target_properties(${USED_DLL_WRAPPER} 
        PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/$<CONFIG>"
    )
    message(STATUS "Target Dll Wrapper: ${USED_DLL_WRAPPER}")
endif()
