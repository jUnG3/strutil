cmake_minimum_required(VERSION 3.16)

project(strutil VERSION 0.2.0 LANGUAGES C)
option(ENABLE_TESTS "OFF")
include(GNUInstallDirs)
include(CPack)

add_subdirectory(src)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/strutil.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if (ENABLE_TESTS)
    find_package(PkgConfig)
    pkg_check_modules(C_UNIT REQUIRED cunit)
    enable_testing()
    add_subdirectory(test)
endif (ENABLE_TESTS)
