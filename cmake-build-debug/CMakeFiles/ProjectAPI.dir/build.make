# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\_Download\CLion-2021.2.win\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\_Download\CLion-2021.2.win\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\MyRepositories\API2021

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\MyRepositories\API2021\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjectAPI.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ProjectAPI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectAPI.dir/flags.make

CMakeFiles/ProjectAPI.dir/capture.c.obj: CMakeFiles/ProjectAPI.dir/flags.make
CMakeFiles/ProjectAPI.dir/capture.c.obj: ../capture.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjectAPI.dir/capture.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectAPI.dir\capture.c.obj -c D:\MyRepositories\API2021\capture.c

CMakeFiles/ProjectAPI.dir/capture.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectAPI.dir/capture.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\capture.c > CMakeFiles\ProjectAPI.dir\capture.c.i

CMakeFiles/ProjectAPI.dir/capture.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectAPI.dir/capture.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\capture.c -o CMakeFiles\ProjectAPI.dir\capture.c.s

CMakeFiles/ProjectAPI.dir/capture_matrix.c.obj: CMakeFiles/ProjectAPI.dir/flags.make
CMakeFiles/ProjectAPI.dir/capture_matrix.c.obj: ../capture_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjectAPI.dir/capture_matrix.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectAPI.dir\capture_matrix.c.obj -c D:\MyRepositories\API2021\capture_matrix.c

CMakeFiles/ProjectAPI.dir/capture_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectAPI.dir/capture_matrix.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\capture_matrix.c > CMakeFiles\ProjectAPI.dir\capture_matrix.c.i

CMakeFiles/ProjectAPI.dir/capture_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectAPI.dir/capture_matrix.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\capture_matrix.c -o CMakeFiles\ProjectAPI.dir\capture_matrix.c.s

CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.obj: CMakeFiles/ProjectAPI.dir/flags.make
CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.obj: ../dijkstra_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectAPI.dir\dijkstra_matrix.c.obj -c D:\MyRepositories\API2021\dijkstra_matrix.c

CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\dijkstra_matrix.c > CMakeFiles\ProjectAPI.dir\dijkstra_matrix.c.i

CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\dijkstra_matrix.c -o CMakeFiles\ProjectAPI.dir\dijkstra_matrix.c.s

CMakeFiles/ProjectAPI.dir/heap.c.obj: CMakeFiles/ProjectAPI.dir/flags.make
CMakeFiles/ProjectAPI.dir/heap.c.obj: ../heap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ProjectAPI.dir/heap.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ProjectAPI.dir\heap.c.obj -c D:\MyRepositories\API2021\heap.c

CMakeFiles/ProjectAPI.dir/heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectAPI.dir/heap.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\heap.c > CMakeFiles\ProjectAPI.dir\heap.c.i

CMakeFiles/ProjectAPI.dir/heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectAPI.dir/heap.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\heap.c -o CMakeFiles\ProjectAPI.dir\heap.c.s

# Object files for target ProjectAPI
ProjectAPI_OBJECTS = \
"CMakeFiles/ProjectAPI.dir/capture.c.obj" \
"CMakeFiles/ProjectAPI.dir/capture_matrix.c.obj" \
"CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.obj" \
"CMakeFiles/ProjectAPI.dir/heap.c.obj"

# External object files for target ProjectAPI
ProjectAPI_EXTERNAL_OBJECTS =

ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/capture.c.obj
ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/capture_matrix.c.obj
ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/dijkstra_matrix.c.obj
ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/heap.c.obj
ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/build.make
ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/linklibs.rsp
ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/objects1.rsp
ProjectAPI.exe: CMakeFiles/ProjectAPI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ProjectAPI.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProjectAPI.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectAPI.dir/build: ProjectAPI.exe
.PHONY : CMakeFiles/ProjectAPI.dir/build

CMakeFiles/ProjectAPI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProjectAPI.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProjectAPI.dir/clean

CMakeFiles/ProjectAPI.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MyRepositories\API2021 D:\MyRepositories\API2021 D:\MyRepositories\API2021\cmake-build-debug D:\MyRepositories\API2021\cmake-build-debug D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles\ProjectAPI.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectAPI.dir/depend

