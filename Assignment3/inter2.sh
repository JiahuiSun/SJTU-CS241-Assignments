#!/usr/bin/expect

spawn sh exe.sh
expect "*"
send "1.6\r"
interact

spawn sh exe.sh
expect "*"
send "2.8\r"
interact

spawn sh exe.sh
expect "*"
send "0.7\r"
interact

