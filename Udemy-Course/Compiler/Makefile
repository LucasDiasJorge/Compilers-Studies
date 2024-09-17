OBJECTS= ./build/compiler.o ./build/cprocess.o 
INCLUDES= -I./

all: ${OBJECTS}
	gcc main.c ${INCLUDES} ${OBJECTS} -g -o ./main 

./build/compiler.o: ./compiler.c
	gcc compiler.c ${INCLUDES} -o ./build/compiler.o -g -c

./build/cprocess.o: ./cprocess.c
	gcc cprocess.c ${INCLUDES} -o ./build/cprocess.o -g -c

./build/buffer.o: ./helpers/buffer.c
	gcc buffer.c ${INCLUDES} -o ./build/buffer.o -g -c

./build/vector.o: ./helpers/vector.c
	gcc vector.c ${INCLUDES} -o ./build/vector.o -g -c


clean:
	rm ./main
	rm -rf ${OBJECTS}