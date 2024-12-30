# Variables générales
CXX = g++
AR = ar
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib
INCLUDE_DIR = include
CXXFLAGS = -std=c++17 -O2 -I$(INCLUDE_DIR) -fPIC
LDFLAGS = 
SOURCES = $(wildcard $(SRC_DIR)/cpp/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/cpp/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

LIB_VERSION = v1.0.0
LIB_NAME = drxType_cpp_$(LIB_VERSION)

# Bibliothèque
STATIC_LIB = $(LIB_DIR)/$(LIB_NAME).a
SHARED_LIB = $(LIB_DIR)/$(LIB_NAME).so

# Détection de l'OS
ifeq ($(OS),Windows_NT)
    SHARED_LIB = $(LIB_DIR)/$(LIB_NAME).dll
    LDFLAGS += -shared
    CXXFLAGS += -DWIN32
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        SHARED_LIB = $(LIB_DIR)/$(LIB_NAME).dylib
        LDFLAGS += -dynamiclib
        CXXFLAGS += -DMACOS
    else
        CXXFLAGS += -DLINUX
    endif
endif

# Règles par défaut
all: $(STATIC_LIB) $(SHARED_LIB)

# Création de la bibliothèque statique
$(STATIC_LIB): $(OBJECTS)
	mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^

# Création de la bibliothèque dynamique
$(SHARED_LIB): $(OBJECTS)
	mkdir -p $(LIB_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/cpp/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

.PHONY: all clean
