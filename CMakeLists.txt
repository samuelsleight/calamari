cmake_minimum_required(VERSION 3.3)
project(calamari)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/Modules)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

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
    include/calamari/colour.hpp
    include/calamari/renderable.hpp
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
    src/error.cpp)

add_library(calamari SHARED ${SOURCE_FILES})
add_executable(calamari_test EXCLUDE_FROM_ALL ${HEADER_FILES} main.cpp)
target_link_libraries(calamari_test calamari)

#Attempt to link libraries
find_package(PkgConfig)

if(PkgConfig_FOUND)
    pkg_search_module(GLFW glfw3)
endif()

if(NOT GLFW_FOUND)
    find_package(GLFW)
endif()

if(GLFW_FOUND)
    include_directories(SYSTEM ${GLFW_INCLUDE_DIR})
    target_link_libraries(calamari ${GLFW_LIBRARIES})
else()
    error("Unable to find GLFW, please set GLFW_LOCATION in your environment")
endif()
