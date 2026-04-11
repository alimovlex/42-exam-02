add_library(tests)

target_sources(tests
  PRIVATE
    tests.cpp
  PUBLIC
    tests.h
  )

target_include_directories(tests
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(tests
    PUBLIC
      "--coverage"
    )
  target_link_options(tests
    INTERFACE
      "--coverage"
    )
endif()
