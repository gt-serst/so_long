# so_long
# World of Warcraft : Wrath of the Lich King
Gain power by looting dark runes and bring the rules of the Undead Scourge back to Azeroth, escape before you die.
<img width="944" alt="Screen Shot 2023-06-05 at 6 03 35 PM" src="https://github.com/gt-serst/so_long/assets/81758850/762d400d-fb83-47c5-b8f0-b1d170a80536">

# parsing
First, map parsing. The map must have a .ber extenssion, be closed by walls and rectangular, have at least one collectible and exactly one player and one exit. Finally, only 0 (empty space), 1 (wall), C (collectible), E (exit) and P (player) characters are allowed.
# flood fill
The player's goal is to reach exit case after looting all the collectibles which are present on the map. Replacing empty spaces by walls with a flood fill algorithm allows me to understand if a valid path is present or not in the map. If at the end, the map only contains walls it means that a valid path was found.
# graphic management
With MiniLibx, I can display and manage a window as well as perform keyboard and mouse interactions.
# game management
The player can move in four directions (up, down, right and left) thanks to the w, s, a and d keyboard letters.
