# Add ASIO include path manually
set(ASIO_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE PATH "")
message(STATUS "Asio include dir: ${ASIO_INCLUDE_DIR}")

# Register the target as "asio" so find_package(asio REQUIRED) works
add_library(asio INTERFACE)
add_library(asio::asio ALIAS asio)

target_include_directories(asio 
    INTERFACE
        ${ASIO_INCLUDE_DIR}
)

target_compile_definitions(asio 
    INTERFACE
        ASIO_STANDALONE
)

