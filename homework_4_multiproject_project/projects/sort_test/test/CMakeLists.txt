set(SOURCES 
    sort_test.cpp
)

add_executable(sort_test ${SOURCES})
target_link_libraries(sort_test
    gtest_main
    gmock_main
    ${LIBRARY}
)

add_test(sort_test sort_test)