cmake_minimum_required (VERSION 3.19)
project (SCARA-Simulator-v1)
# The version number.
set (SCARA-Simulator_VERSION_MAJOR 1)
set (SCARA-Simulator_VERSION_MINOR 0)

# Get headers and sources files
file(GLOB_RECURSE SCARA-Simulator_SOURCES "src/*.cpp")
file(GLOB_RECURSE SCARA-Simulator_HEADERS "include/*.h")
set(ROOT "${PROJECT_SOURCE_DIR}")
source_group(TREE ${ROOT} FILES ${SCARA-Simulator_SOURCES} ${SCARA-Simulator_HEADERS})

# ---- Qt configuration -----
IF(NOT QT_DEBUG)
	# Instruct CMake to run moc automatically when needed.
	cmake_policy(SET CMP0020 OLD)
	set(CMAKE_AUTOMOC ON)
	SET(CMAKE_AUTOUIC ON)
	SET(CMAKE_AUTORCC ON)
	set (CMAKE_PREFIX_PATH ${QT_DIR})
	find_package(Qt5Core)
	find_package(Qt5Widgets)
	find_package(Qt5Gui)
ELSE()
	set(CMAKE_AUTOMOC ON)
ENDIF()
#-----------------------------

message("REVIEW INCLUDE FOLDERS HERE, MOST OF THEM SHOULD BE INHERITED")
include_directories("${PROJECT_SOURCE_DIR}/include"
					"${PROJECT_SOURCE_DIR}/ui"
				
)

IF(QT_DEBUG)
	INCLUDE_DIRECTORIES("${QT_DIR}/include"
						"${QT_DIR}/include/QtCore"
						"${QT_DIR}/include/QtWidgets")
	add_definitions(-DQT_DLL
                -DQT_CORE_LIB
                -DQT_GUI_LIB
                -DQT_WIDGETS_LIB)
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
ENDIF()

                    
add_definitions(-DUNICODE
                -DWIN32
                -D_WINDOWS) 
 
# add the executable
add_executable(${PROJECT_NAME} ${SCARA-Simulator_SOURCES} ${SCARA-Simulator_HEADERS})
IF(QT_DEBUG)
	target_link_libraries(${PROJECT_NAME} 
									  debug "${QT_DIR}/lib/qtmaind.lib"
                                      debug "${QT_DIR}/lib/Qt5Cored.lib"
                                      debug "${QT_DIR}/lib/Qt5Guid.lib"
                                      debug "${QT_DIR}/lib/Qt5Widgetsd.lib"
                                      optimized "${QT_DIR}/lib/qtmain.lib"
                                      optimized "${QT_DIR}/lib/Qt5Core.lib"
                                      optimized "${QT_DIR}/lib/Qt5Gui.lib"
                                      optimized "${QT_DIR}/lib/Qt5Widgets.lib")
ELSE()
	target_link_libraries(${PROJECT_NAME} 			Qt5::Widgets
													 Qt5::Core
													 Qt5::Gui
													 Qt5::WinMain
													 )
ENDIF(QT_DEBUG)

SET_TARGET_PROPERTIES( ${PROJECT_NAME}
    PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/../bin/"
)

# -------------------------------------------
# Create Debug and run configurations
# -------------------------------------------
clear_launcher(${PROJECT_NAME})
IF(NOT QT_DEBUG)
Message (STATUS "creating launchers for Debug Flavour")
create_target_launcher(${PROJECT_NAME} RUNTIME_LIBRARY_DIRS "${QT_DIR}/bin"
                                                            "${QT_DIR}/plugins/platforms"
                                                            "${CMAKE_CURRENT_BINARY_DIR}/../bin/Debug"
                                                            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                                                            FLAVOR "Debug")
Message (STATUS "creating launchers for Release Flavour")
create_target_launcher(${PROJECT_NAME} RUNTIME_LIBRARY_DIRS "${QT_DIR}/bin"
                                                            "${QT_DIR}/plugins/platforms"
                                                            "${CMAKE_CURRENT_BINARY_DIR}/../bin/Release"
                                                            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                                                            FLAVOR "Release")
Message (STATUS "creating launchers for RelWithDebInfo Flavour")
create_target_launcher(${PROJECT_NAME} RUNTIME_LIBRARY_DIRS "${QT_DIR}/bin"
                                                            "${QT_DIR}/plugins/platforms"
                                                            "${CMAKE_CURRENT_BINARY_DIR}/../bin/RelWithDebInfo"
                                                           WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                                                            FLAVOR "RelWithDebInfo")															
 
ELSE()

Message(STATUS "No available launchers for QT_DEBUG mode")
ENDIF()

# Set the project in a solutions's folder    
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES FOLDER Main)