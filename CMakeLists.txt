cmake_minimum_required(VERSION 3.3)
project(lighter)

set(CMAKE_ASM_COMPILER arm-none-eabi-as) # Asembler compiler.

set(CMAKE_C_COMPILER arm-none-eabi-gcc) # C compiler.
set(CMAKE_C_FLAGS "-std=c11 -Wall -O3 -nostdlib -nostartfiles -ffreestanding -mthumb") # C compiler flags.

set(CMAKE_CXX_COMPILER arm-none-eabi-gcc) # C++ compiler.
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3 -nostdlib -nostartfiles -ffreestanding -mthumb") # C++ compiler flags.

set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_SOURCE_DIR}/linker.ld") # Use custom linker file.
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS) # Disable --rdynamic flag. It's unsupported in ARM GCC.
set(SOURCE_FILES startup.s main.c) # startup.s must be first for proper linking.

enable_language(ASM) # Enable custom assembler.

include_directories(include) # Header files.
add_subdirectory(src) # Source files.

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} led)

# Transform ELF to binary ARM format.
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND arm-none-eabi-objcopy ${PROJECT_NAME} -O binary)
