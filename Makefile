CC = g++
CXXFLAGS = -std=gnu++17 -Wall -I/usr/include/opencv4 -Iinclude
LDFLAGS = `pkg-config --libs opencv4`

SRC = src/main.cpp src/video_processor.cpp
INCLUDE = include/video_processor.h
EXEC = video_app

all: $(EXEC)
$(EXEC): $(SRC)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(SRC) $(LDFLAGS)

clean: 
	rm -f $(EXEC)