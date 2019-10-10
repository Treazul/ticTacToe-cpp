# ticTacToe-cpp
Tic Tac Toe written in C++ and nCurses. This project is an attempt to create something more complex.

Libraries required to compile: ncurses

## Debian based systems:

run ```sudo apt-get install libcurses-dev```

run ```g++ *.cpp -o tic-tac-toe -std=c++17 -lncurses```

run ```./tic-tac-toe```

Done

## Windows based systems

Install cygwin

Ensure ncurses is installed in cygwin

install mingw64-x86_64-gcc-g++ package in cygwin

run ```x86_64-w64-mingw32-g++ --static *.cpp -o "tic-tac-toe" -std=c++17 -lncurses``` within the cygwin terminal

run the tic-tac-toe.exe in your file-browser.

Done
