#include <iostream>

using namespace std;

struct Data
{
  Data *right;
  char value;
  Data *left;
};

typedef Data *Three;

void insert(Three &a, char element)
{
  if (a == NULL)
  {
    a = new Data;
    a->value = element;
    a->right = NULL;
    a->left = NULL;
  }
  else if (element < a->value)
  {
    insert(a->left, element);
  }
  else if (element > a->value)
  {
    insert(a->right, element);
  }
  else
  {
    cout << "Error: the element alreaty exist in the three";
  }
}

void showElements(Three &a)
{
  if (a != NULL)
  {
    showElements(a->left);
    cout << a->value << "  ";
    showElements(a->right);
  }
}

void showThree(Three &a, int init)

{
  if (a)
  {
    showThree(a->right, init + 1);
    for (int i = 0; i < init; i++)
      cout << "   ";
    cout << a->value << endl;
    showThree(a->left, init + 1);
  }
}

void inicialize(Three &a)
{
  a = NULL;
}

int main(void)
{
  Three a = new Data;
  inicialize(a);

  insert(a, 'c');
  insert(a, 'i');
  insert(a, 'h');
  insert(a, 'p');
  insert(a, 'o');
  showThree(a, 0);
  showElements(a);

  return 0;
}
