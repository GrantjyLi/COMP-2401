#include<stdio.h>
#include<string.h>

// This is a forward reference
int palindrome(char *s);

int main() {

  char word[30];

    
  printf ("Enter a word or \"q\" to stop: ");
  scanf ("%s", word);

  while (strcmp(word, "q") != 0) {
    palindrome(word);
    printf ("Enter a word or \"q\" to stop: ");
    scanf ("%s", word);
  };

  return 0;

}
  
int palindrome(char *s)
{
  //for loop to loop through string name
  for (int i=0; i<strlen(s)/2; i++){

    //checking if each index is the same as its opposite index from the middle of the string
    if(s[i] != s[strlen(s) - i - 1]){

      //printing message if not a palindrome;
      printf("\"%s\" is not a palindrome\n", s);
      return 1;
    }
  }
  //printing message if palindrome;
  printf("\"%s\" is a palindrome\n", s);
  return 0;
}
