cmake_minimum_required(VERSION 3.2)
project(gestionnaireDeFilm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(gestionnaireDeFilm ${SOURCE_FILES} inventaire.h inventaire.c fichier.h fichier.c gestionnaire.h gestionnaire.c list.h list.c)