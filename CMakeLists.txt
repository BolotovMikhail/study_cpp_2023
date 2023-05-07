cmake_minimum_required(VERSION 3.17)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(study_cpp_2023 VERSION ${PROJECT_VESRION})

#set(CMAKE_CXX_CLANG_TIDY clang-tidy -warnings-as-errors=*)

#add_subdirectory(homework_01)
add_subdirectory(homework_02)
