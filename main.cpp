#include "BST.h"
#include"function.cpp"


int main()
{
	BinarySortTree<int>bst;
	int choice = 0;
	int n = 0, n1 = 0, n2 = 0, n0 = 0;

	cout << "请输入数据(输入0结束)" << endl;
	cin >> n;
	while (n) {
		bst.BST_insert(n);
		cin >> n;
	}

	while (true)
	{
		bst.show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			bst.exitSystem();
			break;
		case 1://插入数据
			cout << "请输入您要插入的数据：" << endl;
			cin >> n0;
			bst.BST_insert(n0);
			cout << "插入数据成功" << endl;
			system("pause");
			system("cls");
			break;
		case 2://查找数据
			cout << "请输入您要查找的数据：" << endl;
			cin >> n1;
			if (bst.BST_search(n1) != nullptr)
			{
				cout << "存在该元素" << endl;
			}
			else
				cout << "不存在该元素" << endl;
			system("pause");
			system("cls");
			break;
		case 3://删除数据
			cout << "请输入您要删除的数据：" << endl;
			cin >> n2;
			bst.BST_delete(n2);
			cout << "删除数据成功" << endl;
			system("pause");
			system("cls");
			break;
		case 4://递归前序遍历
			cout << "递归前序遍历" << endl;
			bst.BST_preorderR();
			cout << "递归前序遍历成功" << endl;
			system("pause");
			system("cls");
			break;
		case 5://递归中序遍历
			cout << "递归中序遍历" << endl;
			bst.BST_inorderR();
			cout << "递归中序遍历成功" << endl;
			system("pause");
			system("cls");
			break;
		case 6://递归后序遍历
			cout << "递归后序遍历" << endl;
			bst.BST_postorderR();
			cout << "递归后序遍历成功" << endl;
			system("pause");
			system("cls");
			break;
		case 7://迭代前序遍历
			cout << "迭代前序遍历" << endl;
			bst.BST_preorderI();
			cout << "迭代前序遍历成功" << endl;
			system("pause");
			system("cls");
			break;
		case 8://迭代中序遍历
			cout << "迭代中序遍历" << endl;
			bst.BST_inorderI();
			cout << "迭代中序遍历成功" << endl;
			system("pause");
			system("cls");
			break;
		case 9://迭代后序遍历
			cout << "迭代后序遍历" << endl;
			bst.BST_postorderI();
			cout << "迭代后序遍历成功" << endl;
			system("pause");
			system("cls");
			break;
		case 10://层序遍历
			cout << "层序遍历" << endl;
			bst.BST_levelOrder();
			cout << "层序遍历成功" << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入错误" << endl;
			cout << "请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}