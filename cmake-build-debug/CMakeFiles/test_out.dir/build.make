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
include CMakeFiles/test_out.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/test_out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_out.dir/flags.make

CMakeFiles/test_out.dir/capture.c.obj: CMakeFiles/test_out.dir/flags.make
CMakeFiles/test_out.dir/capture.c.obj: ../capture.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_out.dir/capture.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_out.dir\capture.c.obj -c D:\MyRepositories\API2021\capture.c

CMakeFiles/test_out.dir/capture.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_out.dir/capture.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\capture.c > CMakeFiles\test_out.dir\capture.c.i

CMakeFiles/test_out.dir/capture.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_out.dir/capture.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\capture.c -o CMakeFiles\test_out.dir\capture.c.s

CMakeFiles/test_out.dir/capture_matrix.c.obj: CMakeFiles/test_out.dir/flags.make
CMakeFiles/test_out.dir/capture_matrix.c.obj: ../capture_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_out.dir/capture_matrix.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_out.dir\capture_matrix.c.obj -c D:\MyRepositories\API2021\capture_matrix.c

CMakeFiles/test_out.dir/capture_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_out.dir/capture_matrix.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\capture_matrix.c > CMakeFiles\test_out.dir\capture_matrix.c.i

CMakeFiles/test_out.dir/capture_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_out.dir/capture_matrix.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\capture_matrix.c -o CMakeFiles\test_out.dir\capture_matrix.c.s

CMakeFiles/test_out.dir/dijkstra_matrix.c.obj: CMakeFiles/test_out.dir/flags.make
CMakeFiles/test_out.dir/dijkstra_matrix.c.obj: ../dijkstra_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_out.dir/dijkstra_matrix.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_out.dir\dijkstra_matrix.c.obj -c D:\MyRepositories\API2021\dijkstra_matrix.c

CMakeFiles/test_out.dir/dijkstra_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_out.dir/dijkstra_matrix.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\dijkstra_matrix.c > CMakeFiles\test_out.dir\dijkstra_matrix.c.i

CMakeFiles/test_out.dir/dijkstra_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_out.dir/dijkstra_matrix.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\dijkstra_matrix.c -o CMakeFiles\test_out.dir\dijkstra_matrix.c.s

CMakeFiles/test_out.dir/heap.c.obj: CMakeFiles/test_out.dir/flags.make
CMakeFiles/test_out.dir/heap.c.obj: ../heap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test_out.dir/heap.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_out.dir\heap.c.obj -c D:\MyRepositories\API2021\heap.c

CMakeFiles/test_out.dir/heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_out.dir/heap.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\heap.c > CMakeFiles\test_out.dir\heap.c.i

CMakeFiles/test_out.dir/heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_out.dir/heap.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\heap.c -o CMakeFiles\test_out.dir\heap.c.s

CMakeFiles/test_out.dir/my_dijkstra.c.obj: CMakeFiles/test_out.dir/flags.make
CMakeFiles/test_out.dir/my_dijkstra.c.obj: ../my_dijkstra.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/test_out.dir/my_dijkstra.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_out.dir\my_dijkstra.c.obj -c D:\MyRepositories\API2021\my_dijkstra.c

CMakeFiles/test_out.dir/my_dijkstra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_out.dir/my_dijkstra.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\my_dijkstra.c > CMakeFiles\test_out.dir\my_dijkstra.c.i

CMakeFiles/test_out.dir/my_dijkstra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_out.dir/my_dijkstra.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\my_dijkstra.c -o CMakeFiles\test_out.dir\my_dijkstra.c.s

CMakeFiles/test_out.dir/tutorial.c.obj: CMakeFiles/test_out.dir/flags.make
CMakeFiles/test_out.dir/tutorial.c.obj: ../tutorial.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/test_out.dir/tutorial.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_out.dir\tutorial.c.obj -c D:\MyRepositories\API2021\tutorial.c

CMakeFiles/test_out.dir/tutorial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_out.dir/tutorial.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\tutorial.c > CMakeFiles\test_out.dir\tutorial.c.i

CMakeFiles/test_out.dir/tutorial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_out.dir/tutorial.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\tutorial.c -o CMakeFiles\test_out.dir\tutorial.c.s

CMakeFiles/test_out.dir/tosubmit_clear.c.obj: CMakeFiles/test_out.dir/flags.make
CMakeFiles/test_out.dir/tosubmit_clear.c.obj: ../tosubmit_clear.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/test_out.dir/tosubmit_clear.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test_out.dir\tosubmit_clear.c.obj -c D:\MyRepositories\API2021\tosubmit_clear.c

CMakeFiles/test_out.dir/tosubmit_clear.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_out.dir/tosubmit_clear.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\MyRepositories\API2021\tosubmit_clear.c > CMakeFiles\test_out.dir\tosubmit_clear.c.i

CMakeFiles/test_out.dir/tosubmit_clear.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_out.dir/tosubmit_clear.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\MyRepositories\API2021\tosubmit_clear.c -o CMakeFiles\test_out.dir\tosubmit_clear.c.s

# Object files for target test_out
test_out_OBJECTS = \
"CMakeFiles/test_out.dir/capture.c.obj" \
"CMakeFiles/test_out.dir/capture_matrix.c.obj" \
"CMakeFiles/test_out.dir/dijkstra_matrix.c.obj" \
"CMakeFiles/test_out.dir/heap.c.obj" \
"CMakeFiles/test_out.dir/my_dijkstra.c.obj" \
"CMakeFiles/test_out.dir/tutorial.c.obj" \
"CMakeFiles/test_out.dir/tosubmit_clear.c.obj"

# External object files for target test_out
test_out_EXTERNAL_OBJECTS =

test_out.exe: CMakeFiles/test_out.dir/capture.c.obj
test_out.exe: CMakeFiles/test_out.dir/capture_matrix.c.obj
test_out.exe: CMakeFiles/test_out.dir/dijkstra_matrix.c.obj
test_out.exe: CMakeFiles/test_out.dir/heap.c.obj
test_out.exe: CMakeFiles/test_out.dir/my_dijkstra.c.obj
test_out.exe: CMakeFiles/test_out.dir/tutorial.c.obj
test_out.exe: CMakeFiles/test_out.dir/tosubmit_clear.c.obj
test_out.exe: CMakeFiles/test_out.dir/build.make
test_out.exe: CMakeFiles/test_out.dir/linklibs.rsp
test_out.exe: CMakeFiles/test_out.dir/objects1.rsp
test_out.exe: CMakeFiles/test_out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable test_out.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_out.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_out.dir/build: test_out.exe
.PHONY : CMakeFiles/test_out.dir/build

CMakeFiles/test_out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_out.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_out.dir/clean

CMakeFiles/test_out.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MyRepositories\API2021 D:\MyRepositories\API2021 D:\MyRepositories\API2021\cmake-build-debug D:\MyRepositories\API2021\cmake-build-debug D:\MyRepositories\API2021\cmake-build-debug\CMakeFiles\test_out.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_out.dir/depend

