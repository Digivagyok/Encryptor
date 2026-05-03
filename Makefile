CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

TARGET_TEST := encryptor_tester
TARGET_APP := encryptor_app

TEST_OBJS := encryptor_tester.o iterator.o
APP_OBJS := encryptor_app.o iterator.o

.PHONY: all clean test app

all: app

test: $(TARGET_TEST)

app: $(TARGET_APP)

$(TARGET_TEST): $(TEST_OBJS)
    $(CXX) $(CXXFLAGS) $^ -o $@

$(TARGET_APP): $(APP_OBJS)
    $(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f *.o *.exe $(TARGET_TEST) $(TARGET_APP)