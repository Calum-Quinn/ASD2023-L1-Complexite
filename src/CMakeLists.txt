cmake_minimum_required(VERSION 3.16)
project(ASD2022-L1-Complexite)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(L1-example operations.cpp generateVector.cpp main.cpp comparisonsAffectations.cpp tris.h temps.h generateVector.h tris_impl.h temps_impl.h test.h test_impl.h OpCounter.h OpCounter_impl.h)