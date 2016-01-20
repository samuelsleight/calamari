cmake_minimum_required(VERSION 3.3)
project(calamari)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(SYSTEM ${GLFW_INCLUDE_DIRS})
include_directories(BEFORE ./include)

set(HEADER_FILES
        include/calamari/gl/gl_core_3_3.hpp
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
        include/calamari/colour.hpp)

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
        include/calamari/colour.cpp)

add_library(calamari SHARED ${SOURCE_FILES})
target_link_libraries(calamari ${GLFW_LIBRARIES})

add_executable(calamari_test EXCLUDE_FROM_ALL ${HEADER_FILES} main.cpp)
target_link_libraries(calamari_test calamari)
