PLATFORM ?= linux

ifeq ($(PLATFORM),windows)
    CC      = x86_64-w64-mingw32-gcc
    TARGET  = bin/vsrg.exe
    RAYLIB  = lib/windows/libraylib.a
    INCLUDE = -Ilib/windows/include

    CFLAGS  = -Wall -std=c99 -g $(INCLUDE)
    LDFLAGS = $(RAYLIB) -lopengl32 -lgdi32 -lwinmm -static -static-libgcc
else
    CC      = gcc
    TARGET  = bin/vsrg
    RAYLIB  = lib/linux/libraylib.a

    CFLAGS  = -Wall -std=c99 -g -O3
    LDFLAGS = $(RAYLIB) -lGL -lm -lpthread -ldl -lrt -lX11
endif

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/$(PLATFORM)/%.o)
DEP = $(OBJ:.o=.d)

$(TARGET): $(OBJ) | bin
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

obj/$(PLATFORM)/%.o: src/%.c | obj/$(PLATFORM)
	$(CC) $(CFLAGS) -c $< -o $@

bin obj/$(PLATFORM):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

windows:
	$(MAKE) PLATFORM=windows

clean:
	rm -rf bin obj



