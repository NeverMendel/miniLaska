# miniLaska

Terminal based Lasca game written in ANSI C. Lasca is a game similar to checkers and is played in a 7x7 chess board.

## Features

- Cross-platform thanks to CMake
- Documentation
- Test cases
- AI bot powered by Minimax algorithm with Alpha–beta pruning and a set of custom rules. Have a look at the code [here](https://github.com/NeverMendel/miniLaska/blob/master/src/logic.c#L97).

## How to build it

### Production

To build for production, just execute `make` or alternatively `make production`.

### Debug

To build for debugging, execute `make debug`.

You can now run the tests by executing `ctest` in the `debug` folder.

## Project structure

```
src
├── constants.h
├── cvector.h
├── logic.c
├── logic.h
├── main.c
├── terminal.c
├── terminal.h
├── utility.c
└── utility.h
test
├── apply_move_test.c
├── clone_board_test.c
├── compute_state_test.c
├── does_move_eat_test.c
├── get_possible_moves.c
├── is_pos_valid_test.c
├── minimax_test.c
└── pos_conversion.c
```

## Documentation

The Doxygen documentation of the project is available in Italian [here as a website](https://nevermendel.github.io/miniLaska/) or [here as a pdf](https://github.com/NeverMendel/miniLaska/blob/gh-pages/refman.pdf).

The University report of this game is available in Italian [here](Relazione%20MiniLaska.pdf).