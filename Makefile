CXX = clang++
CXXFLAGS = -std=c++11 -Iincludes

LIB_SOURCES = src/Attribute.cpp
MAIN_SOURCES = src/program.cpp

TESTS_INCLUDES = tests/TestsAttribute.h
CXXTEST = tests/cxxtest

LIB_OBJECTS = $(subst .cpp,.o, $(LIB_SOURCES))
MAIN_OBJECTS = $(subst .cpp,.o, $(MAIN_SOURCES))
EXEC = program

all: $(EXEC)

debug: CXXFLAGS += -g -DMAP
debug: $(EXEC)

$(EXEC): $(LIB_OBJECTS) $(MAIN_OBJECTS)
	$(CXX) -o $(EXEC) $(LIB_OBJECTS) $(MAIN_OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(LIB_OBJECTS) $(MAIN_OBJECTS) $(EXEC)
	
.PHONY: unittest
unittest: $(LIB_OBJECTS)
	$(CXXTEST)/bin/cxxtestgen --error-printer -o tmp.cpp $(TESTS_INCLUDES)
	$(CXX) -o unittest -I$(CXXTEST) $(CXXFLAGS) tmp.cpp $(LIB_OBJECTS)
	./unittest
	rm unittest tmp.cpp