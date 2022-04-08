cmake_minimum_required(VERSION 3.8)
project(space_arena VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


add_subdirectory(dependencies/sdl)

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
endif(WIN32)


add_executable(space_arena ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )



target_include_directories(space_arena PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/sdl/include)

target_link_libraries(
    space_arena PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    )




include(CPack)
