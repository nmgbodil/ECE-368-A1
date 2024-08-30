WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC =gcc -std=c99 -g $(WARNING) $(ERROR)


a1: main

main: main.o
	$(GCC) main.o -o main

main.o: src/main.c
	$(GCC) -c src/main.c -o main.o

testall: test1 test2 test3 test4 test5 test6

test1:
	@echo "0" | ./main > output1.txt
	diff tests/expected1.txt output1.txt

test2:
	@echo "5" | ./main > output2.txt
	diff tests/expected2.txt output2.txt

test3:
	@echo "25" | ./main > output3.txt
	diff tests/expected3.txt output3.txt

test4:
	@echo "37" | ./main > output4.txt
	diff tests/expected4.txt output4.txt

test5:
	@echo "69" | ./main > output5.txt
	diff tests/expected5.txt output5.txt

test6:
	@echo "90" | ./main > output6.txt
	diff tests/expected6.txt output6.txt

clean:
	rm -f *.o main output*