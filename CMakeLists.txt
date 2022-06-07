cmake_minimum_required(VERSION 3.16)

project(strutil VERSION 0.3.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_TESTS "OFF")

include(GNUInstallDirs)
include(CPack)

add_subdirectory(src)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/strutil.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (ENABLE_TESTS)
    # GoogleTest requires at least C++11
    set(CMAKE_CXX_STANDARD 11)

    include(FetchContent)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    add_subdirectory(test)
endif (ENABLE_TESTS)
