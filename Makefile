WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC =gcc -std=c99 -g $(WARNING) $(ERROR)


a1: main

main: main.o
	$(GCC) main.o -o main

main.o: main.c
	$(GCC) main.c -c main.o -o main

testall: test1 test2 test3 test4 test5 test6

test1:
	@echo "0" | ./main > output1.txt
	diff output1.txt tests/expected1.txt

test2:
	@echo "5" | ./main > output2.txt
	diff output2.txt tests/expected2.txt

test3:
	@echo "25" | ./main > output3.txt
	diff output3.txt tests/expected3.txt

test4:
	@echo "37" | ./main > output4.txt
	diff output4.txt tests/expected4.txt

test5:
	@echo "69" | ./main > output5.txt
	diff output5.txt tests/expected5.txt

test6:
	@echo "90" | ./main > output6.txt
	diff output6.txt tests/expected6.txt

clean:
	rm *.o main output*