cmake_minimum_required(VERSION 3.0.0)
project(chat_2.0 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(chat_2.0 main.cpp chat.cpp connector.cpp database.cpp indexmap.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
