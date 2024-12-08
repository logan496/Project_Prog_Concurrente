# Définir la version minimale requise de CMake
cmake_minimum_required(VERSION 3.29)

# Nom du projet
project(Project_Prog_Concurrente)

# Spécifier le standard C++ utilisé
set(CMAKE_CXX_STANDARD 20)

# Définir le chemin vers Qt
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64")

# Rechercher les composants nécessaires de Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Ajouter la gestion des fichiers .ui (si vous en utilisez)
#qt6_wrap_ui(UI_HEADERS 
    #src/Views/MainWindow.ui
#)

# Ajouter les fichiers sources
add_executable(Project_Prog_Concurrente
    main.cpp

    # Fichiers .ui convertis
    ${UI_HEADERS}

    # --- Models ---
    src/Models/classDeclaration/ClientModel.h
    src/Models/classDefinition/ClientModel.cpp
    src/Models/classDeclaration/Order.h
    src/Models/classDefinition/Order.cpp
    src/Models/classDeclaration/Recipe.h
    src/Models/classDefinition/Recipe.cpp
    src/Models/classDeclaration/Human.h
    src/Models/classDefinition/Human.cpp
    src/Models/classDeclaration/UstensilModel.h
    src/Models/classDefinition/UstensilModel.cpp
    src/Models/classDeclaration/Table.h
    src/Models/classDefinition/Table.cpp
    src/Models/classDeclaration/DinningRoom.h
    src/Models/classDefinition/DinningRoom.cpp
    src/Models/classDeclaration/Butler.h
    src/Models/classDefinition/Butler.cpp
    src/Models/classDeclaration/ClientGroupCreator.h
    src/Models/classDefinition/ClientGroupCreator.cpp
    src/Models/classDeclaration/RestaurantDiver.h
    src/Models/classDefinition/RestaurantDiver.cpp
    src/Models/classDeclaration/Server.h
    src/Models/classDefinition/Server.cpp
    src/Models/classDeclaration/RoomClerk.h
    src/Models/classDefinition/RoomClerk.cpp
    src/Models/classDeclaration/CardModel.h
    src/Models/classDefinition/CardModel.cpp
    src/Models/classDeclaration/Chief.h
    src/Models/classDefinition/Chief.cpp
    src/Models/classDeclaration/Cook.h
    src/Models/classDefinition/Cook.cpp
    src/Models/classDeclaration/StorageModel.h
    src/Models/classDefinition/StorageModel.cpp
    src/Models/classDeclaration/headWaiter.h
    src/Models/classDefinition/HeadWaiter.cpp
    src/Models/classDeclaration/KitchenCounter.h
    src/Models/classDefinition/KitchenCounter.cpp
    src/Models/classDeclaration/KitchenAssistant.h
    src/Models/classDefinition/KitchenAssistant.cpp
    src/Models/classDeclaration/DishwasherModel.h
    src/Models/classDefinition/DishwasherModel.cpp
    src/Models/classDeclaration/MaterialModel.h
    src/Models/classDefinition/MaterialModel.cpp
    src/Models/classDeclaration/WashingMachine.h
    src/Models/classDefinition/WashingMachine.cpp
    src/Models/classDeclaration/DirtyDishesStorage.h
    src/Models/classDefinition/DirtyDishesStorage.cpp

    # --- Controllers ---
    src/Controllers/classDeclaration/MainController.h
    src/Controllers/classDefinition/MainController.cpp
    src/Controllers/classDeclaration/DBController.h
    src/Controllers/classDefinition/DBController.cpp
    src/Controllers/classDeclaration/MoveController.h
    src/Controllers/classDefinition/MoveController.cpp
    src/Controllers/classDeclaration/MotionlessElementController.h
    src/Controllers/classDefinition/MotionlessElementController.cpp

    # --- Views ---
    src/Views/MainWindow.h
    src/Views/MainWindow.cpp
)

# Lier les bibliothèques Qt nécessaires
target_link_libraries(Project_Prog_Concurrente
    Qt6::Widgets
)
