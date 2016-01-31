cmake_minimum_required(VERSION 3.3)
project(calamari)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS 0)

include_directories(BEFORE ./include)

set(HEADER_FILES
    include/calamari/gl/gl_core_3_3.hpp
    include/calamari/gl/gl.hpp
    include/calamari/application.hpp
    include/calamari/defines.hpp
    include/calamari/window.hpp
    include/calamari/renderer.hpp
    include/calamari/state.hpp
    include/calamari/object.hpp
    include/calamari/objectbase.hpp
    include/calamari/components.hpp
    include/calamari/camera.hpp
    include/calamari/eventmanager.hpp
    include/calamari/eventcallbacks.hpp
    include/calamari/colour.hpp
    include/calamari/renderable.hpp
    include/calamari/vector.hpp
    include/calamari/matrix.hpp
    include/calamari/transformation.hpp
    include/calamari/transformable.hpp
    include/calamari/key.hpp
    include/calamari/error.hpp)

set(SOURCE_FILES ${HEADER_FILES}
    src/gl/gl_core_3_3.cpp
    src/application.cpp
    src/window.cpp
    src/renderer.cpp
    src/components.cpp
    src/camera.cpp
    src/state.cpp
    src/eventmanager.cpp
    src/eventcallbacks.cpp
    src/colour.cpp
    src/renderable.cpp
    src/transformation.cpp
    src/transformable.cpp
    src/key.cpp
    src/error.cpp)

add_library(calamari SHARED ${SOURCE_FILES})
add_executable(calamari_test EXCLUDE_FROM_ALL ${HEADER_FILES} main.cpp)
target_link_libraries(calamari_test calamari)

# GLFW
find_package(GLFW)
include_directories(SYSTEM ${GLFW_INCLUDE_DIR})
target_link_libraries(calamari ${GLFW_LIBRARIES})
