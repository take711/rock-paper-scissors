file(GLOB_RECURSE MANAGER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(RockPaperScissors
    ${MANAGER_SOURCES}
)
message(STATUS "MANAGER_SOURCES: ${MANAGER_SOURCES}")

target_include_directories(RockPaperScissors PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/domain
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/infrastructure
)