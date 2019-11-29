#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 9
int allvotes[MAX];
//---------------------------------------------------------------------------
typedef struct
{
    int vote;
    char name[100];
}candidate;
candidate candidates[MAX];// define total amount of candidate outside
//---------------------------------------------------------------------------
int main (int argc, char*argv[])
{
    //error check 1
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    //declaring total num of cadidates//error check
    int candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    //--------------------------------------------------------------------
    for (int i = 0; i < argc - 1; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].vote = 0;
    }
    //----------------------------------------------------------------------
    int voters_count;
    printf("Number of voters: ");
    scanf("%d", &voters_count);
    // Loop over all voters
    for (int i = 0; i < voters_count; i++)
    {
        char tempforvote[100];
        printf("Vote: ");
        scanf("%s", tempforvote);
        int checkinput = 0;

        //loop for checking who gets the vote
        for (int o = 0; o < candidate_count; o++)
        {
            if (strcmp(candidates[o].name, tempforvote) == 0)
                candidates[o].vote++;
            else
                checkinput++;
        }

        if (checkinput == candidate_count)
        {
            printf("Incorrect candidate, please reenter\n");
            i--;
        }
    }
    for (int q = 0; q != candidate_count; q++)
    {
        allvotes[q] = candidates[q].vote;
    }

//sort
    for (int i = 1; candidate_count != i ; i++) //n
        for (int k = 0; k != candidate_count - i; k++) //squared(times n)
        {
            int tempswap = 0;
            if (allvotes[k] > allvotes[k+1])
            {
                tempswap = allvotes[k];
                allvotes[k] = allvotes[k+1];
                allvotes[k+1] = tempswap;
            }
        }
    int mostvotes = allvotes[candidate_count - 1]; //minus one because array starts from 0, remember?

    printf("Winners:");
    //winners int for deciding , or .
    int winners = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (mostvotes == candidates[i].vote)
        {
            winners++;
        }
    }
    //same loop, but this time prints winner(s)
    for (int i = 0; i < candidate_count; i++)
    {
        if (mostvotes == candidates[i].vote)
        {
            static int winnercheck = 0;
            winnercheck++;
            printf(" %s", candidates[i].name);
            if (winnercheck < winners)
                printf(",");
            else
                printf(".");
        }
    }
    printf("\n");
    return 0;
}

