cmake_minimum_required(VERSION 3.10)

# set the project name
project(SimpleCli C CXX ASM)

# set C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# set HEADER_FILES var
set(HEADER_FILES cmdline.h)

# add the executable
add_executable( ${PROJECT_NAME}
    main.cpp
    ${HEADER_FILES}
)


