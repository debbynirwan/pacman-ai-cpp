# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build

# Include any dependencies generated for this target.
include game/layout/CMakeFiles/layout.dir/depend.make

# Include the progress variables for this target.
include game/layout/CMakeFiles/layout.dir/progress.make

# Include the compile flags for this target's objects.
include game/layout/CMakeFiles/layout.dir/flags.make

game/layout/CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.o: game/layout/CMakeFiles/layout.dir/flags.make
game/layout/CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.o: game/layout/layout_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object game/layout/CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.o"
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;-warnings-as-errors=*" --source=/home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout/layout_autogen/mocs_compilation.cpp -- /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.o -c /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout/layout_autogen/mocs_compilation.cpp

game/layout/CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.i"
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout/layout_autogen/mocs_compilation.cpp > CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.i

game/layout/CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.s"
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout/layout_autogen/mocs_compilation.cpp -o CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.s

game/layout/CMakeFiles/layout.dir/layout.cpp.o: game/layout/CMakeFiles/layout.dir/flags.make
game/layout/CMakeFiles/layout.dir/layout.cpp.o: ../game/layout/layout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object game/layout/CMakeFiles/layout.dir/layout.cpp.o"
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=-*,clang-diagnostic-*,clang-analyzer-*,cppcoreguidelines-*,;-warnings-as-errors=*" --source=/home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/game/layout/layout.cpp -- /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/layout.dir/layout.cpp.o -c /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/game/layout/layout.cpp

game/layout/CMakeFiles/layout.dir/layout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layout.dir/layout.cpp.i"
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/game/layout/layout.cpp > CMakeFiles/layout.dir/layout.cpp.i

game/layout/CMakeFiles/layout.dir/layout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layout.dir/layout.cpp.s"
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/game/layout/layout.cpp -o CMakeFiles/layout.dir/layout.cpp.s

# Object files for target layout
layout_OBJECTS = \
"CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/layout.dir/layout.cpp.o"

# External object files for target layout
layout_EXTERNAL_OBJECTS =

game/layout/liblayout.a: game/layout/CMakeFiles/layout.dir/layout_autogen/mocs_compilation.cpp.o
game/layout/liblayout.a: game/layout/CMakeFiles/layout.dir/layout.cpp.o
game/layout/liblayout.a: game/layout/CMakeFiles/layout.dir/build.make
game/layout/liblayout.a: game/layout/CMakeFiles/layout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library liblayout.a"
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && $(CMAKE_COMMAND) -P CMakeFiles/layout.dir/cmake_clean_target.cmake
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/layout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
game/layout/CMakeFiles/layout.dir/build: game/layout/liblayout.a

.PHONY : game/layout/CMakeFiles/layout.dir/build

game/layout/CMakeFiles/layout.dir/clean:
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout && $(CMAKE_COMMAND) -P CMakeFiles/layout.dir/cmake_clean.cmake
.PHONY : game/layout/CMakeFiles/layout.dir/clean

game/layout/CMakeFiles/layout.dir/depend:
	cd /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/game/layout /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout /home/debby/Workspace-HDD/Workspace/pacman-ai-cpp/build/game/layout/CMakeFiles/layout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : game/layout/CMakeFiles/layout.dir/depend

