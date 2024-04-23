CXX = g++
CXXFLAGS = -std=c++17 -pthread

SRCDIR = .
INCDIR = .
BUILDDIR = .
BINDIR = .

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))
DEPS = $(wildcard $(INCDIR)/*.hpp)

TARGET = $(BINDIR)/main

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all clean