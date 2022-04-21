cmake_minimum_required(VERSION 3.8)
project(space_arena VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


add_subdirectory(dependencies/sdl)

# if(WIN32)
#     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
# endif(WIN32)


FILE(GLOB src_files 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/*.cpp"
)


set(lib_SDL2 "${CMAKE_CURRENT_SOURCE_DIR}/libs/sdl2")




include_directories(${lib_SDL2}/include)

link_directories(${lib_SDL2}/lib/x64)

add_executable(${PROJECT_NAME} ${src_files})

target_link_libraries( ${PROJECT_NAME} SDL2 SDL2main )

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -v)



include(CPack)
