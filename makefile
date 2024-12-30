include src/cpp/cpp.mk

info:
	@echo "-------------------------------------"
	@echo "Project Configuration for cpp :"
	@echo "-------------------------------------"
	@echo "CXX (C++ Compiler) . . . . . . . : $(CXX)"
	@echo "CXXFLAGS (C++ Flags) . . . . . . : $(CXXFLAGS)"
	@echo "CPP_SRC_FILES (C++ Source Files) : $(SOURCES)"
	@echo "PROJECT_NAME . . . . . . . . . . : $(LIB_NAME)"
	@echo "-------------------------------------"