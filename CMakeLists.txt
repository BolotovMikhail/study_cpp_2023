cmake_minimum_required(VERSION 3.17)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(study_cpp_2023 VERSION ${PROJECT_VESRION})

#add_subdirectory(homework_01)
#add_subdirectory(homework_02)
#add_subdirectory(homework_03)
add_subdirectory(homework_04)
