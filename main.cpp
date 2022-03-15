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

Three rotateThreeRight(Three grandFather)
{
  Three parent;
  Three child;

  if ((grandFather == NULL) || (grandFather->left == NULL))
  {
    return grandFather;
  }

  parent = grandFather->left;
  child = parent->right;
  parent->right = grandFather;
  grandFather->left = child;
  return parent;
}

Three makeBackBone(Three grandParent)
{
  Three p, r;
  r = new Data;
  r->left = NULL;
  r->right = grandParent;
  p = r;

  while (p->right)
  {
    if (p->right->left == NULL)
    {
      p = p->right;
    }
    else
    {
      p->right = rotateThreeRight(p->right);
    }
  }
  return r;
}

Three rotateThreeLeft(Three grandParent)
{
  Three parent, child;

  if ((grandParent == NULL) || (grandParent->right == NULL))
  {
    return grandParent;
  }
  parent = grandParent->right;
  child = parent->left;
  parent->left = grandParent;
  grandParent->right = child;
  return parent;
}

Three rotate(Three grandParent, int count)
{
  Three p;

  p = grandParent;
  while (count)
  {
    p->right = rotateThreeLeft(p->right);
    p = p->right;
    --count;
  }
  return grandParent;
}

Three rebalance(Three a)
{
  int n, t, l, lc;
  n = countNode(a);

  // log2(n+1)
  t = n + 1;
  l = 0;
  while (t > 1)
  {
    ++l;
    t /= 2;
  }

  lc = n + 1 - (1 << l);
  if (lc == 0)
    lc = (1 << (l - 1));
  a = rotate(a, lc);

  n -= lc;
  while (n > 1)
  {
    n /= 2;
    a = rotate(a, n);
  }

  return a;
}

int main(void)
{
  Three a = new Data;
  inicialize(a);

  insert(a, 'f');
  insert(a, 'g');
  insert(a, 'l');
  insert(a, 't');
  insert(a, 'u');

  a = makeBackBone(a);
  showThree(a, 0);
  a = rebalance(a);
  showThree(a, 0);

  // indAndDeleteElement(a, 'h');

  return 0;
}