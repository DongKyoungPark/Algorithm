// ���� Ʈ���� ������ ��ȸ
// ���� �ڷᱸ��
// �������� Ž�� �ӵ� ������ ���� ����ϴ� ����

// 1. ������ȸ(Preorder Traversal)
// 1) ���� �ڱ� �ڽ��� ó��
// 2) ���� �ڽ��� �湮
// 3) ������ �ڽ��� �湮

// 2. ���� ��ȸ(Inorder Traversal)
// 1) ���� �ڽ��� �湮
// 2) ���� �ڱ� �ڽ��� �湮 ó��
// 3) ������ �ڽ��� �湮

// 3. ���� ��ȸ(Postorder Traversal)
// 1) ���� �ڽ��� �湮
// 2) ������ �ڽ��� �湮
// 3) ���� �ڱ� �ڽ��� �湮 ó��
#include <iostream>

using namespace std;

int n = 15;

// �ϳ��� ��� ������ ����
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

// ���� ��ȸ�� ����
void preOrder(treePointer ptr)
{
	if (ptr)
	{
		cout << ptr->data << ' ';
		preOrder(ptr->leftChild);
		preOrder(ptr->rightChild);
	}
}

// ���� ��ȸ�� ����
void inOrder(treePointer ptr)
{
	if (ptr)
	{
		inOrder(ptr->leftChild);
		cout << ptr->data << ' ';
		inOrder(ptr->rightChild);
	}
}

// ���� ��ȸ�� ����
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

	cout << "������ȸ :";
	preOrder(&nodes[1]);
	cout << '\n';
	
	cout << "������ȸ :";
	inOrder(&nodes[1]);
	cout << '\n';

	cout << "������ȸ :";
	postOrder(&nodes[1]);
	cout << '\n';

	return 0;
}