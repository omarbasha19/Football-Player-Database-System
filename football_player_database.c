#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct player {
    char name[50];
    char nationality[50];
    int age;
    char position[50];
    char current_club[50];
    int goals_scored;
    int t_shirt_number;
};

struct player players[100];
int player_count = 0;

void add_player();
void search_player();
void display_players();

int main() {
    int choice;
    while (1) {
        printf("\nFootball Player Database\n");
        printf("1. Add new player\n");
        printf("2. Search player by name\n");
        printf("3. Display all players\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_player();
                break;
            case 2:
                search_player();
                break;
            case 3:
                display_players();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

void add_player() {
    struct player new_player;
    printf("Enter player's name: ");
    scanf("%s", new_player.name);
    printf("Enter player's nationality: ");
    scanf("%s", new_player.nationality);
    printf("Enter player's age: ");
    scanf("%d", &new_player.age);
    printf("Enter player's position: ");
    scanf("%s", new_player.position);
    printf("Enter player's current club: ");
    scanf("%s", new_player.current_club);
    printf("Enter number of goals scored: ");
    scanf("%d", &new_player.goals_scored);
    printf("Enter player's t-shirt number: ");
    scanf("%d", &new_player.t_shirt_number);

    players[player_count] = new_player;
    player_count++;
    printf("Player added successfully!\n");
}

void search_player() {
    char name[50];
    int i, found = 0;
    printf("Enter the name of the player you want to search for: ");
    scanf("%s", name);

    for (i = 0; i < player_count; i++) {
        if (strcmp(name, players[i].name) == 0) {
            printf("Name: %s\n", players[i].name);
            printf("Nationality: %s\n", players[i].nationality);
            printf("Age: %d\n", players[i].age);
            printf("Position: %s\n", players[i].position);
            printf("Current club: %s\n", players[i].current_club);
            printf("Goals scored: %d\n", players[i].goals_scored);
            printf("T-shirt number: %d\n", players[i].t_shirt_number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Player not found in the database\n");
    }
}

void display_players() {
    int i;
    if (player_count == 0) {
        printf("No players in the database\n");
    } else {
        for (i = 0; i < player_count; i++) {
            printf("Name: %s\n", players[i].name);
            printf("Nationality: %s\n", players[i].nationality);
            printf("Age: %d\n", players[i].age);
            printf("Position: %s\n", players[i].position);
            printf("Current club: %s\n", players[i].current_club);
            printf("Goals scored: %d\n", players[i].goals_scored);
            printf("T-shirt number: %d\n", players[i].t_shirt_number);
        }
    }
}
