include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

add_executable(RockPaperScissors
    src/main.cpp
    src/infrastructure/players_input/src/players_input.cpp
)