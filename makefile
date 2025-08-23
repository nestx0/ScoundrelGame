CXX := g++
CXXFLAGS := -I.includes -Wall -Wextra -std=c++17

# Directorios
SRC_DIR := src
OBJ_DIR := obj

# Archivos fuente y objetos
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Nombre del ejecutable
TARGET := game

# Regla principal
all: $(OBJ_DIR) $(TARGET)

# Crear directorio de objetos
$(OBJ_DIR):
	mkdir -p $@

# Enlazar ejecutable
$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^

# Compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpiar
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean