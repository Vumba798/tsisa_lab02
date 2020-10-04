cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RandomSearcher)

add_library(random_searcher STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/randomSearcher.cpp
)
add_executable(main
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
)

target_include_directories(random_searcher
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(main
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(main PUBLIC random_searcher)
