# ticTacToe-cpp
Tic Tac Toe written in C++ and nCurses. This project is an attempt to create something more complex.

Libraries required to compile: ncurses

## Debian based systems:

run ```sudo apt-get install libcurses-dev```

run ```g++ menu.cpp game.cpp init.cpp main.cpp -o tic-tac-toe -static -std=c++17 -lncurses```

run ```./tic-tac-toe```

Done

## Windows based systems

Install cygwin

Ensure ncurses is installed in cygwin

run ```g++ menu.cpp game.cpp init.cpp main.cpp -o tic-tac-toe -static -std=c++17 -lncurses``` within the cygwin terminal

run ```./tic-tac-toe``` within the cygwin terminal

Done
