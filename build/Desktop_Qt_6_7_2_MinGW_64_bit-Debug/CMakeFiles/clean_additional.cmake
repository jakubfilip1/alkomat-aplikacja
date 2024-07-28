# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Narzedzize_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Narzedzize_autogen.dir\\ParseCache.txt"
  "Narzedzize_autogen"
  )
endif()
