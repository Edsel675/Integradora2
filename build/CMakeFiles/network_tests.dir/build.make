# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/edselcisneros/Documents/Integradora2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/edselcisneros/Documents/Integradora2/build

# Include any dependencies generated for this target.
include CMakeFiles/network_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/network_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/network_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/network_tests.dir/flags.make

CMakeFiles/network_tests.dir/codegen:
.PHONY : CMakeFiles/network_tests.dir/codegen

CMakeFiles/network_tests.dir/test/test_network.cpp.o: CMakeFiles/network_tests.dir/flags.make
CMakeFiles/network_tests.dir/test/test_network.cpp.o: /Users/edselcisneros/Documents/Integradora2/test/test_network.cpp
CMakeFiles/network_tests.dir/test/test_network.cpp.o: CMakeFiles/network_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/edselcisneros/Documents/Integradora2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/network_tests.dir/test/test_network.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/network_tests.dir/test/test_network.cpp.o -MF CMakeFiles/network_tests.dir/test/test_network.cpp.o.d -o CMakeFiles/network_tests.dir/test/test_network.cpp.o -c /Users/edselcisneros/Documents/Integradora2/test/test_network.cpp

CMakeFiles/network_tests.dir/test/test_network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/network_tests.dir/test/test_network.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/edselcisneros/Documents/Integradora2/test/test_network.cpp > CMakeFiles/network_tests.dir/test/test_network.cpp.i

CMakeFiles/network_tests.dir/test/test_network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/network_tests.dir/test/test_network.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/edselcisneros/Documents/Integradora2/test/test_network.cpp -o CMakeFiles/network_tests.dir/test/test_network.cpp.s

# Object files for target network_tests
network_tests_OBJECTS = \
"CMakeFiles/network_tests.dir/test/test_network.cpp.o"

# External object files for target network_tests
network_tests_EXTERNAL_OBJECTS =

network_tests: CMakeFiles/network_tests.dir/test/test_network.cpp.o
network_tests: CMakeFiles/network_tests.dir/build.make
network_tests: lib/libgtest_main.a
network_tests: lib/libgtest.a
network_tests: CMakeFiles/network_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/edselcisneros/Documents/Integradora2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable network_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/network_tests.dir/link.txt --verbose=$(VERBOSE)
	/opt/homebrew/bin/cmake -D TEST_TARGET=network_tests -D TEST_EXECUTABLE=/Users/edselcisneros/Documents/Integradora2/build/network_tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/edselcisneros/Documents/Integradora2/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=network_tests_TESTS -D CTEST_FILE=/Users/edselcisneros/Documents/Integradora2/build/network_tests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_DISCOVERY_EXTRA_ARGS= -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/network_tests.dir/build: network_tests
.PHONY : CMakeFiles/network_tests.dir/build

CMakeFiles/network_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/network_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/network_tests.dir/clean

CMakeFiles/network_tests.dir/depend:
	cd /Users/edselcisneros/Documents/Integradora2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/edselcisneros/Documents/Integradora2 /Users/edselcisneros/Documents/Integradora2 /Users/edselcisneros/Documents/Integradora2/build /Users/edselcisneros/Documents/Integradora2/build /Users/edselcisneros/Documents/Integradora2/build/CMakeFiles/network_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/network_tests.dir/depend

