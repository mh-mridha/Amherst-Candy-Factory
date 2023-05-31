#include <stdio.h>
#include <stdlib.h>

int mutex = 1;      /// Initialize a mutex to 1
int Full_Slots = 0;     /// Number of full slots
int Empty_Slots = 2, x = 0;    /// Number of empty slots as size of buffer

void Producer_func()
{
    --mutex;
    ++Full_Slots;
    --Empty_Slots;
    x++;
    printf("  Producer Produces Candy-- %d", x);

    ++mutex;
}

void Consumer_func()
{
    --mutex;
    --Full_Slots;
    ++Empty_Slots;
    printf("  Consumer Consumes Candy-- %d", x);
    x--;

    ++mutex;
}

int main()
{
    int n, i;
    printf("\n\n");
    printf("    1 >> Producer\n");
    printf("    2 >> Consumer\n");
    printf("    0 >> Exit\n");
    printf("__________________________________________________________");

    #pragma omp critical

    for (i = 1; i > 0; i++)
    {
        printf("\n\n    Your Choice: ");
        scanf("%d", &n);
        printf("\n\n");

        switch (n)
        {
        case 1:
            printf("    Producer is Chosen\n");
            if ((mutex==1)&& (Empty_Slots!=0))
            {
                Producer_func();
            }

            else
            {
                printf("\n\a    ---Buffer is Currently Full!---\n");
            }
            break;

        case 2:
            printf("    Consumer is Chosen\n");
            if ((mutex==1) && (Full_Slots!=0))
            {
                Consumer_func();
            }

            else
            {
                printf("\n\a    ---Buffer is Currently Empty!---\n");
            }
            break;

        case 0:
            exit(0);
            break;
        }
    }
}
