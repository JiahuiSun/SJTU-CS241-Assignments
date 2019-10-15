main.out: JacobiIteration.cpp
	g++ -o $@ $< -std=c++11
	
test11: test1
	echo "4\n1 -1 2 -1 -8\n2 -2 3 -3 -20\n1 1 1 0 -2\n1 -1 4 3 4" | ./test1
test12: test1
	echo "4\n1 1 0 3 4\n2 1 -1 1 1\n3 -1 -1 2 -3\n-1 2 3 -1 4" | ./test1

test13: test1
	echo "4\n10 -1 2 0 6\n-1 11 -1 3 25\n2 -1 10 -1 -11\n0 3 -1 8 15\n0 0 0 0\n" | ./test1

test4: test1
	echo "3\n1 1 1 4\n2 2 1 6\n1 1 2 6" | ./test1
