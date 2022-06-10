# These codes outputs the row-reduced form a matrix
**rank.c** requires number of rows and columns as macros definations while **rank2.c** needs these inputs as cmd line args. 
**rank2.c** is my first shot at working with 2D arrays completely via pointers which required great deal of carfulness and imagination.

### rank.c
Change marcos definations of *row* and *clmn* to work with the required matrix. </br >
Compile and run:
> gcc rank.c -o rank
> rank.c
Input the matrix elements. Irrespective of the way you input them, the code takes first 'row' number of elements as inputs for first row, second 'row' number of elements as second and so on. </br >
Upon entering *row* x *clmn* number of elements, the row reducesd form is printed to the terminal.
