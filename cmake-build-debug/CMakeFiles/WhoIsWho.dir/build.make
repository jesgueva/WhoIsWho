# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/esguevaj/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/esguevaj/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/WhoIsWho.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WhoIsWho.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WhoIsWho.dir/flags.make

CMakeFiles/WhoIsWho.dir/testing.cpp.o: CMakeFiles/WhoIsWho.dir/flags.make
CMakeFiles/WhoIsWho.dir/testing.cpp.o: ../testing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WhoIsWho.dir/testing.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WhoIsWho.dir/testing.cpp.o -c "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/testing.cpp"

CMakeFiles/WhoIsWho.dir/testing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WhoIsWho.dir/testing.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/testing.cpp" > CMakeFiles/WhoIsWho.dir/testing.cpp.i

CMakeFiles/WhoIsWho.dir/testing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WhoIsWho.dir/testing.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/testing.cpp" -o CMakeFiles/WhoIsWho.dir/testing.cpp.s

# Object files for target WhoIsWho
WhoIsWho_OBJECTS = \
"CMakeFiles/WhoIsWho.dir/testing.cpp.o"

# External object files for target WhoIsWho
WhoIsWho_EXTERNAL_OBJECTS =

WhoIsWho.exe: CMakeFiles/WhoIsWho.dir/testing.cpp.o
WhoIsWho.exe: CMakeFiles/WhoIsWho.dir/build.make
WhoIsWho.exe: CMakeFiles/WhoIsWho.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WhoIsWho.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WhoIsWho.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WhoIsWho.dir/build: WhoIsWho.exe

.PHONY : CMakeFiles/WhoIsWho.dir/build

CMakeFiles/WhoIsWho.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WhoIsWho.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WhoIsWho.dir/clean

CMakeFiles/WhoIsWho.dir/depend:
	cd "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho" "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho" "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/cmake-build-debug" "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/cmake-build-debug" "/cygdrive/c/Users/esguevaj/OneDrive - Wentworth Institute of Technology/3Junior/5ObjectOrientedProgramming/WhoIsWho/cmake-build-debug/CMakeFiles/WhoIsWho.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/WhoIsWho.dir/depend

