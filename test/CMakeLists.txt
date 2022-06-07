set(TARGET strutil-tests)

add_executable(
        ${TARGET}
        ${CMAKE_CURRENT_SOURCE_DIR}/trim_test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/strexplode_test.cpp
)

target_include_directories(${TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${TARGET} PUBLIC gtest_main strutil)

include(GoogleTest)
gtest_discover_tests(${TARGET})
