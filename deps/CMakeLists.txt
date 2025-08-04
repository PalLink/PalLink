##########
# spdlog #
##########
set(SPDLOG_ENABLE_PCH ON CACHE BOOL "" FORCE)
set(SPDLOG_COMPILED_LIB ON CACHE BOOL "" FORCE)
add_subdirectory(spdlog-1.15.3)
set_target_properties(spdlog PROPERTIES FOLDER "Dependencies")

################
# PolyHook 2.0 #
################
set(POLYHOOK_BUILD_STATIC_RUNTIME OFF CACHE BOOL "" FORCE)
set(POLYHOOK_BUILD_SHARED_LIB OFF CACHE BOOL "" FORCE)
add_subdirectory(PolyHook_2_0)
set_target_properties(PolyHook_2 PROPERTIES FOLDER "Dependencies")

###############
# DllWrappers #
###############
if (WIN32)
    add_subdirectory(DllWrappers)
endif()
