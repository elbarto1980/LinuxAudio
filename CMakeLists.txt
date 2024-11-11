cmake_minimum_required(VERSION 3.5.0)
project(AudioDemo VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(ALSA REQUIRED)
find_package(PipeWire REQUIRED)
find_package(LIBVLC REQUIRED)
find_package(LibVLCpp REQUIRED)
find_package(PulseAudio REQUIRED)

add_executable(AudioDemo main.cpp)

target_include_directories(AudioDemo PUBLIC ${PipeWire_INCLUDE_DIRS} ${Spa_INCLUDE_DIRS} ${LIBVLC_INCLUDE_DIR} ${LIBVLCPP_INCLUDE_DIR} ${PULSEAUDIO_INCLUDE_DIR})
target_link_libraries(AudioDemo asound ${PipeWire_LIBRARIES} ${LIBVLC_LIBRARY} ${PULSEAUDIO_LIBRARY} ${PULSEAUDIO_MAINLOOP_LIBRARY} pthread)