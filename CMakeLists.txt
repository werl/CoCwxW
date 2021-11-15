cmake_minimum_required(VERSION 3.20)
project(CoCwxW)

set(CMAKE_CXX_STANDARD 17)

add_executable(CoCwxW WIN32 src/main.cpp src/main_frame.cpp src/main_frame.hpp src/id_enum.cpp src/id_enum.hpp src/panels/left_panel.cpp src/panels/left_panel.hpp src/panels/right_panel.cpp src/panels/right_panel.hpp src/backend/character.cpp src/backend/character.hpp src/panels/abstract_panel.cpp src/panels/abstract_panel.hpp src/panels/default_panel.cpp src/panels/default_panel.hpp)

find_package(wxWidgets REQUIRED)

target_include_directories(CoCwxW PUBLIC ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(CoCwxW PUBLIC ${wxWidgets_LIBRARIES})