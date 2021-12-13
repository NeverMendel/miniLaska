# miniLaska
> Terminal based Laska game

## How to build it

This project uses CMake. To build the project you need to:

- Run CMake on main folder
  ```
  cmake -S . -B build
  ```
- Build the project
  ```
  cmake --build build
  ```

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