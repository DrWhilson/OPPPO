# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/SFU/OPPPO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/SFU/OPPPO/build

# Include any dependencies generated for this target.
include src/CMakeFiles/libs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/libs.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/libs.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/libs.dir/flags.make

src/CMakeFiles/libs.dir/figure.cpp.o: src/CMakeFiles/libs.dir/flags.make
src/CMakeFiles/libs.dir/figure.cpp.o: ../src/figure.cpp
src/CMakeFiles/libs.dir/figure.cpp.o: src/CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/SFU/OPPPO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/libs.dir/figure.cpp.o"
	cd /home/user/SFU/OPPPO/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/libs.dir/figure.cpp.o -MF CMakeFiles/libs.dir/figure.cpp.o.d -o CMakeFiles/libs.dir/figure.cpp.o -c /home/user/SFU/OPPPO/src/figure.cpp

src/CMakeFiles/libs.dir/figure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libs.dir/figure.cpp.i"
	cd /home/user/SFU/OPPPO/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/SFU/OPPPO/src/figure.cpp > CMakeFiles/libs.dir/figure.cpp.i

src/CMakeFiles/libs.dir/figure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libs.dir/figure.cpp.s"
	cd /home/user/SFU/OPPPO/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/SFU/OPPPO/src/figure.cpp -o CMakeFiles/libs.dir/figure.cpp.s

src/CMakeFiles/libs.dir/lib.cpp.o: src/CMakeFiles/libs.dir/flags.make
src/CMakeFiles/libs.dir/lib.cpp.o: ../src/lib.cpp
src/CMakeFiles/libs.dir/lib.cpp.o: src/CMakeFiles/libs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/SFU/OPPPO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/libs.dir/lib.cpp.o"
	cd /home/user/SFU/OPPPO/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/libs.dir/lib.cpp.o -MF CMakeFiles/libs.dir/lib.cpp.o.d -o CMakeFiles/libs.dir/lib.cpp.o -c /home/user/SFU/OPPPO/src/lib.cpp

src/CMakeFiles/libs.dir/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libs.dir/lib.cpp.i"
	cd /home/user/SFU/OPPPO/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/SFU/OPPPO/src/lib.cpp > CMakeFiles/libs.dir/lib.cpp.i

src/CMakeFiles/libs.dir/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libs.dir/lib.cpp.s"
	cd /home/user/SFU/OPPPO/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/SFU/OPPPO/src/lib.cpp -o CMakeFiles/libs.dir/lib.cpp.s

# Object files for target libs
libs_OBJECTS = \
"CMakeFiles/libs.dir/figure.cpp.o" \
"CMakeFiles/libs.dir/lib.cpp.o"

# External object files for target libs
libs_EXTERNAL_OBJECTS =

src/liblibs.a: src/CMakeFiles/libs.dir/figure.cpp.o
src/liblibs.a: src/CMakeFiles/libs.dir/lib.cpp.o
src/liblibs.a: src/CMakeFiles/libs.dir/build.make
src/liblibs.a: src/CMakeFiles/libs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/SFU/OPPPO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblibs.a"
	cd /home/user/SFU/OPPPO/build/src && $(CMAKE_COMMAND) -P CMakeFiles/libs.dir/cmake_clean_target.cmake
	cd /home/user/SFU/OPPPO/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/libs.dir/build: src/liblibs.a
.PHONY : src/CMakeFiles/libs.dir/build

src/CMakeFiles/libs.dir/clean:
	cd /home/user/SFU/OPPPO/build/src && $(CMAKE_COMMAND) -P CMakeFiles/libs.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/libs.dir/clean

src/CMakeFiles/libs.dir/depend:
	cd /home/user/SFU/OPPPO/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/SFU/OPPPO /home/user/SFU/OPPPO/src /home/user/SFU/OPPPO/build /home/user/SFU/OPPPO/build/src /home/user/SFU/OPPPO/build/src/CMakeFiles/libs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/libs.dir/depend

