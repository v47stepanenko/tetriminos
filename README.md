# tetriminos

Program that assembles given Tetrimino set:

...#  ....  .###  ....
...#  ....  ...#  ..##
...#  ....  ....  .##.
...#  ####  ....  .... 

....  ....  ##..  ....
.##.  ....  .#..  ###.
.##.  ##..  .#..  .#..
....  .##.  ....  ....


and arranges every Tetrimino with each others in order to make
the smallest possible square:

ABBBB.
ACCCEE
AFFCEE
A.FFGG
HHHDDG
.HDD.G

To launch:

make
./fillit tetriminos/valid_tetriminos.txt
