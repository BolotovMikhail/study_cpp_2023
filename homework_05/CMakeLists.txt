project(homework5 VERSION ${PROJECT_VESRION})

set(TARGET main)

add_executable(${TARGET}
               main.cpp
               "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/model/data/primitive/Primitive.cpp"
               "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/model/data/document/ActiveDocument.cpp"
               "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/model/EditorModel.cpp"
               "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/view/EditorView.cpp"
               "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/controller/EditorController.cpp"
               )

set_target_properties(${TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${TARGET} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/model"
    "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/model/data/common"
    "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/view"
    "${CMAKE_CURRENT_SOURCE_DIR}/graphics_editor/controller"
)

install(TARGETS ${TARGET} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
