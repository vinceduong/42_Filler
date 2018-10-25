### 42_Filler
42 Project - Code a player fighting on a VM !

Filler is game where two players need to cover a map with pieces given by a virtual machine.

The VM calls the players alternatively and gives each a random piece, the player has to give the coordonates for his piece on the standard input.

The first player who cannot place his piece loses.

##### You can find more details in the subject !

#### My Player

vduong.filler is the player i created, his strategy consists of going the closest possible to the enemy and surround him.

For each turn, my player will list the possibles coordonates i can use for my piece placement, then he will assign them the distance to the enemy  and sort them.
The coordonate whith the closest distance to the enemy will be printed of the standard input.

#### Compile the player
```
make
```
#### Launch
Command format :

```
./filler_vm -f [map_path] -p1 ./[player1_path] -p2 ./[player2_path]
```
example :
```
./filler_vm -f maps/map01 -p1 ./vduong.filler -p2 ./players/hcao.filler
