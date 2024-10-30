SOURCES = $(wildcard *.cpp)
EXECUTABLES_WIN = $(SOURCES:.cpp=.exe)
EXECUTABLES_UNIX = $(SOURCES:.cpp=.out)

ifeq ($(OS),Windows_NT)
    EXECUTABLES = $(EXECUTABLES_WIN)
    DEL_CMD = del /Q
else
    EXECUTABLES = $(EXECUTABLES_UNIX)
    DEL_CMD = rm -f
endif

CXX = g++
CXXFLAGS = -Wall -Wextra -O2
LDFLAGS = -mconsole 

all: $(EXECUTABLES)

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	$(DEL_CMD) *.exe *.out


.PHONY: all clean
