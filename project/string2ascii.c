#include <stdio.h>
void print(char *s){
  for (int i = 0; s[i] != '\0';i++){
    printf("%x ", s[i]);
  }
}
int main(){
  char *s = "747c9c5e";
  print(s);
  return 0;
}