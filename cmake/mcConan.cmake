if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
file(
    DOWNLOAD
        "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake"
    EXPECTED_HASH
        SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484

    TLS_VERIFY
        ON
)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_add_remote(NAME conancenter URL https://center.conan.io)
conan_cmake_autodetect(settings)
conan_cmake_install(
    CONANFILE
        conanfile.txt
    PATH_OR_REFERENCE
        ${CMAKE_CURRENT_SOURCE_DIR}
    BUILD
        outdated
    REMOTE
        conancenter
    SETTINGS
        ${settings}
    SETTINGS
        compiler.cppstd=${CMAKE_CXX_STANDARD}
)