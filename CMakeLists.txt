cmake_minimum_required(VERSION 3.8)
project(space_arena)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
endif(UNIX)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


# add_subdirectory(dependencies/sdl)

# if(WIN32)
#     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
# endif(WIN32)


FILE(GLOB src_files 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/projectiles/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/map/*.cpp"
)



list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/sdl2)

set(SDL2_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/sdl2)
find_package(SDL2 REQUIRED)

set(SDL2_IMAGE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/sdl2_image)
find_package(SDL2_image REQUIRED)

include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} ${src_files})

target_link_libraries( ${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} )

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)


add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E copy_if_different
         "${CMAKE_SOURCE_DIR}/libs/sdl2/lib/x64/SDL2.dll"
         $<TARGET_FILE_DIR:${PROJECT_NAME}>)



include(CPack)
