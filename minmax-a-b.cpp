//this is where the difficulty happens
//this should probably be a method in twoplayer for simplicity
//but for now bc its such a big portion of this project it has its own file

//notes: I dont entire understand how UT helps the control flow
//you might want to revise this sudo code if I got that part wrong

//void minmax-a-b(position, depth, player, passthresh, usethresh, eval) {}
//bc all minmax-a-b does is update the boardstate it doesnt need to return anything
//position: which node is currently being evaluated,
//          because each node is a boardstate, this variable probably needs to be an array
//depth: how far away from the current boardstate the function is
//      starts at 0 when called, recursion adds 1, stop at depth of 2
//player: this helps decide if the child generator should be playing as X or O
//        also important for comparisons
//passthresh(PT): struct pointer, starts with an initialized value thats super low
//          gets updated at d=1 by values of nodes at d=2
//          value compaired to UT after all d=2 nodes of this d=1 node are checked
//usethresh(UT): starts with an initialized value thats super low
//          gets updated... I think?
//eval: objects of class type eval, used to determine value of d=2 nodes

//step 1: check depth value to see if its time to stop,
//        if d=2, run eval function, return value & path (see vp.h)
//step 2: fill a stack with position arrays for each possible board state branching off from this one
//        remember to do so from the player's perspective
//        if no children can be generated, return value & path for this node
//step 3: recursively call this function for each position array on the stack
//        tempStruct = minmax-a-b(child, d+1, opposite player, negative PT, negative UT, eval)
//        if tempStruct.value > PT.value, then set PT to tempStruct
//        once the stack is empty compare PT to UT
//        if PT is larger than UT, return PT otherwise ignore branch
//step 4: if you havent returned a value yet, return PT
