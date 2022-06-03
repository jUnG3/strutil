set(TARGET strutil-tests)

add_executable(${TARGET} ${CMAKE_CURRENT_SOURCE_DIR}/test_runner.c
        ${CMAKE_CURRENT_SOURCE_DIR}/strexplode_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/strexplode_test.c
        ${CMAKE_CURRENT_SOURCE_DIR}/trim_test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/trim_test.c)

target_include_directories(${TARGET} PUBLIC ${C_UNIT_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${TARGET} PUBLIC ${C_UNIT_LIBRARIES} strutil)

add_test(NAME ${TARGET} COMMAND ${TARGET})
