# Install script for directory: D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/nlohmann_json")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests/abi/cmake_install.cmake")
  include("D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests/cmake_import/cmake_install.cmake")
  include("D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests/cmake_import_minver/cmake_install.cmake")
  include("D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests/cmake_add_subdirectory/cmake_install.cmake")
  include("D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests/cmake_fetch_content/cmake_install.cmake")
  include("D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests/cmake_fetch_content2/cmake_install.cmake")
  include("D:/Sources/Current Projects/Foxy/Foxy 1.XX.X/vendor/json/tests/cmake_target_include_directories/cmake_install.cmake")

endif()
