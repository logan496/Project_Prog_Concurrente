# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/concurrence_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/concurrence_autogen.dir/ParseCache.txt"
  "concurrence_autogen"
  )
endif()
