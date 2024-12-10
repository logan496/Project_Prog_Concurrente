cmake_minimum_required(VERSION 3.16) # Qt nécessite au moins CMake 3.16, mais vérifiez si 3.29 est nécessaire pour d'autres raisons.

project(Projet_Programmation_Syteme LANGUAGES CXX)

# Utiliser le standard C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the prefix path to the Qt installation
set(CMAKE_PREFIX_PATH "/home/wolverine/Qt/6.8.1")

# Activer les fonctionnalités automatiques de Qt
set(CMAKE_AUTOMOC ON) # Active la génération automatique de moc


# Trouver les composants nécessaires de Qt6
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# Ajouter l'exécutable
add_executable(Projet_Programmation_Syteme
        src/main.cpp
        #        src/Controllers/classDefinition/MainController.cpp
        #        src/Controllers/classDeclaration/MainController.h
        src/Models/DinningRoom/classDeclaration/ClientModel.h

        src/View/MainView.cpp
        src/View/MainView.h
        #        src/View/DinningRoom/ClassDeclaration/ServerView.h
        #        src/View/DinningRoom/ClassDefinition/ServerView.cpp
        #        src/Models/DinningRoom/classDeclaration/Server.h
        #        src/Models/DinningRoom/classDefinition/Server.cpp

        src/Observer/Observable.cpp
        src/View/commonClass/ClassDeclaration/MobileElementView.h
        src/View/commonClass/ClassDefinition/MobileElementView.cpp
        src/Models/CommonClass/classDeclaration/MobilityModel.h
        src/Models/CommonClass/classDefinition/MobilityModel.cpp
        src/Controllers/classDeclaration/MoveController.h
        src/Controllers/classDefinition/MoveController.cpp
        src/factories/DinningRoom/classDefinition/ClientGroupFactory.cpp
        src/factories/DinningRoom/classDeclaration/ClientGroupFactory.h
        src/threadPool/ThreadPool.cpp
        src/threadPool/ThreadPool.h
        #        src/tes.cpp
        src/manageConfig/readEnv/EnvReader.cpp
        src/manageConfig/readEnv/EnvReader.h
        #        src/manageConfig/readJson/JsonReader.cpp
        #        src/manageConfig/readJson/JsonReader.h
        src/Managers/classDefinition/clientGroupManager.cpp
        src/Managers/classDeclaration/clientGroupManager.h
        src/Models/DinningRoom/classDeclaration/ClientGroup.h
        src/factories/DinningRoom/classDeclaration/TableFactory.h
        src/factories/DinningRoom/classDefinition/TableFactory.cpp
#        src/View/commonClass/ClassDeclaration/MotionLessElementView.h
        src/Models/CommonClass/classDeclaration/MotionLessModel.h
        src/Managers/classDeclaration/TableCreateManager.h
        src/Managers/classDefinition/TableCreateManager.cpp


)

# Inclure les répertoires d'en-têtes
target_include_directories(Projet_Programmation_Syteme PRIVATE
        src/Models
        src/View
        src/Controllers
)

# Lier les bibliothèques Qt nécessaires
target_link_libraries(Projet_Programmation_Syteme PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        stdc++
)


