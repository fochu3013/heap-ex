#include <iostream>
#include <vector>
using namespace std;
//metodo swap troca os valores entre A e B
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
// metodo heapfy é utilizado para criar a estrutura heap a partir de uma arvore binaria 
void heapify(vector<int> &hT, int i)
{
  int size = hT.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  if (largest != i)
  {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}
//metodo insert utilizado para adicionar elementos dentro de uma estrutura vector
void insert(vector<int> &hT, int newNum)
{
  int size = hT.size();
  if (size == 0)
  {
    hT.push_back(newNum);
  }
  else
  {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(hT, i);
    }
  }
}
// delete node e o metodo utilizado para remover um elemento da estrutura heap
void deleteNode(vector<int> &hT, int num)
{
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(hT, i);
  }
}
void printArray(vector<int> &hT)
{
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main()
{
  vector<int> heapTree;

  int quantidadeNumeros = 500;
  
  for(int i=0; i < quantidadeNumeros; i++) {
    insert(heapTree, rand() % 700);
  }

  cout << "Max-Heap array: ";
  printArray(heapTree);

  deleteNode(heapTree,1);

  cout << "After deleting an element: ";

  printArray(heapTree);
}
