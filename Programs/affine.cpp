// Affine Cipher C Program 
#include <stdio.h>
#include <string.h>
int main()
{
            char str[30];
            int keym,keya,i;
            printf("Enter plaintext\n");
            scanf("%s",str);
            int len=strlen(str);
            printf("Enter the additive key\n");
            scanf("%d",&keya);
printf("Enter the multiplicative key\n");
            scanf("%d",&keym);
            for(i=0;i<len;i++)
            {
                        int t = str[i]-'a';
                        t=(t*keym+keya);
                        t=t%26;
                        str[i]=(char)(t+'a');
            }
            printf("Cipher Text is \n%s\n",str);
            return 0;
}
