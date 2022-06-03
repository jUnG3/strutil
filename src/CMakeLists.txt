set(LIB_NAME strutil)

add_library(${LIB_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/explode_free.c
        ${CMAKE_CURRENT_SOURCE_DIR}/strexplode.c
        ${CMAKE_CURRENT_SOURCE_DIR}/trim.c)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

install(TARGETS ${LIB_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
