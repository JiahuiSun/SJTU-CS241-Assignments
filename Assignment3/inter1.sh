#!/usr/bin/expect

spawn sh exe.sh
expect "*"
send "1 -7 10 3\n0 0 1 -5\r"
interact

spawn sh exe.sh
expect "*"
send "4 -4 1 3\n0 0 3 0\r"
interact

spawn sh exe.sh
expect "*"
send "3 -2 3/5 0\n0 1 7 5\r"
interact
