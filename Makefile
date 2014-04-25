OBJ=lcs
SRC=$(wildcard *.cpp)
${OBJ}:${SRC}
	cp S${S}.in S.in
	g++ -g -I. ${SRC} -o ${OBJ} -DS${S}
.PHONY:run clean
run:
	./${OBJ} < S.in
clean:
	rm -f ${OBJ} 
