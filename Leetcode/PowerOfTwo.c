bool isPowerOfTwo(int n) {

    int v = 2;
    double a = n;
    if(a == 0)
        return false;
        
    while(a != 1.0000000000000000000000)
    {
        if(a < 1 && a > 0)
            return false;
        if(a > -1 && a < 0)
            return false;
       a = a / v;
    }

    return true;
  
}
