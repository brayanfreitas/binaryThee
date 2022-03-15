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

void inicialize(Three &a)
{
  a = NULL;
}

int main(void)
{
  return 0;
}