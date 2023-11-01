# Battleship
Implementation of the popular game "Battleship" in C++.


# Gameplay
## Board Overview
- The size of the board is variable, but for now we will start with 10x10.
- The rows of the board will be labeled alphabetically, while columns will be labeled numerically
- Coordinates of the board used for gameplay shall be in ROWCOLUMN format, e.g. A10, C3.
## Ship Configuaration
- Instructions will be displayed at the beginning of ship configuration.
- A working list will be displayed with every configuration prompt, showing the user how many of their ships are left.
- The user can type in the ship type, the starting coordinate, and the direction of the ship.
## Gameplay
- With every turn prompt, the player's working board and the opponent's board will be displayed and updated.
- The user will guess the computer's ships by inputting coordinates.
- A hit, miss, and sink will be displayed accordingly.
- Upon sinking all of the computer's ships, either the computer or player wins.


