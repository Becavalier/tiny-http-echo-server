cmake_minimum_required(VERSION 3.21)
project(mini-http-server)

set(TARGET_FILE "main")
set(CMAKE_C_STANDARD 17)

# for headers in "/libs" and other external installed packages.
include_directories(. /usr/local/include)

# load source files and sub-directories.
aux_source_directory(./src DIR_SRCS)
add_subdirectory(libs/)

# load packages.
find_package(uriparser 0.9.6 CONFIG REQUIRED char)

# for executable.
add_executable(${TARGET_FILE} ${DIR_SRCS})
target_link_libraries(${TARGET_FILE} PUBLIC core m pthread uriparser::uriparser)
