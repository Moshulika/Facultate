#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int n = 0;
    
    scanf("%d", &n);

    
    float *p = (float*) calloc(n, sizeof(float));
    
    for(int i = 0; i < n; i++)
    {
        
        scanf("%f", p+i);
        //printf("Valoarea %d este %f\n", i, *(p+i));
    }
    
    int w = 0;
    
    scanf("%d", &w);
    
    for(int i = 0; i < n; i+=w)
    {
        
        float s = 0;
        int c = 0;
        float ma = 0;
        
        //printf("%s", "Subgrupa:");
        
        for(int z = 1; z <= w && z + i <= n; z++)
        {
            
          //printf("%f ", *(p + i + z - 1));
          s = s + *(p + i + z - 1);  
          c++;
            
        }
        
        ma = (float) ((float) s / (float) c);
        
        //printf(",suma: %d, count: %d, medie: %f ", s, c, ma);
        
        int treceri = 0;
        
        for(int z = 0; z < c; z++)
        {
            
          if(*(p + i + z) - ma < 0)
          {
              
              if(z > 0 && *(p + i + z - 1) - ma < 0) treceri--;
              
              treceri++;
          }
            
        }
        
        printf("%d\n", treceri);
        
    }
    
    return 0;
}
