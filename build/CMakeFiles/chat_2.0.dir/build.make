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
CMAKE_SOURCE_DIR = /home/awl/projects/chat_2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/awl/projects/chat_2.0/build

# Include any dependencies generated for this target.
include CMakeFiles/chat_2.0.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chat_2.0.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chat_2.0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chat_2.0.dir/flags.make

CMakeFiles/chat_2.0.dir/main.cpp.o: CMakeFiles/chat_2.0.dir/flags.make
CMakeFiles/chat_2.0.dir/main.cpp.o: ../main.cpp
CMakeFiles/chat_2.0.dir/main.cpp.o: CMakeFiles/chat_2.0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/chat_2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chat_2.0.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chat_2.0.dir/main.cpp.o -MF CMakeFiles/chat_2.0.dir/main.cpp.o.d -o CMakeFiles/chat_2.0.dir/main.cpp.o -c /home/awl/projects/chat_2.0/main.cpp

CMakeFiles/chat_2.0.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chat_2.0.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/chat_2.0/main.cpp > CMakeFiles/chat_2.0.dir/main.cpp.i

CMakeFiles/chat_2.0.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chat_2.0.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/chat_2.0/main.cpp -o CMakeFiles/chat_2.0.dir/main.cpp.s

CMakeFiles/chat_2.0.dir/chat.cpp.o: CMakeFiles/chat_2.0.dir/flags.make
CMakeFiles/chat_2.0.dir/chat.cpp.o: ../chat.cpp
CMakeFiles/chat_2.0.dir/chat.cpp.o: CMakeFiles/chat_2.0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/chat_2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chat_2.0.dir/chat.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chat_2.0.dir/chat.cpp.o -MF CMakeFiles/chat_2.0.dir/chat.cpp.o.d -o CMakeFiles/chat_2.0.dir/chat.cpp.o -c /home/awl/projects/chat_2.0/chat.cpp

CMakeFiles/chat_2.0.dir/chat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chat_2.0.dir/chat.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/chat_2.0/chat.cpp > CMakeFiles/chat_2.0.dir/chat.cpp.i

CMakeFiles/chat_2.0.dir/chat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chat_2.0.dir/chat.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/chat_2.0/chat.cpp -o CMakeFiles/chat_2.0.dir/chat.cpp.s

CMakeFiles/chat_2.0.dir/connector.cpp.o: CMakeFiles/chat_2.0.dir/flags.make
CMakeFiles/chat_2.0.dir/connector.cpp.o: ../connector.cpp
CMakeFiles/chat_2.0.dir/connector.cpp.o: CMakeFiles/chat_2.0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/chat_2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chat_2.0.dir/connector.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chat_2.0.dir/connector.cpp.o -MF CMakeFiles/chat_2.0.dir/connector.cpp.o.d -o CMakeFiles/chat_2.0.dir/connector.cpp.o -c /home/awl/projects/chat_2.0/connector.cpp

CMakeFiles/chat_2.0.dir/connector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chat_2.0.dir/connector.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/chat_2.0/connector.cpp > CMakeFiles/chat_2.0.dir/connector.cpp.i

CMakeFiles/chat_2.0.dir/connector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chat_2.0.dir/connector.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/chat_2.0/connector.cpp -o CMakeFiles/chat_2.0.dir/connector.cpp.s

CMakeFiles/chat_2.0.dir/database.cpp.o: CMakeFiles/chat_2.0.dir/flags.make
CMakeFiles/chat_2.0.dir/database.cpp.o: ../database.cpp
CMakeFiles/chat_2.0.dir/database.cpp.o: CMakeFiles/chat_2.0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/chat_2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chat_2.0.dir/database.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chat_2.0.dir/database.cpp.o -MF CMakeFiles/chat_2.0.dir/database.cpp.o.d -o CMakeFiles/chat_2.0.dir/database.cpp.o -c /home/awl/projects/chat_2.0/database.cpp

CMakeFiles/chat_2.0.dir/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chat_2.0.dir/database.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/chat_2.0/database.cpp > CMakeFiles/chat_2.0.dir/database.cpp.i

CMakeFiles/chat_2.0.dir/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chat_2.0.dir/database.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/chat_2.0/database.cpp -o CMakeFiles/chat_2.0.dir/database.cpp.s

CMakeFiles/chat_2.0.dir/indexmap.cpp.o: CMakeFiles/chat_2.0.dir/flags.make
CMakeFiles/chat_2.0.dir/indexmap.cpp.o: ../indexmap.cpp
CMakeFiles/chat_2.0.dir/indexmap.cpp.o: CMakeFiles/chat_2.0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/awl/projects/chat_2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chat_2.0.dir/indexmap.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chat_2.0.dir/indexmap.cpp.o -MF CMakeFiles/chat_2.0.dir/indexmap.cpp.o.d -o CMakeFiles/chat_2.0.dir/indexmap.cpp.o -c /home/awl/projects/chat_2.0/indexmap.cpp

CMakeFiles/chat_2.0.dir/indexmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chat_2.0.dir/indexmap.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/awl/projects/chat_2.0/indexmap.cpp > CMakeFiles/chat_2.0.dir/indexmap.cpp.i

CMakeFiles/chat_2.0.dir/indexmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chat_2.0.dir/indexmap.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/awl/projects/chat_2.0/indexmap.cpp -o CMakeFiles/chat_2.0.dir/indexmap.cpp.s

# Object files for target chat_2.0
chat_2_0_OBJECTS = \
"CMakeFiles/chat_2.0.dir/main.cpp.o" \
"CMakeFiles/chat_2.0.dir/chat.cpp.o" \
"CMakeFiles/chat_2.0.dir/connector.cpp.o" \
"CMakeFiles/chat_2.0.dir/database.cpp.o" \
"CMakeFiles/chat_2.0.dir/indexmap.cpp.o"

# External object files for target chat_2.0
chat_2_0_EXTERNAL_OBJECTS =

chat_2.0: CMakeFiles/chat_2.0.dir/main.cpp.o
chat_2.0: CMakeFiles/chat_2.0.dir/chat.cpp.o
chat_2.0: CMakeFiles/chat_2.0.dir/connector.cpp.o
chat_2.0: CMakeFiles/chat_2.0.dir/database.cpp.o
chat_2.0: CMakeFiles/chat_2.0.dir/indexmap.cpp.o
chat_2.0: CMakeFiles/chat_2.0.dir/build.make
chat_2.0: CMakeFiles/chat_2.0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/awl/projects/chat_2.0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable chat_2.0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chat_2.0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chat_2.0.dir/build: chat_2.0
.PHONY : CMakeFiles/chat_2.0.dir/build

CMakeFiles/chat_2.0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chat_2.0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chat_2.0.dir/clean

CMakeFiles/chat_2.0.dir/depend:
	cd /home/awl/projects/chat_2.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/awl/projects/chat_2.0 /home/awl/projects/chat_2.0 /home/awl/projects/chat_2.0/build /home/awl/projects/chat_2.0/build /home/awl/projects/chat_2.0/build/CMakeFiles/chat_2.0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chat_2.0.dir/depend

