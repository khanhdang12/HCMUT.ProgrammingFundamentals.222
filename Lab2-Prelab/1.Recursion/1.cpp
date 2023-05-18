int gcdRecursion(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    // TODO
    if (q == 0) {
        return p;
    }
    else {
        return gcdRecursion(q, p % q);
    }
    // END YOUR EMPLEMENTATION [1]
}
int gcdIteration(int p, int q)
{
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
    int temp;
    while (q != 0) 
    {
        temp = p % q;
        p = q;
        q = temp;
    }
    return p;
    // END YOUR EMPLEMENTATION [2]
}