# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/jon/Projects/Programming/Embedded/h4_embedded_opgave5/out/default.eep"
  "/home/jon/Projects/Programming/Embedded/h4_embedded_opgave5/out/default.hex"
  "/home/jon/Projects/Programming/Embedded/h4_embedded_opgave5/out/default.lss"
  "/home/jon/Projects/Programming/Embedded/h4_embedded_opgave5/out/default.srec"
  "/home/jon/Projects/Programming/Embedded/h4_embedded_opgave5/out/default.usersignatures"
  )
endif()
