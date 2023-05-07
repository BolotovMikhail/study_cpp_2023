project(homework2 VERSION ${PROJECT_VESRION})

find_package(GTest REQUIRED)

add_executable(ip_filter
               ip_filter.cpp)

add_executable(ip_filter_tests
               ip_filter_tests.cpp)

set_target_properties(ip_filter ip_filter_tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(ip_filter
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/helpers"
)
set_target_properties(ip_filter_tests PROPERTIES
    INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIRS}"
    INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/helpers"
)

target_link_libraries(ip_filter_tests
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
)

configure_file(test_data/ip_filter.tsv
    ${CMAKE_BINARY_DIR}/test_data/ip_filter.tsv COPYONLY)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(ip_filter_tests ip_filter_tests)
