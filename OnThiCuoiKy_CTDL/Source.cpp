#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};

typedef node* NODEPTR;

void khoiTao(NODEPTR& list)
{
	list = NULL;
}

NODEPTR taoNode(int x)
{
	NODEPTR p = new node;
	p->data = x;
	p->link = NULL;
	return p;
}

NODEPTR themCuoi(NODEPTR& list, int x)
{
	NODEPTR p = taoNode(x);
	if (list == NULL)
	{
		list = p;
	}
	else
	{
		NODEPTR q = list;
		while (q->link != NULL)
		{
			q = q->link;
		}
			q->link = p;
	}
	return p;
}

void themDau(NODEPTR& list, int x)
{
	NODEPTR p = taoNode(x);
	if (list == NULL)
	{
		list = p;
	}
	else
	{
		p->link = list;
		list = p;
	}
}

int isEmpty(NODEPTR list)
{
	return (list == NULL ? 1 : 0);
}

void nhap(NODEPTR& list)
{
	int x;
	do
	{
		cout << "\n Nhap Gia Tri: (-99 De Thoat)"; cin >> x;
		if (x == -99) break;
		themCuoi(list, x);
	} while (1);
}

void xuat(NODEPTR list)
{
	NODEPTR p = list;
	while (p!= NULL)
	{
		cout << " " << p->data;
		p = p->link;
	}
}

// Đếm các phần tử có giá trị là X 
int demX(NODEPTR list, int x)
{
	int dem = 0;
	NODEPTR p = list;
	while (p != NULL)
	{
		if (p->data == x)
		{
			dem++;
		}
		p = p->link;
	}
	return dem;
}

// Ghép 2 danh sách liên kết đơn có thứ tự thành 1 danh sách liên kết 
void ghepDanhSachCoThuTu(NODEPTR& list, NODEPTR list1, NODEPTR list2)
{
	NODEPTR p;
	if (!isEmpty(list1))
	{
		while (list1 != NULL)
		{
			if (list2 == NULL)
			{
				p = list1;
				list1 = list1->link;
				p->link = NULL;
				themCuoi(list, p->data);
				
			}
			else
			{
				if (list1->data >= list2->data) //nếu list 1 lớn hơn list 2 thì thêm list 2 vào trước
				{
					p = list2;
					list2 = list2->link;
					p->link = NULL;
					themCuoi(list, p->data);
				}
				else
				{
					p = list1;
					list1 = list1->link;
					p->link = NULL;
					themCuoi(list, p->data);
				}
			}
		}
		while (list2 != NULL)
		{
			p = list2;
			list2 = list2->link;
			p->link = NULL;
			themCuoi(list, p->data);
		}
	}
	else
	{
		while (list2 != NULL)
		{
			p = list2;
			list2 = list2->link;
			p->link = NULL;
			themCuoi(list, p->data);
		}
	}
}

bool checkSnt(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}


void tachDanhSachThanhHaiDanhSach(NODEPTR list, NODEPTR& list1, NODEPTR& list2)
{
	while (!isEmpty(list))
	{
		NODEPTR p = list;
		if (checkSnt(p->data) == true)
		{
			list = list->link;
			p->link = NULL;
			themCuoi(list1, p->data);
		}
		else
		{
			list = list->link;
			p->link = NULL;
			themCuoi(list2, p->data);
		}
		
	}
}

void themCuoiDieuKien(NODEPTR& list, int x)
{
	NODEPTR p = list;
	while (p->link != NULL)
		p = p->link;
	if (p->data < x)
	{
		themCuoi(list, x);
	}
}

void themXVaoDanhSachTangDan(NODEPTR& list, int x)
{
	NODEPTR p;
	NODEPTR q = taoNode(x);
	
	if (!isEmpty(list))
	{
		if (list->data > x)
		{
			themDau(list, x);
		}
		p = list;
		while (p != NULL)
		{
			if (p->data <= x && x <= p->link->data)
			{
				q->link = p->link;
				p->link = q;
				break;
			}
			p = p->link;
		}
	}
}

void xoaSoNguyenToDauTien(NODEPTR& list)
{
	NODEPTR p,before;
	if (!isEmpty(list))
	{
		p = list;
		before = list;
		while (p != NULL)
		{
			if (checkSnt(p->data))
			{
				before->link = p->link;
				p->link = NULL;
				delete p;
				break;
			}
			before = p;
			p = p->link;
		}
	}
}

