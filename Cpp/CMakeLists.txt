cmake_minimum_required(VERSION 3.8)
project(CppProject)

set(CMAKE_PROJECT_VERSION_MAJOR "1")
set(CMAKE_PROJECT_VERSION_MINOR "0")
set(CMAKE_PROJECT_VERSION_PATCH "0")
set(CMAKE_PROJECT_VERSION ${CPP_MAJOR}.${CPP_MINOR}.${CPP_PATCH})

set(EXECUTABLE game)

set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_BINARY_DIR}/../src)
set(src ${CMAKE_CURRENT_SOURCE_DIR})
set(lib ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(dir ${CMAKE_BINARY_DIR}/bin)
set(lib_cmake ${CMAKE_BINARY_DIR}/../cmake)

set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_DIRECTORY ${dir})

set(CMAKE_PROJECT_ROOT ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_PATH ${dir})
set(CMAKE_ARCHIVE_OUTPUT_PATH ${dir})
set(CMAKE_RUNTIME_OUTPUT_PATH ${dir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${dir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_CACHEFILE_DIR ${dir})
set(CMAKE_BINARY_DIR ${dir})
set(CMAKE_CURRENT_BINARY_DIR ${dir})

set(PROJECT_BINARY_DIR ${dir})

# set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb3 -std=c++14") # -Wall -Wextra -Werror
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OS and compiler checks.
if(UNIX)
    # linux / normal unix
    add_definitions(-D_LINUX)
    if(CYGWIN)
        # Special Cygwin stuff here
    elseif(APPLE)
        # Special Apple stuff here
        remove_definitions(-D_LINUX)
        add_definitions(-D_DARWIN)
    endif()
elseif(WIN32)
    add_definitions(-DWIN32)
    if(MINGW)
        # Special MINGW stuff here
    elseif(MSVC)
        # Special MSVC stuff here
        add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)
    else()
        # No idea what it is, but there's a good chance it's too weird.
        MESSAGE( FATAL_ERROR "Using unknown WIN32 compiler... NOT. Please add to build system." )
    endif()
endif()

option(BUILD_CLI "Build CLI" ON)
option(BUILD_WEB "Build WEB" OFF)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}:${dir})

# include_directories(${lib}/{$libname}/include)
# set(LINK_LIBS pthread)

if (BUILD_WEB)
    # add_subdirectory(${src}/web)
    # list(APPEND LINK_LIBS web)
endif(BUILD_WEB)
unset(BUILD_WEB CACHE)

if (BUILD_CLI)
    file(GLOB_RECURSE SRC_CLI . ${src}/game/*.cpp)
    add_executable(${EXECUTABLE} ${src}/main.cpp ${SRC_CLI})
    # add_dependencies(${EXECUTABLE} ${DEPS})
    set_target_properties(${EXECUTABLE} PROPERTIES VERSION ${CMAKE_PROJECT_VERSION} SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR})
    target_link_libraries(${EXECUTABLE} PRIVATE ${LINK_LIBS})
    target_include_directories(${EXECUTABLE} PUBLIC
        ${src}/
        ${src}/include
    )
    if (WIN32)
        set_property(DIRECTORY ${CMAKE_PROJECT_ROOT} PROPERTY VS_STARTUP_PROJECT ${EXECUTABLE})
    endif()
    if (CMAKE_VERSION VERSION_GREATER 3.12)
        set_property(TARGET ${EXECUTABLE} PROPERTY CXX_STANDARD 20)
    endif()
endif()
