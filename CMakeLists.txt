cmake_minimum_required(VERSION 3.16) # Qt nécessite au moins CMake 3.16, mais vérifiez si 3.29 est nécessaire pour d'autres raisons.

project(Projet_Programmation_Syteme LANGUAGES CXX)

# Utiliser le standard C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the prefix path to the Qt installation
set(CMAKE_PREFIX_PATH "/home/wolverine/Qt/6.8.1")

# Activer les fonctionnalités automatiques de Qt
set(CMAKE_AUTOMOC ON) # Active la génération automatique de moc
set(CMAKE_AUTOUIC ON) # (Optionnel) Active la gestion des fichiers UI
set(CMAKE_AUTORCC ON) # (Optionnel) Active la gestion des fichiers QRC

# Trouver les composants nécessaires de Qt6
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# Ajouter l'exécutable
add_executable(Projet_Programmation_Syteme
        main.cpp
#        src/Controllers/classDefinition/MainController.cpp
#        src/Controllers/classDeclaration/MainController.h
#        src/Controllers/classDefinition/MoveController.cpp
#        src/Models/DinningRoom/classDeclaration/ClientGroupCreator.h
#        src/Models/DinningRoom/classDefinition/ClientGroupCreator.cpp
#        src/Models/DinningRoom/classDeclaration/ClientModel.h
#        src/Models/CommonClass/classDeclaration/Order.h
        src/View/MainView.cpp
        src/View/MainView.h
#        src/View/DinningRoom/ClassDeclaration/ServerView.h
#        src/View/DinningRoom/ClassDefinition/ServerView.cpp
#        src/Models/DinningRoom/classDeclaration/Server.h
#        src/Models/DinningRoom/classDefinition/Server.cpp
        src/Observer/Observable.cpp
        src/View/DinningRoom/ClassDeclaration/MobileElementView.h
        src/View/DinningRoom/ClassDefinition/MobileElementView.cpp
        src/Models/CommonClass/classDeclaration/MobilityModel.h
        src/Models/CommonClass/classDefinition/MobilityModel.cpp
        src/Controllers/classDeclaration/MoveController.h
        src/Controllers/classDefinition/MoveController.cpp


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
)
