//contains a class called Board 
//VARIABLE:
//ttt: an array variable that holds strings, "", "X", "O"
//the indexs themselves arent natively in magic square form to make it easier to print
//METHODS:
//add(index, string): puts the value representing either an X or an O into the array at a given position, returns T/F
//reset: cleans the board, setting every value to empty, void
//print: generates a visual of the current board state
//magic(array pointer): fills the passed array with the values of ttt
//      as they correspond to the magic square (lines add to 12)
//      for use with eval functions & goal method
//      doesnt necessarily need to remain a string array
//goal: checks if the board has reached a terminal state, returning T/F
//winner: this is whats called to check board state, checks if goal reached
//        if goal is reached, this returns who won, X or O