void sapXepTangDan(NODEPTR& list)
{
	NODEPTR p = list;
	NODEPTR q;
	for (p = list; p->link != NULL; p = p->link)
	{
		for (q = p->link; q != NULL; q = q->link)
		{
			if (p->data >= q->data)
			{
				int tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}

int demPhanTu(NODEPTR list)
{
	int dem = 0;
	NODEPTR p = list;
	while (p != NULL)
	{
		dem++;
		p = p->link;
	}
	return dem;
}

void xoaNodeTaiViTriK(NODEPTR& list, int k)
{
	NODEPTR p, q, before;
	int soPhanTu = demPhanTu(list);
	if (k == 0)
	{
		p = list;
		list = list->link;
		p->link = NULL;
		delete p;
	}
	else if (k > 0 && k <= soPhanTu)
	{
			q = list;
			before = list;
			for (int i = 0; i < k - 1; i++) q = q->link;
			before->link = q->link;
			p = q;
			delete p;
			q = before->link;
	}
}

void xoaNodeX(NODEPTR& list, int x)
{
	NODEPTR p, before;
	before = list;
	p = list;
	if (list->data == x)
	{
		p = list;
		list = list->link;
		p->link = NULL;
		delete p;
	}
	else
	{
		while (p != NULL && p->data != x)
		{
			before = p;
			p = p->link;
		}
		if (p != NULL)
		{
			before->link = p->link;
			p->link = NULL;
			delete p;
		}
	}
}

void xoaTrungNhau(NODEPTR& list)
{
	NODEPTR p, q;
	for (p = list; p->link != NULL; p = p->link)
	{
		for (q = p->link; q != NULL; q = q->link)
		{
			if (p->data == q->data)
			{
				xoaNodeX(list, q->data);
				//p--;
			}
		}
	}
}

int main()
{
	NODEPTR list,list1,list2;
	khoiTao(list);
	khoiTao(list1);
	khoiTao(list2);
	int chon = 0;
	do
	{
		cout << "\n\n\t\t1. Nhap Gia Tri. ";
		cout << "\n\n\t\t2. Xuat Gia Tri.";
		cout << "\n\n\t\t3. Dem Cac Phan Tu Co Gia Tri La X.";
		cout << "\n\n\t\t4. Ghep 2 Danh Sach Lien Ket Thanh 1 Danh Sach Co Thu Tu.";
		cout << "\n\n\t\t5. Tach 1 DSLK Thanh 2 DSLK Trong Do Danh Sach 1 Chua SNT Va Danh Sach 2 Chua Phan Tu Con Lai.";
		cout << "\n\n\t\t6. Them Mot Phan Tu X Vao DSLK Chua Gia Tri Tang Dan ( Khong Dung GThuat Sap Xep).";
		cout << "\n\n\t\t7. Xoa Phan Tu La So Nguyen To Dau Tien.";
		cout << "\n\n\t\t8. Dem Cac Phan Tu Phan Biet Nhau.";
		cout << "\n\n\t\t9. Xoa Node X Nhap Vao.";
		cout << "\n\n\t\t0. Dung Lai.";
		cout << "\n Lua Chon 1 So Nguyen De Thuc Thi: "; cin >> chon;
		switch (chon)
		{
		case 1:
			system("cls");
			nhap(list);
			break;
		case 2:
			system("cls");
			xuat(list);
			break;
		case 3:
			system("cls");
			int x,kq;
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			kq = demX(list, x);
			cout<<"\n So Luong X Co Trong Danh Sach La: "<<kq;
			break;
		case 4:
			system("cls");
			cout << "\n Nhap Danh Sach 1: ";
			nhap(list1);
			cout << "\n Nhap Danh Sach 2: ";
			nhap(list2);
			ghepDanhSachCoThuTu(list, list1, list2);
			cout << "\n Danh Sach Sau Khi Ghep: ";
			xuat(list);
			break;
		case 5:
			system("cls");
			tachDanhSachThanhHaiDanhSach(list, list1, list2);
			cout << "\n Danh Sach Chua So Nguyen To: ";
			xuat(list1);
			cout << "\n Danh Sach Chua So Khong Phai La So Nguyen To: ";
			xuat(list2);
			break;
		case 6:
			system("cls");
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			themXVaoDanhSachTangDan(list, x);
			xuat(list);
			break;
		case 7:
			system("cls");
			cout << "\n Xoa So Nguyen To Dau Tien Trong DSLK: ";
			xoaSoNguyenToDauTien(list);
			xuat(list);
		case 8:
			system("cls");
			xoaTrungNhau(list);
			xuat(list);
			break;
		case 9:
			system("cls");
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			xoaNodeX(list, x);
			xuat(list);
			break;
		default:
			break;
		}
	} while (chon!=0);
	return 0;
}