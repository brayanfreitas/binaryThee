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
void deleteElement(Three &a)
{
  Three aux = new Data;
  if (a != NULL)
  {
    if (!a->right)
    {
      a = a->left;
    }
    else if (!a->left)
    {
      a = a->right;
    }
    else
    {
      aux = a->left;
      while (aux->right != NULL)
      {
        aux = aux->right;
      }
      aux->right = a->right;

      aux = a;
      a = a->left;
    }
    delete aux;
  }
}

void findAndDeleteElement(Three &a, char element)
{
  Three node = a;
  Three prev = new Data;
  while (node != NULL)
  {
    if (node->value == element)
    {
      break;
    }
    prev = node;
    if (element < node->value)
    {
      node = node->left;
    }
    else
    {
      node = node->right;
    }
  }
  if (node != NULL && node->value == element)
  {
    if (node == a)
    {
      deleteElement(a);
    }
    else if (prev->left == node)
    {
      deleteElement(prev->left);
    }
    else
    {
      deleteElement(prev->right);
    }
  }
  else if (a != NULL)
  {
    cout << "Element " << element << "is not in the three";
  }
  else
  {
    cout << "Three is empty";
  }
}

int countNode(Three a)
{

  if (a == NULL)
    return 0;
  return (1 + countNode(a->left) + countNode(a->right));
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
  showElements(a);

  findAndDeleteElement(a, 'h');

  showElements(a);

  return 0;
}