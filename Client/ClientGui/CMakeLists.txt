cmake_minimum_required(VERSION 3.5)

project(ClientGui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the option to use static Qt libraries
set(QT_STATIC_LINK ON CACHE BOOL "Link Qt statically" FORCE)

# Find Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Set compiler and linker flags for static linking
if(QT_STATIC_LINK)
    if(WIN32)
        set(CMAKE_FIND_LIBRARY_SUFFIXES .lib ${CMAKE_FIND_LIBRARY_SUFFIXES})
        set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
    elseif(UNIX)
        set(CMAKE_FIND_LIBRARY_SUFFIXES .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
        set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
        set(QT_STATIC_LINK ON CACHE BOOL "Link Qt statically" FORCE)
    endif()
endif()

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ClientGui
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        sign_up.h sign_up.cpp sign_up.ui
        signin.h signin.cpp signin.ui
        validator.h validator.cpp
        wallet.h wallet.cpp wallet.ui
        stringhasher.h stringhasher.cpp
        client.h client.cpp
    )
else()
    if(ANDROID)
        add_library(ClientGui SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(ClientGui
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ClientGui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX that is fine
BUNDLE_GUI_IDENTIFIER com.example.ClientGui)
endif()
set_target_properties(ClientGui PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ClientGui
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ClientGui)
endif()
