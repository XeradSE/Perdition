cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(Perdition)

# Standard C++
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

# Création de l'exécutable
add_executable(Perdition 
                ./src/main.cpp
                ./src/Enemy.cpp
                ./src/Entity.cpp
                ./src/Inventory.cpp
                ./src/Map.cpp
                ./src/Player.cpp
                ./src/Room.cpp
                ./src/Tile.cpp
                )

target_link_libraries(Perdition PRIVATE ftxui::screen ftxui::dom ftxui::component)