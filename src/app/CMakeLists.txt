add_executable(${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/qrc/app_win32.rc
  main.cpp
  widget.cpp
  widget.ui
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        mysql
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
