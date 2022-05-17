#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    char str[12];
    unsigned int fst = 0, scd = 0, pre_dig, post_dig, pre_fact, post_fact, op_index;
    int result, i;

    system("color 1e");

    printf("Dear user:\n\t This program working with positive decimal integer numbers only\n");
    printf("\t If you enter number > 5 digits, I'll ignore the above five\n");
    printf("\t If you enter null, I'll consider it Zero\n");
    printf("\t So, Take care to get the correct result\n\n");

    printf("Please Enter Eq: ");
    scanf("%[^\n]s",str);

    for(i = 0; ; i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            op_index = i;
            break;
        }

    }
    pre_dig = i;

    for(i = pre_dig + 1; ; i++)
    {
        if(str[i] == '\0') break;
    }
    post_dig = i - (pre_dig + 1);


    if(pre_dig > 1 )
    {
        pre_fact = pow(10,(pre_dig-1));
        if((pre_fact % 10) != 0 && pre_dig > 1) pre_fact++;
        if(pre_fact > 10000) pre_fact = 10000;
    }
    else pre_fact = pre_dig;

    if(post_dig > 1)
    {
        post_fact = pow(10,(post_dig-1));
        if((post_fact % 10) != 0 && post_dig > 1) post_fact++;
        if(post_fact > 10000) post_fact = 10000;
    }
    else post_fact = post_dig;


    for(i = 0; i < 5 || i < op_index; i++)
    {
        fst += (str[i] - '0') * pre_fact;
        pre_fact /= 10;
    }


    for(i = op_index + 1; i < op_index + 6; i++)
    {
        scd += (str[i] - '0') * post_fact;
        post_fact /= 10;
    }


    switch(str[op_index])
    {
        case '+': result = fst + scd; break;
        case '-': result = fst - scd; break;
        case '*': result = fst * scd; break;
        case '/':
            if(scd > 0 || scd < 0) result = fst / scd;
            else if (scd == 0)
            {
                printf("Divided by Zero\n");
                exit(1);
            }
            break;
        default: printf("Invalid operation\n"); exit(2);
    }

    printf("Result = %d\n",result);
    return 0;
}
