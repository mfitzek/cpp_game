cmake_minimum_required(VERSION 3.8)
project(my_game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
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
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/projectiles/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/projectiles/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/map/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/map/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/collisions/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/collisions/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/utils/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/utils/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/ResourceManager/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/ResourceManager/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/enemies/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/enemies/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/main/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/main/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/score/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/score/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/card_scene/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/scenes/card_scene/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/cards/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/game/cards/*.cpp"
)



list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/sdl2)

set(SDL2_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/sdl2)
find_package(SDL2 REQUIRED)

set(SDL2_IMAGE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/sdl2_image)
find_package(SDL2_image REQUIRED)

set(SDL2_TTF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs/sdl2_ttf)
find_package(SDL2_ttf REQUIRED)

include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} ${src_files})

target_link_libraries( ${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} )

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic )

# set_source_files_properties( ${src_files} PROPERTIES COMPILE_FLAGS -Wall -Wextra -pedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic ) 


file(GLOB lib_files 
    "${CMAKE_SOURCE_DIR}/libs/sdl2/lib/x64/*.dll"
    "${CMAKE_SOURCE_DIR}/libs/sdl2/lib/x64/*.lib"
    "${CMAKE_SOURCE_DIR}/libs/sdl2_ttf/lib/x64/*.dll"
    "${CMAKE_SOURCE_DIR}/libs/sdl2_ttf/lib/x64/*.lib"
    "${CMAKE_SOURCE_DIR}/libs/sdl2_image/lib/x64/*.dll"
    "${CMAKE_SOURCE_DIR}/libs/sdl2_image/lib/x64/*.lib"
)


# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#      COMMAND ${CMAKE_COMMAND} -E copy_if_different
#          "${CMAKE_SOURCE_DIR}/libs/sdl2/lib/x64/SDL2.dll"
#          "${CMAKE_SOURCE_DIR}/libs/sdl2_ttf/lib/x64/SDL2_ttf.dll"
#          "${CMAKE_SOURCE_DIR}/libs/sdl2_image/lib/x64/*.dll"
#          "${CMAKE_SOURCE_DIR}/libs/sdl2_image/lib/x64/*.lib"
#          $<TARGET_FILE_DIR:${PROJECT_NAME}>)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${lib_files}
         $<TARGET_FILE_DIR:${PROJECT_NAME}>)



include(CPack)
