cmake_minimum_required(VERSION 2.6)
project(atomicnes)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

add_subdirectory(lib/fmt)

set(COMPILER_FEATURES cxx_std_17)

set(ANES_SOURCES
  src/error/unimplemented_error.cpp src/error/unimplemented_error.h

  src/logger/nestest.cpp src/logger/nestest.h

  src/AddressingMode.h
  src/Debugger.cpp src/Debugger.h
  src/Cpu.h
  src/DecodeInfo.h
  src/Executor.cpp src/Executor.h
  src/Instruction.cpp src/Instruction.h
  src/Memory.cpp src/Memory.h
  src/Operation.h

  src/RomLoader.cpp src/RomLoader.h)

set(ANES_TEST_SOURCES
  tests/main.cpp
  tests/Instruction.cpp
  tests/Memory.cpp
  tests/Cpu.cpp)
 
add_library(libaNES ${ANES_SOURCES})
add_executable(aNES src/main.cpp)
add_executable(tests ${ANES_TEST_SOURCES}) 
 
set(COMMON_INCLUDES
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/lib/header-only
  ${CMAKE_SOURCE_DIR}/lib)
 
set(COMMON_LIBRARIES 
  fmt::fmt)


target_include_directories(libaNES PRIVATE ${COMMON_INCLUDES})
target_include_directories(aNES PRIVATE ${COMMON_INCLUDES})
target_include_directories(tests PRIVATE ${COMMON_INCLUDES})

target_link_libraries(libaNES PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(aNES PRIVATE libaNES ${COMMON_LIBRARIES})
target_link_libraries(tests PRIVATE libaNES ${COMMON_LIBRARIES})

target_compile_features(libaNES PUBLIC ${COMPILER_FEATURES} )
target_compile_features(aNES PUBLIC ${COMPILER_FEATURES} )
target_compile_features(tests PUBLIC ${COMPILER_FEATURES} )
