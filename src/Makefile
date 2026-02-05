CC = gcc

RAYLIB_PATH = C:/raylib-5.5_win64_mingw-w64

CFLAGS = -Wall -Wextra -std=c99 \
	-Iinclude \
	-I$(RAYLIB_PATH)/include

LDFLAGS = -L$(RAYLIB_PATH)/lib \
	-lraylib -lm -lopengl32 -lgdi32 -lwinmm

TARGET = raycaster

SRC = src/main.c src/player.c src/map.c src/raycast.c

all:
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

clean:
	del $(TARGET).exe
