char findTheDifference(char* s, char* t) {

    int tamanhoS = strlen(s);
    int amanhoT = strlen(t);
    for(int i = 0; i <tamanhoS; i++)
    {
        for(int j = 0; j < amanhoT; j++)
        {
            if(t[j] == s[i])
            {
                s[i] = '#';
                t[j] = '#';
                break;
            }
                
        }
    }

    char r;
    for(int i = 0; i < amanhoT; i++)
    {
        if(t[i] != '#')
            return t[i];
    }

    return 1;

}