CFLAGS = -g -Iinclude -Itype -Wall
BIN_PATH =  ./build
SRC_PATH =  ./src
TYPE_PATH = ./type
type_src = $(wildcard ${TYPE_PATH}/*.c)
src = $(wildcard ${SRC_PATH}/*.c)

vm: $(src) $(type_src)
	$(CC) $(CFLAGS) $^

.PHONY : clean

clean:
	-rm -rf a.out* 
