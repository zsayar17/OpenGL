CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS = -lGL -lglfw -ldl

SRCDIR = Src
GLADDIR = Essantials/glad
BUILDDIR = Build

SRCS = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(GLADDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp)) $(patsubst $(GLADDIR)/%.c, $(BUILDDIR)/%.o, $(wildcard $(GLADDIR)/*.c))

TARGET = opengl

all: build $(TARGET)

build:
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDDIR)/%.o: $(GLADDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

re: fclean all

clean:
	rm -f $(TARGET)

fclean: clean
	rm -rf $(BUILDDIR)
	rm -f $(TARGET)

.PHONY: all clean fclean re
