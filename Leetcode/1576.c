char* modifyString(char* s) {
    // achar os ?
    // remover por caracteres
    int t = strlen(s);
    int contador = 2;
    for(int i = 0; i < t; i++)
    {
        if(s[i] == '?')
        {
            s[i] = 'a' + i;

          if(s[i] > 'z' || s[i] < 'a')
                if(contador % 2 == 0)
                {
                    s[i] = 'a';
                    contador--;
                }
                else if(contador % 2 != 0)
                {
                    s[i] = 'b';
                    contador++;            
                }  

            if(i > 0 && (s[i] == s[i-1]))
            {
                s[i] = 'e';

                if(s[i] == s[i+1])
                {
                    s[i] = 'z';
                }
                
            }

            if(s[i] == s[i+1])
            {
                s[i] = 'p';

                if(i > 0 && s[i] == s[i-1])
                {
                    s[i] = 'e';
                }
                
            }
            
      


        }
    }

    return s;
}