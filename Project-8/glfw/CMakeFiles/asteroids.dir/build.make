# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/coblmeli/3308/projects/project8/p8-dist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/coblmeli/3308/projects/project8/p8-dist/glfw

# Include any dependencies generated for this target.
include CMakeFiles/asteroids.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/asteroids.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/asteroids.dir/flags.make

CMakeFiles/asteroids.dir/main.cpp.o: CMakeFiles/asteroids.dir/flags.make
CMakeFiles/asteroids.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/coblmeli/3308/projects/project8/p8-dist/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/asteroids.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/asteroids.dir/main.cpp.o -c /home/coblmeli/3308/projects/project8/p8-dist/main.cpp

CMakeFiles/asteroids.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asteroids.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/coblmeli/3308/projects/project8/p8-dist/main.cpp > CMakeFiles/asteroids.dir/main.cpp.i

CMakeFiles/asteroids.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asteroids.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/coblmeli/3308/projects/project8/p8-dist/main.cpp -o CMakeFiles/asteroids.dir/main.cpp.s

CMakeFiles/asteroids.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/asteroids.dir/main.cpp.o.requires

CMakeFiles/asteroids.dir/main.cpp.o.provides: CMakeFiles/asteroids.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/asteroids.dir/main.cpp.o.provides

CMakeFiles/asteroids.dir/main.cpp.o.provides.build: CMakeFiles/asteroids.dir/main.cpp.o


CMakeFiles/asteroids.dir/Game.cpp.o: CMakeFiles/asteroids.dir/flags.make
CMakeFiles/asteroids.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/coblmeli/3308/projects/project8/p8-dist/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/asteroids.dir/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/asteroids.dir/Game.cpp.o -c /home/coblmeli/3308/projects/project8/p8-dist/Game.cpp

CMakeFiles/asteroids.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asteroids.dir/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/coblmeli/3308/projects/project8/p8-dist/Game.cpp > CMakeFiles/asteroids.dir/Game.cpp.i

CMakeFiles/asteroids.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asteroids.dir/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/coblmeli/3308/projects/project8/p8-dist/Game.cpp -o CMakeFiles/asteroids.dir/Game.cpp.s

CMakeFiles/asteroids.dir/Game.cpp.o.requires:

.PHONY : CMakeFiles/asteroids.dir/Game.cpp.o.requires

CMakeFiles/asteroids.dir/Game.cpp.o.provides: CMakeFiles/asteroids.dir/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/Game.cpp.o.provides.build
.PHONY : CMakeFiles/asteroids.dir/Game.cpp.o.provides

CMakeFiles/asteroids.dir/Game.cpp.o.provides.build: CMakeFiles/asteroids.dir/Game.cpp.o


CMakeFiles/asteroids.dir/deps/glad.c.o: CMakeFiles/asteroids.dir/flags.make
CMakeFiles/asteroids.dir/deps/glad.c.o: deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/coblmeli/3308/projects/project8/p8-dist/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/asteroids.dir/deps/glad.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/asteroids.dir/deps/glad.c.o   -c /home/coblmeli/3308/projects/project8/p8-dist/glfw/deps/glad.c

CMakeFiles/asteroids.dir/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/asteroids.dir/deps/glad.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/coblmeli/3308/projects/project8/p8-dist/glfw/deps/glad.c > CMakeFiles/asteroids.dir/deps/glad.c.i

CMakeFiles/asteroids.dir/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/asteroids.dir/deps/glad.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/coblmeli/3308/projects/project8/p8-dist/glfw/deps/glad.c -o CMakeFiles/asteroids.dir/deps/glad.c.s

CMakeFiles/asteroids.dir/deps/glad.c.o.requires:

.PHONY : CMakeFiles/asteroids.dir/deps/glad.c.o.requires

CMakeFiles/asteroids.dir/deps/glad.c.o.provides: CMakeFiles/asteroids.dir/deps/glad.c.o.requires
	$(MAKE) -f CMakeFiles/asteroids.dir/build.make CMakeFiles/asteroids.dir/deps/glad.c.o.provides.build
.PHONY : CMakeFiles/asteroids.dir/deps/glad.c.o.provides

CMakeFiles/asteroids.dir/deps/glad.c.o.provides.build: CMakeFiles/asteroids.dir/deps/glad.c.o


# Object files for target asteroids
asteroids_OBJECTS = \
"CMakeFiles/asteroids.dir/main.cpp.o" \
"CMakeFiles/asteroids.dir/Game.cpp.o" \
"CMakeFiles/asteroids.dir/deps/glad.c.o"

# External object files for target asteroids
asteroids_EXTERNAL_OBJECTS =

asteroids: CMakeFiles/asteroids.dir/main.cpp.o
asteroids: CMakeFiles/asteroids.dir/Game.cpp.o
asteroids: CMakeFiles/asteroids.dir/deps/glad.c.o
asteroids: CMakeFiles/asteroids.dir/build.make
asteroids: glfw/src/libglfw3.a
asteroids: /usr/lib/x86_64-linux-gnu/librt.so
asteroids: /usr/lib/x86_64-linux-gnu/libm.so
asteroids: /usr/lib/x86_64-linux-gnu/libX11.so
asteroids: /usr/lib/x86_64-linux-gnu/libXrandr.so
asteroids: /usr/lib/x86_64-linux-gnu/libXinerama.so
asteroids: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
asteroids: /usr/lib/x86_64-linux-gnu/libXcursor.so
asteroids: CMakeFiles/asteroids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/coblmeli/3308/projects/project8/p8-dist/glfw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable asteroids"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/asteroids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/asteroids.dir/build: asteroids

.PHONY : CMakeFiles/asteroids.dir/build

CMakeFiles/asteroids.dir/requires: CMakeFiles/asteroids.dir/main.cpp.o.requires
CMakeFiles/asteroids.dir/requires: CMakeFiles/asteroids.dir/Game.cpp.o.requires
CMakeFiles/asteroids.dir/requires: CMakeFiles/asteroids.dir/deps/glad.c.o.requires

.PHONY : CMakeFiles/asteroids.dir/requires

CMakeFiles/asteroids.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/asteroids.dir/cmake_clean.cmake
.PHONY : CMakeFiles/asteroids.dir/clean

CMakeFiles/asteroids.dir/depend:
	cd /home/coblmeli/3308/projects/project8/p8-dist/glfw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/coblmeli/3308/projects/project8/p8-dist /home/coblmeli/3308/projects/project8/p8-dist /home/coblmeli/3308/projects/project8/p8-dist/glfw /home/coblmeli/3308/projects/project8/p8-dist/glfw /home/coblmeli/3308/projects/project8/p8-dist/glfw/CMakeFiles/asteroids.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/asteroids.dir/depend

