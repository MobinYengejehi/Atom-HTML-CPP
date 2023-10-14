cmake_minimum_required(VERSION 3.8)

if (POLICY CMP0141)
	cmake_policy(SET CMP0141 NEW)
	set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(Atom3D)

#set(ATOM_COMPILING_LIBRARY TRUE) # this is when we want to build our dynamic link library files!
set(ATOM_SOURCE_DEVELOPEMENT_MODE TRUE) # this is when we want to build source code directly as executable

include(Atom/AtomCMake.cmake)

file(GLOB PROJECT_SOURCES
	./*.h
	./*.cpp
)

add_executable(Atom3D ${PROJECT_SOURCES} ${ATOM_LIB_HEADERS} ${ATOM_LIB_SOURCES})

if (DEFINED ATOM_EXTERNAL_LIB_LINKER)
	target_link_libraries(Atom3D ${OPENGL_LIBRARY} ${ATOM_EXTERNAL_LIB_LINKER})
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET Atom3D PROPERTY CXX_STANDARD 20)
endif()