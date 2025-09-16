# Makefile for Linux - with raylib support (pkg-config or lib/libraylib.a)
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

# Directories
SRC_DIR := src
OBJ_DIR := obj
INCLUDE_DIR := includes
LIB_DIR := lib

# Source & object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable name
TARGET := game

# Raylib detection via pkg-config
PKG_EXISTS := $(shell command -v pkg-config >/dev/null 2>&1 && pkg-config --exists raylib 2>/dev/null && echo yes || echo no)

ifeq ($(PKG_EXISTS),yes)
    RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib)
    RAYLIB_LIBS   := $(shell pkg-config --libs raylib)
else
    # If there's not pkg-config for raylib: search libraylib.a in lib/
    ifneq ("$(wildcard $(LIB_DIR)/libraylib.a)","")
        RAYLIB_CFLAGS := -I$(INCLUDE_DIR)
        # link the .a directly + necessary system libs for Linux
        RAYLIB_LIBS := $(LIB_DIR)/libraylib.a -lGL -lm -lpthread -ldl -lrt -lX11 -lXrandr -lXinerama -lXcursor -lXxf86vm -lXfixes -lasound
    else
        # Fallback: headers in includes and ask for system libraries
        RAYLIB_CFLAGS := -I$(INCLUDE_DIR)
        RAYLIB_LIBS := -lGL -lm -lpthread -ldl -lrt -lX11 -lXrandr -lXinerama -lXcursor -lXxf86vm -lXfixes -lasound
    endif
endif

# Add include flags to CXXFLAGS for compiling
CXXFLAGS := $(CXXFLAGS) $(RAYLIB_CFLAGS) -I$(INCLUDE_DIR)

# Rules
.PHONY: all clean run vendor-info

all: $(OBJ_DIR) $(TARGET)

# Make object directory
$(OBJ_DIR):
	mkdir -p $@

# Link executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $@ $(RAYLIB_LIBS)

# Compile Objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Execute
run: all
	./$(TARGET)

# Util info
vendor-info:
	@echo "PKG_EXISTS = $(PKG_EXISTS)"
	@echo "RAYLIB_CFLAGS = $(RAYLIB_CFLAGS)"
	@echo "RAYLIB_LIBS = $(RAYLIB_LIBS)"

# Limpiar
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
