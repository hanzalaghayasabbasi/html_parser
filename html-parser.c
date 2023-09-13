#include <stdio.h>
#include <string.h>

void parser(char *par) {
    int track = 0; // variable to track if we are inside a tag
    int index = 0;
    int prev_space = 0; // variable to track if the previous character was a space

    for (int i = 0; i < strlen(par); i++) {
        if (par[i] == '<') {
            track = 1;
            continue;
        } else if (par[i] == '>') {
            track = 0;
            continue;
        }

        if (track == 0) {
            // Only copy characters when not inside a tag
            if (!(par[i] == ' ' && prev_space)) {
                par[index] = par[i];
                index++;
            }
            prev_space = (par[i] == ' ');
        }
    }

    par[index] = '\0'; // Null-terminate the modified string

    printf("The parsed string is: %s\n", par); // Print the final parsed string
}

int main() {
    char p[] = "<p> This is p tag  with spaces </p>";
    char h1[] = "<h1> This is h1 Tag </h1>";

    parser(p);
    parser(h1);

    return 0;
}
