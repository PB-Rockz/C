#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct player_rec
{
    char name[20];
    int age;
    int no_of_matches;
    float avg_run[100];
};
struct player_rec player[20];
int compareByRuns(const void *a, const void *b)
{
    const struct player_rec *cricketerA = (const struct player_rec *)a;
    const struct player_rec *cricketerB = (const struct player_rec *)b;

    // Compare by average runs
    if (cricketerA->avg_run < cricketerB->avg_run)
        return -1;
    if (cricketerA->avg_run > cricketerB->avg_run)
        return 1;

    return 0;
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the Name of Player: ");
        scanf("%s", player[i].name);

        printf("Enter the Age of Player: ");
        scanf("%d", &player[i].age);

        printf("Enter total number of matches of Player(not more than 100): ");
        scanf("%d", &player[i].no_of_matches);

        printf("Enter average runs for match : ");
        scanf("%f", &player[i].avg_run);
    }

    qsort(player, 20, sizeof(struct player_rec), compareByRuns);

    printf("\nCricketer records sorted by average runs:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("Name: %s, Age: %d, Matches Played: %d, Average Runs: %.2f\n",
               player[i].name, player[i].age, player[i].no_of_matches, player[i].avg_run);
    }
    return 0;
}
