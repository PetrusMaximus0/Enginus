cmake_minimum_required(VERSION 3.31.1)
project(Engine VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# Add the External libraries
add_subdirectory(External/SDL3 EXCLUDE_FROM_ALL)

# Add folders and files to solution.
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Source/*)
file(GLOB_RECURSE INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/Include/*)
file(GLOB_RECURSE CONFIGS ${CMAKE_CURRENT_SOURCE_DIR}/Config/*)

add_library(${PROJECT_NAME} ${SOURCES} ${INCLUDES} ${CONFIGS})

#
target_include_directories(${PROJECT_NAME}
PUBLIC 
    $<INSTALL_INTERFACE:Include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>

PRIVATE
)

target_link_libraries(${PROJECT_NAME}
 PUBLIC

 PRIVATE    
    SDL3::SDL3
)

## Post Build Commands
add_custom_command(TARGET Engine POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:MyApp>/Engine/Config"
 COMMAND ${CMAKE_COMMAND} -E copy_directory
 "${CMAKE_CURRENT_SOURCE_DIR}/Config"
 "$<TARGET_FILE_DIR:MyApp>/Engine/Config"
)
