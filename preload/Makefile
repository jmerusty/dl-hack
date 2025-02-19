CC 		= gcc
SRC		= ./src
DEST 	= ./bin

write:
	$(CC) -fPIC -shared $(SRC)/write.c -o $(DEST)/write.o -ldl

main:
	$(CC) $(SRC)/main.c -o ./$(DEST)/main

run: main write
	LD_PRELOAD=$(DEST)/write.o $(DEST)/main
