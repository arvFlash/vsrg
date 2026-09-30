PLATFORM ?= linux
BACKEND  ?= x11

ifeq ($(PLATFORM),windows)

    CC      = x86_64-w64-mingw32-gcc
    TARGET  = bin/vsrg.exe
    RAYLIB  = lib/windows/libraylib.a
    INCLUDE = -Ilib/windows/include

    CFLAGS  = -Wall -std=c99 -g -flto $(INCLUDE)
    LDFLAGS = $(RAYLIB) -lopengl32 -lgdi32 -lwinmm -static -static-libgcc -flto

    OBJDIR  = obj/windows

else

    CC      = gcc
    TARGET  = bin/vsrg
    INCLUDE = -Ilib/linux/$(BACKEND)
    RAYLIB  = lib/linux/$(BACKEND)/libraylib.a

    CFLAGS  = -Wall -std=c99 -g -O3 -flto $(INCLUDE)

    ifeq ($(BACKEND),wayland)
        LDFLAGS = $(RAYLIB) -lGL -lwayland-client -lwayland-cursor -lxkbcommon -lm -lpthread -ldl -lrt -flto
        OBJDIR  = obj/linux/wayland
    else ifeq ($(BACKEND),x11)
        LDFLAGS = $(RAYLIB) -lGL -lX11 -lm -lpthread -ldl -lrt -flto
        OBJDIR  = obj/linux/x11
    else
        $(error Unknown backend '$(BACKEND)')
    endif

endif

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

$(TARGET): $(OBJ) | bin
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

bin $(OBJDIR):
	mkdir -p $@

-include $(DEP)

run: $(TARGET)
	./$(TARGET)

wayland:
	$(MAKE) PLATFORM=linux BACKEND=wayland

x11:
	$(MAKE) PLATFORM=linux BACKEND=x11

windows:
	$(MAKE) PLATFORM=windows

clean:
	rm -rf bin obj

.PHONY: run wayland x11 windows clean
