target:	run	clean
CC = gcc
CFLAGS = -Wall -Iinclude -Icommon_functions -DMODULE=$(MODULE) -DTASK=$(TASK)
LDFLAGS = -lm

MODULE ?= 1
TASK ?= 1

MOD_DIR = 170875_Karan_DR_Module$(MODULE)_T006

OBJ_DIR = obj
MAIN_OBJ = $(OBJ_DIR)/main.o

COMMON_SRC = common_functions/function.c
COMMON_OBJ = common_functions/function.o

SRC = $(MOD_DIR)/src/170875_Karan_DR_Module$(MODULE)-$(TASK).c
OBJ = $(MOD_DIR)/obj/170875_Karan_DR_Module$(MODULE)-$(TASK).o


TARGET = bin/main_1.out

all: run

$(TARGET): $(OBJ) $(MAIN_OBJ) $(COMMON_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) $(COMMON_OBJ) -o $(TARGET) $(LDFLAGS)

$(OBJ): $(SRC)
	@mkdir -p $(MOD_DIR)/obj
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_OBJ): main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(COMMON_OBJ): $(COMMON_SRC)
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf */obj/*.o obj/*.o
	rm -rf common_functions/*.o
	rm -rf bin/*

