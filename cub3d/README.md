# cub3D

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

# usage

Enter the directory and make
```
cd cub3d
make
```
Execute the program
```
./cub3d map.cub
```

You can move with the keys w, a, s, d and rotate left and right with the arrowkeyes.

 The "map.cub" file contains data upon which the execution depends. For example, you can change the color of the floor and ceiling by modifying the RGB color code. Additionally, you can modify the map at the bottom of the file. The player in this map is represented by one of the letters: N, E, W, S, which also indicate the direction in which the player will spawn when starting the program. The maze can also be changed, but ensure it's surrounded by '1', indicating walls, or the program will throw an error.
