CC=gcc

OBJ_DIR=src
SRC_DIR=src

TARGET_DIR=build
TARGET_FILE=csevm
TARGET=$(TARGET_DIR)/$(TARGET_FILE)

SRCS=$(wildcard $(SRC_DIR)/*.c)
INCLUDE=src
OBJS=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CFLAGS=-I$(INCLUDE)

INSTALL_DIR=/usr/bin
INSTALL=$(INSTALL_DIR)/$(TARGET_FILE)

all: $(TARGET)

$(TARGET): $(OBJS)
	@[ -d build ] || mkdir -p build
	@$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ $(CFLAGS)

run: all
	@./$(TARGET) $(arg)

install: all
	sudo mv $(TARGET) $(INSTALL)

uninstall: all
	sudo rm -f $(INSTALL)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -rf build

.PHONY: all clean run install uninstall
