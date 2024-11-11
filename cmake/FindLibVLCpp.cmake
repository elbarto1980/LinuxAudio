FIND_PATH(LIBVLCPP_INCLUDE_DIR vlcpp/vlc.hpp
  HINTS "$ENV{LIBVLCPP_INCLUDE_PATH}"
  PATHS
    #Mac OS and Contribs
    "${CMAKE_CURRENT_SOURCE_DIR}/contribs/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/contribs/include/vlc"
    "/Applications/VLC.app/Contents/MacOS/include"
    "/Applications/VLC.app/Contents/MacOS/include/vlc"
    # Env
    "$ENV{LIB_DIR}/include"
    "$ENV{LIB_DIR}/include/vlc"
    #
    "./submodules/libvlcpp"
    "/usr/include"
    "/usr/include/vlc"
    "/usr/local/include"
    #mingw
    c:/msys/local/include
    "c:/Program Files (x86)/VideoLAN/VLC/sdk/include"
  )
FIND_PATH(LIBVLCPP_INCLUDE_DIR PATHS "${CMAKE_INCLUDE_PATH}/vlcpp" NAMES vlc.hpp)


IF (LIBVLCPP_INCLUDE_DIR)
   SET(LIBVLCPP_FOUND TRUE)
ENDIF (LIBVLCPP_INCLUDE_DIR)

IF (LIBVLCPP_FOUND)
   IF (NOT LIBVLCPP_FIND_QUIETLY)
      MESSAGE(STATUS "Found LibVLCpp include-dir path: ${LIBVLCPP_INCLUDE_DIR}")
   ENDIF (NOT LIBVLCPP_FIND_QUIETLY)
ELSE (LIBVLC_FOUND)
   IF (LIBVLC_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find LibVLCpp")
   ENDIF (LIBVLC_FIND_REQUIRED)
ENDIF (LIBVLCPP_FOUND)
