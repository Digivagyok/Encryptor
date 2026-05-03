CCX = g++
CXXFLAGS = -Wall -Wdeprecated -pedantic -DMEMTRACE -g

HEADERS := $(wildcard *.h) $(wildcard *.hpp)
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:%.cpp=%.o)

.PHONY: all test app clean
all: app

test: encryptor_tester

app: encryptor_app

encryptor_tester: encryptor_tester.o iterator.o
	$(CCX) $(CXXFLAGS) $^ -o $@

encryptor_app: encryptor_app.o iterator.o
	$(CCX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CCX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) encryptor_tester encryptor_app