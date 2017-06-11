# Install script for directory: G:/learnMore/opengl/assimp-3.3.1/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/learnMore/opengl/assimp331build/code/Debug/assimp-vc120-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/learnMore/opengl/assimp331build/code/Release/assimp-vc120-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/learnMore/opengl/assimp331build/code/MinSizeRel/assimp-vc120-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/learnMore/opengl/assimp331build/code/RelWithDebInfo/assimp-vc120-mt.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.3.1")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/learnMore/opengl/assimp331build/code/Debug/assimp-vc120-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/learnMore/opengl/assimp331build/code/Release/assimp-vc120-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/learnMore/opengl/assimp331build/code/MinSizeRel/assimp-vc120-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/learnMore/opengl/assimp331build/code/RelWithDebInfo/assimp-vc120-mt.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/anim.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/ai_assert.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/camera.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/color4.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/color4.inl"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/config.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/defs.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/cfileio.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/light.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/material.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/material.inl"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/matrix3x3.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/matrix3x3.inl"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/matrix4x4.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/matrix4x4.inl"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/mesh.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/postprocess.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/quaternion.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/quaternion.inl"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/scene.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/metadata.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/texture.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/types.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/vector2.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/vector2.inl"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/vector3.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/vector3.inl"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/version.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/cimport.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/importerdesc.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/Importer.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/DefaultLogger.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/ProgressHandler.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/IOStream.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/IOSystem.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/Logger.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/LogStream.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/NullLogger.hpp"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/cexport.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/Exporter.hpp"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/Compiler/pushpack1.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/Compiler/poppack1.h"
    "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "G:/learnMore/opengl/assimp-3.3.1/code/../include/assimp//AndroidJNIIOSystem.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "G:/learnMore/opengl/assimp331build/code/Debug/assimp-vc120-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "G:/learnMore/opengl/assimp331build/code/RelWithDebInfo/assimp.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

