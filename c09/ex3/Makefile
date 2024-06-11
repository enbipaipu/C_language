# 特殊変数なし
pi: integral.o main.o
	gcc -Wall -g integral.c main.o -o pi

integral.o: integral.c
	gcc -Wall -c -g integral.c -o integral.o

main.o: main.c
	gcc -Wall -c -g main.c -o main.o

clean:
	rm -f pi *.o

# 特殊変数を利用する記法
# pi: integral.o main.o
# 	gcc -Wall -g $^ -o $@

# integral.o: integral.c
# 	gcc -Wall -c -g $< -o $@

# main.o: main.c
# 	gcc -Wall -c -g $< -o $@

# clean:
# 	rm -f pi *.o