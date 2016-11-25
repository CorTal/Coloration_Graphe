cmake_minimum_required(VERSION 2.6)
project(coloration_graphe_qt)
find_package(Qt4 REQUIRED)
add_definitions(-std=c++1y -ggdb -O3)
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Coloration_Graphe_QT_SRCS Moteur.cpp Noeud.cpp Graphe.cpp Coloration_Graphe_QT.cpp main.cpp)

qt4_automoc(${Coloration_Graphe_QT_SRCS})
add_executable(coloration_graphe_qt ${Coloration_Graphe_QT_SRCS})
target_link_libraries(coloration_graphe_qt ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS coloration_graphe_qt RUNTIME DESTINATION bin)
