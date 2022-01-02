#include <stdio.h>
#include <string.h>

#include "util.h"

int cmp(char input[], char check[]) {
  int i, result = 1;
  for ( i = 0; input[i] != '\0' || check[i] != '\0'; i++ ) {
    if ( input[i] != check[i] ) {
      result = 0;
      break;
    }
  }
  return result;
}

int cmpfirst(char input[], char check[]) {
  int i, result = 1;
  for ( i = 0; input[i] != '\0' || check[i] != '\0'; i++ ) {
    if ( input[i] != check[i] ) {
      result = 0;
      break;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {

  char cwd[50];
  strcpy(cwd, argv[1]);

  if ( cmp(cwd, "/root") )
    strcpy(cwd, "%B%F{3}~");
  else if ( strncmp("/root/", cwd, 6) == 0 )
    strcpy(cwd, "inroot");
  else {
    char sources[50][500] = {
        "/mega/repo/wiki",
        "/root/scripts",
        "/root/stow-dotfiles",
        "/root/.config/nvim",
        "/projects/c/master",
        "/projects/c/get_cwd",
        "/projects/c/ecart_type",
    };
    for ( int i = 0; i < 50 && strcmp("", sources[i]) != 0; i++ ) {
      // TODO: project is basename of sources[i]
      char project[500] = "tttttttt";
      // lastname is ""${cwd##${s}/}"
      char lastname[500] = "kkkk";
      if ( strcmp(cwd, sources[i]) == 0 ) {
        strcpy(cwd, "");
        strcat(strcat(strcat(cwd, "%B%F{3}"), project), " %B%F{1}>%B%F{2}>%B%F{3}>");
      } else if ( strncmp(sources[i], cwd, strlen(sources[i])) == 0 ) {
        strcpy(cwd, "");
        strcpy(cwd, strcat(strcat(strcat(strcat(strcat(cwd,"%B%F{3}"), project), ":%B%F{7}"), lastname), " %B%F{1}>%B%F{2}>%B%F{3}>"));
      }
    }
  }
  printf("%s\n", cwd);

  return 0;
}
