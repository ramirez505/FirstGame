#include "../headers/dev.h"

void dev_manager(int argc, char *argv[], GameObject *G)
{
  // flags extraction
  char flags[20][30];
  int flagCount = 1;
  int charCount = 0;
  int charIndex = 4;
  while (argv[1][charIndex] != '\0')
  {
    if (argv[1][charIndex] == '-')
    {
      flags[flagCount - 1][charCount] = '\0';
      flagCount++;
      charCount = 0;
    }
    else
    {
      flags[flagCount - 1][charCount] = argv[1][charIndex];
      charCount++;
    }

    charIndex++;
  }
  flags[flagCount - 1][charCount] = '\0';

  // flags redirection
  for (int i = 0; i < flagCount; i++)
  {
    if (strcmp(flags[i], "fps") == 0)
      displayFPS();
    if (strcmp(flags[i], "full_screen") == 0)
      set_fullScreen(&(G->window));
  }
}