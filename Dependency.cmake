include(ExternalProject)

set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)

#glfw
ExternalProject_Add(
    dep-glfw
    GIT_REPOSITORY "https://github.com/glfw/glfw.git"
    GIT_TAG "3.3.2"
    GIT_SHALLOW TRUE
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    TEST_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DGLFW_BUILD_DOCS=OFF
        -DGLFW_BUILD_EXAMPLES=OFF
        -DGLFW_BUILD_TESTS=OFF
)

set(DEP_LIST ${DEP_LIST} dep-glfw)
set(DEP_LIBS ${DEP_LIBS} glfw3)

#glad
ExternalProject_Add(
    dep-glad
    GIT_REPOSITORY "https://github.com/Dav1dde/glad.git"
    GIT_TAG "v0.1.34"
    GIT_SHALLOW TRUE
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    TEST_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DGLAD_INSTALL=ON
)

set(DEP_LIST ${DEP_LIST} dep-glad)
set(DEP_LIBS ${DEP_LIBS} glad)

# glm
ExternalProject_Add(
    def-glm
    GIT_REPOSITORY "https://github.com/g-truc/glm.git"
    GIT_SHALLOW TRUE
    UPDATE_COMMAND ""
    PATCH_COMMAND ""
    TEST_COMMAND ""
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
        -DGLM_BUILD_SHARED_LIBS=OFF
        -DGLM_BUILD_STATIC_LIBS=OFF
)

set(DEP_LIST ${DEP_LIST} def-glm)
set(DEP_LIBS ${DEP_LIBS} glm)