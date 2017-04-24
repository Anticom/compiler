cmake_minimum_required(VERSION 3.2)
project(go)
set(TARGET_NAME ${PROJECT_NAME})

option(BUILD_SHARED_LIBS "Build shared instead of static libs?" ON)

add_subdirectory("${PROJECT_SOURCE_DIR}/../tpl" "tpl")

set(CXX_INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/include)

set(CXX_SOURCES
    # APPLICATION
    src/go.cxx
    )

configure_file(${PROJECT_SOURCE_DIR}/hello.go ${PROJECT_BINARY_DIR}/hello.go COPYONLY)

add_executable(${TARGET_NAME} ${CXX_SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC ${CXX_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} tpl)
set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED TRUE)
