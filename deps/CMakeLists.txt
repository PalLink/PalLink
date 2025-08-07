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
set_target_properties(asmjit PROPERTIES FOLDER "Dependencies")
set_target_properties(asmtk PROPERTIES FOLDER "Dependencies")
set_target_properties(Zycore PROPERTIES FOLDER "Dependencies")
set_target_properties(Zydis PROPERTIES FOLDER "Dependencies")
set_target_properties(PolyHook_2 PROPERTIES FOLDER "Dependencies")

###############
# DllWrappers #
###############
if (WIN32)
    add_subdirectory(DllWrappers)
endif()


#############
# RapidJSON #
#############
set(RAPIDJSON_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_CXX11 OFF CACHE BOOL "" FORCE)
set(RAPIDJSON_BUILD_CXX20 ON CACHE BOOL "" FORCE)
set(RAPIDJSON_HAS_STDSTRING ON CACHE BOOL "" FORCE)
add_subdirectory(rapidjson-1.1.0)


########
# asio #
########
add_subdirectory(asio-1.30.2)


###########
# CrowCpp #
###########
set(CROW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(Crow-1.2.1.2)
set_target_properties(uninstall PROPERTIES FOLDER "Dependencies")
