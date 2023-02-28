cmake_minimum_required(VERSION 3.13.4)

project(embedlog)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

file(GLOB files src/*.c src/*.h include/*.h)

add_library(${PROJECT_NAME} STATIC ${files})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_definitions(${PROJECT_NAME} PUBLIC HAVE_CONFIG_H=1)
add_definitions(-DHAVE_CONFIG_H)
add_definitions(-DENABLE_PTHREAD)
#message("--- [embedlog] PROJECT NAME: " ${PROJECT_NAME})
#target_link_libraries(${PROJECT_NAME} PUBLIC posix_subsys FS)

# target_compile_options( ${PROJECT_NAME} PRIVATE
# $<$<CXX_COMPILER_ID:Clang>:${BUILD_FLAGS_FO_CLANRG}>
# $<$<CXX_COMPILER_ID:GNU>:${BUILD_FLAGS_FOR_GCC}>
# $<$<CXX_COMPILER_ID:MSVC>:${BUILD_FLAGS_FOR_VISUAL}>)
# target_compile_options(${PROJECT_NAME} PUBLIC
# "$<$<CONFIG:DEBUG>:${CUSTOM_CMAKE_C_FLAGS}>")
# target_compile_options(${PROJECT_NAME} PUBLIC
# "$<$<CONFIG:RELEASE>:${CUSTOM_CMAKE_C_FLAGS}>")
# set_source_files_properties(${files} PROPERTIES COMPILE_FLAGS
# ${CUSTOM_CMAKE_C_FLAGS})
