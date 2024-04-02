cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME CGIP_HW1)
set(CMAKE_CXX_STANDARD 17)

set(WINDOW_NAME "CGIP_HW1")
set(WINDOW_WIDTH 512)
set(WINDOW_HEIGHT 512)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)

include(Dependency.cmake)

target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

target_compile_definitions(${PROJECT_NAME} PUBLIC
    WINDOW_NAME="${WINDOW_NAME}"
    WINDOW_WIDTH=${WINDOW_WIDTH}
    WINDOW_HEIGHT=${WINDOW_HEIGHT}
)

add_dependencies(${PROJECT_NAME} ${DEP_LIST})