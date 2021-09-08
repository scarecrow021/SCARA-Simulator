cmake_minimum_required (VERSION 3.19)
project (SCARA-Simulator_v1)
# The version number.
set (SCARA-Simulator_VERSION_MAJOR 1)
set (SCARA-Simulator_VERSION_MINOR 0)
if (MSVC_VERSION GREATER_EQUAL "1900")
    set (CMAKE_CXX_STANDARD 17)
else()
	set (CMAKE_CXX_STANDARD 14)
endif()
# Add cmake resources to generate run config
include(CreateLaunchers.cmake)
# DEPENDENCIES DIR
set(DEPENDENCIES_DIR "${CMAKE_SOURCE_DIR}")
#  Qt
set(QT_DIR "${DEPENDENCIES_DIR}/Qt/5.6.0/msvc2015_64" CACHE PATH "Qt dir")
#MESSAGE ("Qt directory folder is set to: ${QT_DIR}" )

#Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

MACRO(SUBDIRLIST result curdir i)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist_${i} "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      set(dir ${curdir}/${child})
      message(${dir})
      SUBDIRLIST(dirlist ${dir} i++)
      LIST(APPEND dirlist ${dir})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})

ENDMACRO()


# add specific flag for debug :
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")


set(CMAKE_DEBUG_POSTFIX d)



# Add sub-directories
message("Adding SCARA_Simulator ...")
add_subdirectory(SCARA_Simulator)
