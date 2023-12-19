# Battleship
Implementation of the popular game "Battleship" in C++.


# Gameplay
## Board Overview
- The size of the board is 10x10.
- Currently both rows and columns are labeled numerically.
- Coordinates of the board used for gameplay shall be in COLUMNROW format, e.g. 10 (1,0), 53 (5,3).
## Ship Configuaration
- Instructions will be displayed at the beginning of ship configuration.
- A working list will be displayed with every configuration prompt, showing the user how many of their ships are left.
- The user can type in the ship type, the starting coordinate, and the direction of the ship.
- After each player configures their ships, the game can commence.
## Gameplay
- With every turn prompt, the player's working board and the opponent's board will be displayed and updated.
- The opposing player's board will be hidden by the user.
- The user will guess the computer's ships by inputting coordinates.
- A hit, miss, and sink will be displayed accordingly.
- Upon sinking all of the computer's ships, either the computer or player wins.

## Lower Design
- Split into ship and board classes; Handle state with board.
- Each ship shall track its coords; each board shall track its ships, and thus all occupied coords.


