cmake_minimum_required(VERSION 3.16)

project(FunGameManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Qt6Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(SOURCES
    main.cpp
    mainwindow.cpp mainwindow.h mainwindow.ui
    programmingpage.cpp programmingpage.h programmingpage.ui
    gameartpage.cpp gameartpage.h gameartpage.ui
    backendpage.cpp backendpage.h backendpage.ui
    productmanagementpage.cpp productmanagementpage.h productmanagementpage.ui
    homepage.cpp homepage.h homepage.ui
    task.cpp task.h
    tasktype.h
    taskcategory.h
    goal.cpp goal.h
    goalpriority.h
    goalservice.cpp goalservice.h
    funresources.qrc
)

if(QT_VERSION_MAJOR GREATER_EQUAL 6)
    qt_add_executable(FunGameManager
        MANUAL_FINALIZATION
        ${SOURCES}
        taskservice.h taskservice.cpp
    )
else()
    add_executable(FunGameManager ${SOURCES})
endif()

target_link_libraries(FunGameManager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# macOS and Windows packaging options
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set_target_properties(FunGameManager PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.FunGameManager
    )
endif()

set_target_properties(FunGameManager PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS FunGameManager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FunGameManager)
endif()
