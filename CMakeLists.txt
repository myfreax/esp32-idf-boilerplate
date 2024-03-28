# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
find_package(Git QUIET)
execute_process(COMMAND
  "${GIT_EXECUTABLE}" describe --tags --always --dirty
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
  OUTPUT_VARIABLE "GIT_REVISION"
  ERROR_QUIET
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
set(PROJECT_VER "${GIT_REVISION}")
project(esp32-idf-boilerplate)
add_custom_command(
  TARGET app POST_BUILD
  COMMAND ${PROJECT_SOURCE_DIR}/package.sh ${PROJECT_VER} ${CMAKE_BINARY_DIR} ${PROJECT_NAME}
)