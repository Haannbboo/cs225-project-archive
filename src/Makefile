#
# This is a generic Makefile designed to compile a sample directory of code.
# This file depends on variables having been set before calling:
#   EXE: The name of the result file
#   OBJS: Array of objects files (.o) to be generated
#   CLEAN_RM: Optional list of additional files to delete on `make clean`
#
# @author Wade Fagen-Ulmschneider, <waf@illinois.edu>
# @author Jeffrey Tolar
#

# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o


# mp_traverals specific stuff
# Add all `colorPicker` and `imageTraversal`s:
CPP_FILES += $(wildcard data/*.cpp)
CPP_FILES += $(wildcard DataLoader/*.cpp)
CPP_FILES += $(wildcard algorithms/*.cpp)
OBJS += $(CPP_FILES:.cpp=.o)


# Compiler/linker comfig and object/depfile directory:
CXX = clang++
LD = clang++
OBJS_DIR = .objs

# Add standard final project files
OBJS += data/Map.o data/Point.o data/Road.o DataLoader/dataLoader.o algorithms/Astar.o

# Add cs225 related files
OBJS += cs225/HSLAPixel.o cs225/PNG.o cs225/lodepng/lodepng.o

# -MMD and -MP asks clang++ to generate a .d file listing the headers used in the source code for use in the Make process.
#   -MMD: "Write a depfile containing user headers"
#   -MP : "Create phony target for each dependency (other than main file)"
#   (https://clang.llvm.org/docs/ClangCommandLineReference.html)
DEPFILE_FLAGS = -MMD -MP

# Provide lots of helpful warning/errors:
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

# Flags for compile:
CXXFLAGS += -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) $(DEPFILE_FLAGS) -g -c

# Flags for linking:
LDFLAGS += -std=c++1y -stdlib=libc++ -lc++abi

# Rule for `all` (first/default rule):
all: $(EXE)

# Rule for linking the final executable:
# - $(EXE) depends on all object files in $(OBJS)
# - `patsubst` function adds the directory name $(OBJS_DIR) before every object file
$(EXE): output_msg $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS))
	$(LD) $(filter-out $<, $^) $(LDFLAGS) -o $@

# Ensure .objs/ exists:
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/data
	@mkdir -p $(OBJS_DIR)/DataLoader
	@mkdir -p $(OBJS_DIR)/algorithms
	@mkdir -p $(OBJS_DIR)/tests
	@mkdir -p $(OBJS_DIR)/cs225
	@mkdir -p $(OBJS_DIR)/cs225/catch
	@mkdir -p $(OBJS_DIR)/cs225/lodepng

# Rules for compiling source code.
# - Every object file is required by $(EXE)
# - Generates the rule requiring the .cpp file of the same name
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@


# Rules for compiling test suite.
# - Grab every .cpp file in tests/, compile them to .o files
# - Build the test program w/ catchmain.cpp from cs225
OBJS_TEST += $(filter-out $(EXE_OBJ), $(OBJS))
CPP_TEST = $(wildcard tests/*.cpp)
CPP_TEST += cs225/catch/catchmain.cpp
OBJS_TEST += $(CPP_TEST:.cpp=.o)

$(TEST): output_msg $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS_TEST))
	$(LD) $(filter-out $<, $^) $(LDFLAGS) -o $@


# Additional dependencies for object files are included in the clang++
# generated .d files (from $(DEPFILE_FLAGS)):
-include $(OBJS_DIR)/*.d
-include $(OBJS_DIR)/data/*.d
-include $(OBJS_DIR)/DataLoader/*.d
-include $(OBJS_DIR)/algorithms/*.d
-include $(OBJS_DIR)/tests/*.d
-include $(OBJS_DIR)/cs225/*.d
-include $(OBJS_DIR)/cs225/catch/*.d
-include $(OBJS_DIR)/cs225/lodepng/*.d


output_msg: ; $(CLANG_VERSION_MSG)

# Standard C++ Makefile rules:
clean:
	rm -rf $(EXE) $(TEST) $(OBJS_DIR) *.o *.d

tidy: clean
	rm -rf doc

.PHONY: all tidy clean output_msg
