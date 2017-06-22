cmake_minimum_required(VERSION 3.6)
project(DomiCity)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Game.cpp Game.h GameState.cpp GameState.h GameStateStart.h GameStateEditor.h GameStateStart.cpp GameStateEditor.cpp TextureManager.cpp TextureManager.h AnimationEngine.cpp AnimationEngine.h Tile.cpp Tile.h map.cpp map.h gui.cpp gui.h cityController.cpp cityController.h)
add_executable(DomiCity ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(DomiCity ${SFML_LIBRARIES})
endif()

# Add the source files
file(GLOB DOMICITY_SRC
        "*.h"
        "*.cpp"
        )

# Install executable
install(TARGETS DomiCity
        RUNTIME DESTINATION .)

# Install game assets
install(DIRECTORY media/
        DESTINATION media/)

# Install config files
install(FILES city_cfg.dat city_map.dat LICENSE README.md
        DESTINATION .)