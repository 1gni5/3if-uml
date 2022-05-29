CXX = g++
CXXFLAGS = -std=c++11 -Imodel/includes

LIB_SOURCES = model/src/Attribute.cpp model/src/Cleaner.cpp model/src/Provider.cpp \
model/src/Sensor.cpp model/src/User.cpp model/src/Measurement.cpp model/src/Utilities.cpp model/src/System.cpp
MAIN_SOURCES = model/src/program.cpp

TESTS_INCLUDES = tests/TestsAttribute.h tests/TestsCleaner.h tests/TestsProvider.h \
tests/TestsSensor.h tests/TestsUser.h tests/TestsMeasurement.h tests/TestsSystem.h
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
