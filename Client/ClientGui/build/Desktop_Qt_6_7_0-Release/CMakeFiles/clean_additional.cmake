# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/ClientGui_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ClientGui_autogen.dir/ParseCache.txt"
  "ClientGui_autogen"
  )
endif()
