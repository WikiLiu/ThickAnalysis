# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = /home/wiki/c++/project/ThickAnalysis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wiki/c++/project/ThickAnalysis/build

# Include any dependencies generated for this target.
include CMakeFiles/ThickaAnalysis_o.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ThickaAnalysis_o.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ThickaAnalysis_o.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ThickaAnalysis_o.dir/flags.make

CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o: CMakeFiles/ThickaAnalysis_o.dir/flags.make
CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o: ../src/mian.cpp
CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o: CMakeFiles/ThickaAnalysis_o.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wiki/c++/project/ThickAnalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o -MF CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o.d -o CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o -c /home/wiki/c++/project/ThickAnalysis/src/mian.cpp

CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wiki/c++/project/ThickAnalysis/src/mian.cpp > CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.i

CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wiki/c++/project/ThickAnalysis/src/mian.cpp -o CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.s

# Object files for target ThickaAnalysis_o
ThickaAnalysis_o_OBJECTS = \
"CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o"

# External object files for target ThickaAnalysis_o
ThickaAnalysis_o_EXTERNAL_OBJECTS =

ThickaAnalysis_o: CMakeFiles/ThickaAnalysis_o.dir/src/mian.cpp.o
ThickaAnalysis_o: CMakeFiles/ThickaAnalysis_o.dir/build.make
ThickaAnalysis_o: CMakeFiles/ThickaAnalysis_o.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wiki/c++/project/ThickAnalysis/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ThickaAnalysis_o"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ThickaAnalysis_o.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ThickaAnalysis_o.dir/build: ThickaAnalysis_o
.PHONY : CMakeFiles/ThickaAnalysis_o.dir/build

CMakeFiles/ThickaAnalysis_o.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ThickaAnalysis_o.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ThickaAnalysis_o.dir/clean

CMakeFiles/ThickaAnalysis_o.dir/depend:
	cd /home/wiki/c++/project/ThickAnalysis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wiki/c++/project/ThickAnalysis /home/wiki/c++/project/ThickAnalysis /home/wiki/c++/project/ThickAnalysis/build /home/wiki/c++/project/ThickAnalysis/build /home/wiki/c++/project/ThickAnalysis/build/CMakeFiles/ThickaAnalysis_o.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ThickaAnalysis_o.dir/depend
