#include "BST.h"
#include"function.cpp"


int main()
{
	BinarySortTree<int>bst;
	int choice = 0;
	int n = 0, n1 = 0, n2 = 0, n0 = 0;

	cout << "����������(����0����)" << endl;
	cin >> n;
	while (n) {
		bst.BST_insert(n);
		cin >> n;
	}

	while (true)
	{
		bst.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			bst.exitSystem();
			break;
		case 1://��������
			cout << "��������Ҫ��������ݣ�" << endl;
			cin >> n0;
			bst.BST_insert(n0);
			cout << "�������ݳɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 2://��������
			cout << "��������Ҫ���ҵ����ݣ�" << endl;
			cin >> n1;
			if (bst.BST_search(n1) != nullptr)
			{
				cout << "���ڸ�Ԫ��" << endl;
			}
			else
				cout << "�����ڸ�Ԫ��" << endl;
			system("pause");
			system("cls");
			break;
		case 3://ɾ������
			cout << "��������Ҫɾ�������ݣ�" << endl;
			cin >> n2;
			bst.BST_delete(n2);
			cout << "ɾ�����ݳɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 4://�ݹ�ǰ�����
			cout << "�ݹ�ǰ�����" << endl;
			bst.BST_preorderR();
			cout << "�ݹ�ǰ������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 5://�ݹ��������
			cout << "�ݹ��������" << endl;
			bst.BST_inorderR();
			cout << "�ݹ���������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 6://�ݹ�������
			cout << "�ݹ�������" << endl;
			bst.BST_postorderR();
			cout << "�ݹ��������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 7://����ǰ�����
			cout << "����ǰ�����" << endl;
			bst.BST_preorderI();
			cout << "����ǰ������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 8://�����������
			cout << "�����������" << endl;
			bst.BST_inorderI();
			cout << "������������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 9://�����������
			cout << "�����������" << endl;
			bst.BST_postorderI();
			cout << "������������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 10://�������
			cout << "�������" << endl;
			bst.BST_levelOrder();
			cout << "��������ɹ�" << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "�������" << endl;
			cout << "����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}