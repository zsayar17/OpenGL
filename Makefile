CC = g++
CFLAGS = -std=c++98 -Wall
LDFLAGS = -lGL -lglfw -ldl

SRCDIR = Src
BUILDDIR = Build

SRCS = $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp) Essantials/glad/glad.c
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))

TARGET = opengl

all: build $(TARGET)

build:
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

re: fclean all

clean:
	rm -f $(TARGET)

fclean: clean
	rm -f $(TARGET)
	rm -rf $(BUILDDIR)

.PHONY: all clean fclean re
