# Overview #
Lighter is a CMake C/C++ project template used with GCC ARM cross compiler. Targeted for Stellaris LM4F120 LaunchPad
with ARM Cortex-M4F Based MCU but should work for almost any other ARM.

Codes does almost nothing. It is just a saved template for project.

# Compilation #
Remember to set correct paths to compilers and linker in CMakeLists.txt file in the main directory of the project.

```
#!bash

git clone git@bitbucket.org:Kajtek/lighter.git
mkdir lighter/build
cd lighter/build
cmake ..
make
```

This will create **lighter** binary file under **lighter/build** directory. This executable is ready to flash to memory.
You can test it, on Stellaris LM4F120 LaunchPad Evaluation Kit it will light on the led.
