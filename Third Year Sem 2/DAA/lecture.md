# DAA Lecture Notes

## Lecture 11

## Traveling Salesman Problem

    Given a set of cities and distances between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.

### Solve TSP using Branch & Bound

M = {

    [INF,20,30,10,11],
    [15,INF,16,4,2],
    [3,5,INF,2,4],
    [19, 6, 18, INF, 3],
    [18,4,7,16,INF]

}

MIN ROW values = [10,2,2,3,4]

reducing the matrix

M = {

    [INF,10,20,0,1],
    [13,INF,14,2,0],
    [1,3,INF,0,2],
    [16, 3, 15, INF, 0],
    [13,0,3,12,INF]

}

MIN Colum values = [1,0,3,0,0]

M = {

    [INF,10 ,17 ,0  ,  1],
    [12 ,INF,11 ,2  ,  0],
    [0  , 3 ,INF,0  ,  2],
    [15 , 3 ,12 ,INF,  0],
    [11 , 0 , 0 ,12 ,INF]

}

consider path 1-2 make 1st row & 2nd column INF

    that is m[2][1] = INF

M = {

    [INF,INF,INF,INF,INF],
    [INF,INF,11 ,2  ,  0],
    [0  ,INF,INF,0  ,  2],
    [15 ,INF,12 ,INF,  0],
    [11 ,INF, 0 ,12 ,INF]

}

val = 25 + 0 + 10 = 35

consider path 1-3 make 1st row & 2nd column INF

    that is m[3][1] = INF

M = {

    [INF,INF,INF,INF,INF],
    [12 ,INF,INF,2  ,  0],
    [INF, 3 ,INF,0  ,  2],
    [15 , 3 ,INF,INF,  0],
    [11 , 0 ,INF,12 ,INF]

}

val = 25 + 11 + 17 = 53

consider path 1-4 make 1st row & 2nd column INF

    that is m[4][1] = INF

M = {

    [INF,INF,INF,INF,INF],
    [12 ,INF,11 ,INF,  0],
    [0  , 3 ,INF,INF,  2],
    [INF, 3 ,12 ,INF,  0],
    [11 , 0 , 0 ,INF,INF]

}

val = 25

consider path 1-5 make 1st row & 2nd column INF

    that is m[5][1] = INF

M = {

    [INF,INF,INF,INF,INF],
    [12 ,INF,11 ,2  ,INF],
    [0  , 3 ,INF,0  ,INF],
    [15 , 3 ,12 ,INF,INF],
    [INF, 0 , 0 ,12 ,INF]

}

val = 25 + 2 + 3 + 1 = 31

consider path 1-4-2 as infinity

M = {

    [INF,INF,INF,INF,INF],
    [INF,INF,11 ,2  ,  0],
    [0  ,INF,INF,0  ,  2],
    [INF,INF,INF,INF,INF],
    [11 ,INF, 0 ,INF,INF]

}

val = 25 + 0 + 3 = 28

consider path 1-4-3 as infinity

M = {

    [INF,INF,INF,INF,INF],
    [12 ,3  ,11 ,2  ,  0],
    [INF,INF,INF,0  ,  2],
    [INF,0  ,INF,INF,INF],
    [11 ,INF, 0 ,12 ,INF]

}

val = 25 + 11 + 12 = 48

consider path 1-4-5 as infinity

M = {

    [INF,INF,INF,INF,INF],
    [12 ,INF,11 ,2  ,INF],
    [0  , 3 ,INF,0  ,INF],
    [INF,INF,INF,INF,INF],
    [INF, 0 , 0 ,12 ,INF]

}

val = 27

consider path 1-4-5-2

M = {

    [INF,INF,INF,INF,INF],
    [12 ,INF,11 ,INF,INF],
    [0  ,INF,INF,INF,INF],
    [INF,INF,INF,INF,INF],
    [INF,INF,INF,INF,INF]

}

val = 22 + 25 = 47

consider path 1-4-5-3

M = {

    [INF,INF,INF,INF,INF],
    [12 ,INF,INF,INF,INF],
    [INF,3  ,INF,INF,INF],
    [INF,INF,INF,INF,INF],
    [INF,INF,INF,INF,INF]

}

val = 22 + 15 = 40

consider path 1-4-5-3-2

M = {

    [INF,INF,INF,INF,INF],
    [INF,INF,INF,INF,INF],
    [INF,INF,INF,INF,INF],
    [INF,INF,INF,INF,INF],
    [INF,INF,INF,INF,INF]

}

val = 25 + 3 = 28

Final **Tree**

![Img 1](./Images/treenew.png)
