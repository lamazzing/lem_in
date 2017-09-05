# lem_in
This program was made for a project in Ecole 42. The problem to be solved was the following: 
"You must move your ant colony from one point to another in the least amount of time". 
This program takes as input a map of an ant colony in the form os a list of rooms and links between those rooms. 
The goal is to move ants from the source room to the sink room, and do it in the minimum number of turns possible, 
knowing that an ant can only move once per turn and that at any given time there can only be one ant per room 
(except for the source and the sink, where there can be as many ants as needed).

The map must be in the following format:

#comment   -> comment  
10          -> number of ants  
a 0 0       -> definition of a room, room name (the names can be assigned randomly) followed by the coordinates  
b 0 0  
##start     -> the next room defined will be the source  
start 0 0  
##end       -> the next room defined will be the end  
end 0 0  
start-a     -> definition of a link between rooms  
a-b  
b-end  
(I ignore the coordinates of the rooms that can be used in conjunction with a visual program)  

The output is:  
L1-a  
L1-b L2-a  
L1-end L2-b L3-a  
L2-end L3-b L4-a  
L3-end L4-b L5-a  
L4-end L5-b L6-a  
L5-end L6-b L7-a  
L6-end L7-b L8-a  
L7-end L8-b L9-a  
L8-end L9-b L10-a  
L9-end L10-b  
L10-end  

In the format "Ln-name", Ln is the number of the ant that is moving and name is the room name to which the ant goes.
Each line corresponds to one turn.  

In order to find the best solution I first determine the distance of each room from the end.
I then re-order the links for each room by putting first the links that lead to shortest paths.
I get the minimum between the # of links in the starting room and the # of links in the finishing room to know what is the max number of unique paths.
The optimal solution is found by comparing each set of unique solutions, for example:  

If I have 3 unique paths, I find the best solution using one path, then the best solution using 2 path and the best solution using 3 paths.
By considering the number of ants I then decide which set is the fastest, and  write of the exit the movements that the ants have to do each turn.  
You can check in the folder maps the example1 file to understand better how the algorithm choses the paths.  
All functions are commented.

usage:
```
$ ./lem-in < map_file
```
