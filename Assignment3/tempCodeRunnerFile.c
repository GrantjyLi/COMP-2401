char *input;
    printf("Enter the name of your chosen pokemon: ");
    scanf("%m[^\n]", &input);

    //if found:
    realloc(pokeDeck, deckSize * sizeof(Pokemon));


    free(input);