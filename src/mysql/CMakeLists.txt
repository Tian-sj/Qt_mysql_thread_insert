add_library (mysql STATIC
    personservice.h personservice.cpp
    personmapper.h personmapper.cpp)

target_link_libraries(mysql PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
)

target_include_directories(mysql INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
