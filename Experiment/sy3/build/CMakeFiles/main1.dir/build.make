# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/cgc/anaconda3/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/cgc/anaconda3/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cgc/Library/dsa/DSA/Experiment/sy3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cgc/Library/dsa/DSA/Experiment/sy3/build

# Include any dependencies generated for this target.
include CMakeFiles/main1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main1.dir/flags.make

CMakeFiles/main1.dir/main1.cpp.o: CMakeFiles/main1.dir/flags.make
CMakeFiles/main1.dir/main1.cpp.o: /home/cgc/Library/dsa/DSA/Experiment/sy3/main1.cpp
CMakeFiles/main1.dir/main1.cpp.o: CMakeFiles/main1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cgc/Library/dsa/DSA/Experiment/sy3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main1.dir/main1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main1.dir/main1.cpp.o -MF CMakeFiles/main1.dir/main1.cpp.o.d -o CMakeFiles/main1.dir/main1.cpp.o -c /home/cgc/Library/dsa/DSA/Experiment/sy3/main1.cpp

CMakeFiles/main1.dir/main1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main1.dir/main1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cgc/Library/dsa/DSA/Experiment/sy3/main1.cpp > CMakeFiles/main1.dir/main1.cpp.i

CMakeFiles/main1.dir/main1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main1.dir/main1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cgc/Library/dsa/DSA/Experiment/sy3/main1.cpp -o CMakeFiles/main1.dir/main1.cpp.s

CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o: CMakeFiles/main1.dir/flags.make
CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o: /home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp
CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o: CMakeFiles/main1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cgc/Library/dsa/DSA/Experiment/sy3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o -MF CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o.d -o CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o -c /home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp

CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp > CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.i

CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp -o CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.s

# Object files for target main1
main1_OBJECTS = \
"CMakeFiles/main1.dir/main1.cpp.o" \
"CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o"

# External object files for target main1
main1_EXTERNAL_OBJECTS =

main1: CMakeFiles/main1.dir/main1.cpp.o
main1: CMakeFiles/main1.dir/home/cgc/Library/dsa/DSA/Experiment/template/vector.cpp.o
main1: CMakeFiles/main1.dir/build.make
main1: CMakeFiles/main1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cgc/Library/dsa/DSA/Experiment/sy3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable main1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main1.dir/build: main1
.PHONY : CMakeFiles/main1.dir/build

CMakeFiles/main1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main1.dir/clean

CMakeFiles/main1.dir/depend:
	cd /home/cgc/Library/dsa/DSA/Experiment/sy3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cgc/Library/dsa/DSA/Experiment/sy3 /home/cgc/Library/dsa/DSA/Experiment/sy3 /home/cgc/Library/dsa/DSA/Experiment/sy3/build /home/cgc/Library/dsa/DSA/Experiment/sy3/build /home/cgc/Library/dsa/DSA/Experiment/sy3/build/CMakeFiles/main1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main1.dir/depend

