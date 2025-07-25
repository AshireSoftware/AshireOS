cmake_minimum_required(VERSION 3.16)

project(ashire_start_menu VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.4)

qt_add_executable(appashire_start_menu
    main.cpp
)

qt_add_qml_module(appashire_start_menu
    URI ashire_start_menu
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES
        RESOURCES Resources.qrc
        SOURCES startmenu.h startmenu.cpp
)

qt_add_resources(appashire_start_menu "icons"
    PREFIX="/"
    FILES Images/pfp.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appashire_start_menu PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appashire_start_menu
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appashire_start_menu
    PRIVATE Qt6::Quick
)
target_link_libraries(appashire_start_menu PRIVATE Qt6::Core)
target_link_libraries(appashire_start_menu PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS appashire_start_menu
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
