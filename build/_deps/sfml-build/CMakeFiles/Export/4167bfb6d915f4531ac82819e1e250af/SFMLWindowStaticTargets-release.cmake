#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SFML::Window" for configuration "RELEASE"
set_property(TARGET SFML::Window APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SFML::Window PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsfml-window-s.a"
  )

list(APPEND _cmake_import_check_targets SFML::Window )
list(APPEND _cmake_import_check_files_for_SFML::Window "${_IMPORT_PREFIX}/lib64/libsfml-window-s.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
