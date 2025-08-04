##########
# spdlog #
##########
set(SPDLOG_ENABLE_PCH ON CACHE BOOL "" FORCE)
set(SPDLOG_COMPILED_LIB ON CACHE BOOL "" FORCE)
add_subdirectory(spdlog-1.15.3)
set_target_properties(spdlog PROPERTIES FOLDER "Dependencies")


###############
# DllWrappers #
###############
if (WIN32)
    add_subdirectory(DllWrappers)
endif()
