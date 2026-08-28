#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_winner(int user_choice_idx, int rand_num)
{
    return (user_choice_idx == rand_num) ? 0
           : (user_choice_idx == 0 && rand_num == 2) || (user_choice_idx == 1 && rand_num == 0) ||
                   (user_choice_idx == 2 && rand_num == 1)
               ? 1
               : 2;
}

int main(void)
{
    char types[3][10] = {"rock", "paper", "scissors"};
    int rand_num = rand() % 3;
    printf("Choose rock, paper, or scissors: ");
    char user_choice[10];
    scanf("%s", user_choice);
    printf("You chose: %s\n", user_choice);
    printf("Computer chose: %s\n", types[rand_num]);
    int user_choice_idx = strcmp(user_choice, types[0]) == 0   ? 0
                          : strcmp(user_choice, types[1]) == 0 ? 1
                          : strcmp(user_choice, types[2]) == 0 ? 2
                                                               : -1;
    int winner = get_winner(user_choice_idx, rand_num);
    if (winner == 0)
    {
        printf("It's a draw!\n");
    }
    else
    {
        printf("Player %d wins!\n", winner);
    }
    return 0;
}