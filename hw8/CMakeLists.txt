cmake_minimum_required(VERSION 3.10)  
project(HuffmanProject)                

set(CMAKE_CXX_STANDARD 11)            
set(CMAKE_CXX_STANDARD_REQUIRED ON)   

add_executable(main main.cpp)


# To enable using the `make clean-custom` command to clean up custom files.
# you can add the following custom clean rules.
# cmake script does NOT generate intermediate object such as object file(.o or .obj).
if(NOT TARGET clean)
    add_custom_target(clean-custom
        COMMAND ${CMAKE_COMMAND} -E echo "cleaning custom file..."
        COMMAND ${CMAKE_COMMAND} -E rm -f "${CMAKE_BINARY_DIR}/*.elf"
        COMMAND ${CMAKE_COMMAND} -E rm -f "main"
        COMMAND ${CMAKE_COMMAND} -E rm -f "../output/*.compress"
        COMMAND ${CMAKE_COMMAND} -E rm -f "../output/*.txt"
        COMMAND ${CMAKE_COMMAND} -E rm -f "../output/*.jpg"
        COMMAND ${CMAKE_COMMAND} -E rm -f "../output/*.mp3"
    )
endif()
