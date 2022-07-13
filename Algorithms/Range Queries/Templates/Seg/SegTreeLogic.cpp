int sum(int a, int b) {
    a += n; b += n;
    //you first increase the values by n so you are at the original array-- everything before 
    //takes some sum after
    int s = 0;
    while (a <= b) {
        //for a -> b
    	//if it's a right node, then you can simply add this node
    	//because you don't want to look at its parent
    	//you don't need the sum of its left and right node
    	//since you only want from that right node -> to the left endpoint
    	//by incrementing a, you move over one node and ensure
    	//that you take the parent of the next node, which you need 
    	//(you're going from [a,b], so if a is a right node you can add and continue)
    	//you also ensure that if the node is even, you keep on moving 
    	//up the tree to get the uppermost node for the sum
    	//if it ever becomes right you can just add the node you are at in the tree
    	//and skip the the next node again, repeating the cycle
    	//a <= b ensures that there's no spillover between nodes
    	//same process for b -> a, except opposite parity of node
       if (a%2 == 1) s += tree[a++];
       if (b%2 == 0) s += tree[b--];
       a /= 2; b /= 2;
    }
    return s; 
}