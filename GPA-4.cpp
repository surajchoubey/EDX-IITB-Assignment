/*

Graded Programming Assignment 4 (STL)
You are the manager of the casino CS101.1x Royale. You have a very weird game in your casino, rules for which are

1) N players start the game with money m1,m2,m3….mN  respectively where mi > 0 for all i

2) All players play all turns

3) If a player wins a turn he/she get   W,

4) If a player loses a turn he/she loses 1

5) You have a no losers policy so if a turn is being played and a player has 0 at the start of the turn, he/she is declared a default winner and gets W at the end of that turn

6) Any number of players can win a turn from 0 to N

7) The game ends when all except 1 player have 0

8) There is no upper bound on the number of turns that can be played


Your job is to find out if the game can ever end (number of turns does not matter).

Here is an example with N=2 and W=2 and player 1 starts with 6 and player 2 with 5

Player 1

Player 2

Start money

6

5

Result of round 1

Win

Lose

Money after round 1

8

4

Result of round 2

Win

Lose

Money after round 2

10

3

Result of round 3

Win

Lose

Money after round 3

12

2

Result of round 4

Win

Lose

Money after round 4

14

1

Result of round 5

Win

Lose

Money after round 5

16

0

The game ends after round 5 since all except player 1 have 0

Here is another example with N = 3 and W = 2 and P1 starts with 2, P2 with 2 and P3 with 4

Player 1

Player 2

Player3

Start money

2

2

4

Result of round 1

Lose

Lose

Win

Money after round 1

1

1

6

Result of round 2

Win

Win

Lose

Money after round 2

3

3

5

Result of round 3

Lose

Lose

Lose

Money after round 3

2

2

4

Result of round 4

Lose

Lose

Lose

Money after round 4

1

1

3

Result of round 5

Lose

Lose

Lose

Money after round 5

0

0

2

The game ends after round 5 since all except player3 have 0

One case where the game won't end is when N = 3, W = 2, P1 starts with 1, P2 with 2 and P3 with 3 (You can check this by manually trying)

Function: void royale(int N, int W, vector<int> &money, bool &flag)

Variable N contains number of players, variable W is the winning amount, and vector money contains m1,m2,m3….mN., and variable 'flag'. 

You are required to complete the code to determine whether the game will end or not? You are required to :

1) Set value of variable 'flag' to true if game ends or set to false in case when game doesn't end.


Sample inputs with their outputs


Input1:

N=2 W=2 money={6,5}

output1:

YES

input2:

N=3 W=2 money={2 ,2, 4}

output2:

YES

input3:

N=3 W=2 money={1, 2, 3}

output3:

NO 

Note: the output only contains the string “YES”, If the game can end or “NO” if it cannot end.

Some constraints on inputs are 
1<N<=100

1<W<=10

0<mi<300

*/
