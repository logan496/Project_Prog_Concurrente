cmake_minimum_required(VERSION 3.19)
project(concurrence LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

# Ajout des ressources (resources.qrc)
qt_add_resources(RESOURCE_FILES resources.qrc)

qt_add_executable(concurrence
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    table.cpp
    table.h
    chef.cpp
    chef.h
    MaitreHotel.cpp
    MaitreHotel.h
    Serveur.cpp
    Serveur.h
    Client.cpp
    Client.h
    Plongeur.h
    Plongeur.cpp


)

target_link_libraries(concurrence
    PRIVATE
        Qt::Core
        Qt::Widgets
)

# Associer les ressources au projet
target_sources(concurrence PRIVATE ${RESOURCE_FILES})

include(GNUInstallDirs)

install(TARGETS concurrence
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET concurrence
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
