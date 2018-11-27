cmake_minimum_required(VERSION 3.12)
project(Nodes)

set(CMAKE_CXX_STANDARD 14)

add_executable(Nodes main.cpp DiskNodes.cpp DiskNodes.h DiskNodeFacade.cpp DiskNodeFacade.h Client.cpp Client.h)