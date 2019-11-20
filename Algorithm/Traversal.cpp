// 이진 트리의 구현과 순회
// 비선형 자료구조
// 데이터의 탐색 속도 증진을 위해 사용하는 구조

// 1. 전위순회(Preorder Traversal)
// 1) 먼저 자기 자신을 처리
// 2) 왼쪽 자식을 방문
// 3) 오른쪽 자식을 방문

// 2. 중위 순회(Inorder Traversal)
// 1) 왼쪽 자식을 방문
// 2) 먼저 자기 자신을 방문 처리
// 3) 오른쪽 자식을 방문

// 3. 후위 순회(Postorder Traversal)
// 1) 왼쪽 자식을 방문
// 2) 오른쪽 자식을 방문
// 3) 먼저 자기 자신을 방문 처리
#include <iostream>

using namespace std;

int n = 15;

// 하나의 노드 정보를 선언
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

// 전위 순회를 구현
void preOrder(treePointer ptr)
{
	if (ptr)
	{
		cout << ptr->data << ' ';
		preOrder(ptr->leftChild);
		preOrder(ptr->rightChild);
	}
}

// 중위 순회를 구현
void inOrder(treePointer ptr)
{
	if (ptr)
	{
		inOrder(ptr->leftChild);
		cout << ptr->data << ' ';
		inOrder(ptr->rightChild);
	}
}

// 후위 순회를 구현
void postOrder(treePointer ptr)
{
	if (ptr)
	{
		postOrder(ptr->leftChild);
		postOrder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	node nodes[16];
	for (int i = 1; i <= n; i++)
	{
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			nodes[i / 2].leftChild = &nodes[i];
		else
			nodes[i / 2].rightChild = &nodes[i];
	}

	cout << "전위순회 :";
	preOrder(&nodes[1]);
	cout << '\n';
	
	cout << "중위순회 :";
	inOrder(&nodes[1]);
	cout << '\n';

	cout << "후위순회 :";
	postOrder(&nodes[1]);
	cout << '\n';

	return 0;
}