# POO2 2020 - Labo 04 -Buffy

*Authors: Walther Simon, Moreno Andres*

##### Implementation choices:

The *fill* class is in charge of managing the game. In order to be able to quickly compare each class we created roles for the humanoids (HumanType, BuffyType and VampireType).  We decided to implement a class *Action* in order to define all types of possible action the humanoides can have. We divided it in two, Attack actions and movement acctions. Althought in this particular case Buffy presents the same attack actions as the vampires we've decided to keep a BuffyAttackAction class specially for buffy in case we decide to modify her behavior in the future.  For the generation of random numbers we select an uniform distribution.



**Example of interaction:**

The game can be run in two diferent modes, statics only or with the board. In case we decided to only do stats we need to set the grid size, number of vampires and  number of humans. 

```c++
Width Height nbVampires nbHumans: 
10 10 5 10 
stats mode? y/n
y
Calculating..
simulation % : 19.45
```

if we decide to play the game without stats we simply enter 'n' and the grid will be displayed

```c++
Width Height nbVampires nbHumans: 
10 10 5 10
stats mode? y/n
n

+---------------------+
|           h         |
|                     |
|         h           |
|             h       |
|   h       v v       |
|       v v           |
|             h h     |
| h         v h       |
|           h         |
|   B       h         |
+---------------------+
[0] q)quit s)statistics n)nextTurn: 
```

if we are executing the program with the displayed grid and we decide to have the statistics we simply need to press 's'. The game will automaticaly take the same parameters as initial state of the game and run the stats. Once the stats are calculated the game will resume. 

```c++
Width Height nbVampires nbHumans: 
10 10 5 10
stats mode? y/n
n

+---------------------+
|           h         |
|                     |
|         h           |
|             h       |
|   h       v v       |
|       v v           |
|             h h     |
| h         v h       |
|           h         |
|   B       h         |
+---------------------+
[0] q)quit s)statistics n)nextTurn: s
Calculating stats...
simulation % : 20.05
+---------------------+
|           h         |
|                     |
|         h           |
|             h       |
|   h       v v       |
|       v v           |
|             h h     |
| h         v h       |
|           h         |
|   B       h         |
+---------------------+
[0] q)quit s)statistics n)nextTurn: 
```



Succes rate of Buffy with the following initial conditions : grid 50x50, 10 vampires and 20 humans

```c++
Width Height nbVampires nbHumans: 
50 50 10 20
stats mode? y/n
y
Calculating..
simulation % : 46.88
```



*Annexes*
classes diagram (UML)

