

/*
* T sẽ sửa lại từng tý của bài này
* Để ý làm theo nhé, sửa đến đâu t sẽ có note đến đấy
*/

#include<iostream>
#include<math.h>
using namespace std;

/*
* Một trong số các kỹ năng dev chính là đặt tên biến
* M cần đặt tên biến một cách rõ ràng và dễ hiểu chứ không phải là đặt tên viết tắt của nó,
* về sau đâu phải mỗi m đọc code của m đâu
*/

// Ở đây có thể đặt là Kiem_tra_so_nguyen_to, hoặc tiếng anh là Prime_Number_check
/*
int snt(int n) 
{
	if (n < 2) return 0; // Không nên viết câu lệnh if rồi thực thi cùng 1 dòng
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
				return 0;
		}
		return 1;
	}
}
*/

/* T viết lại hàm kiểm tra ở đây nhé
* T sử dụng bool (bool là trả về đúng/sai, nên khi return t sẽ return về true(đúng) hoặc false(sai)
* sử dụng int như m thì cũng không sai, vẫn đúng nhưng mà về mặt ý nghĩa thì khác
*/
bool Prime_Number_Check(int n)
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

/*
* Oke lỗi sai ở đây là khi làm việc đến mảng, chúng ta sử dụng con trỏ
* Đối với mảng 1 chiều thì dùng con trỏ cấp 1
* Đối với mảng 2 chiều dùng con trỏ cấp 2
* Một vấn đề nữa, đây là một hàm thủ tục, m không cần nó trả về bất kì giá trị gì, 
* nên chúng ta không dùng "int nhap" mà là dùng "void"

int nhap(int a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
}

Viết lại sẽ như sau
*/

void Input_Array(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
}

/* Tương tự như trên

int xuat(int a[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << " " << a[i][j];
		cout << endl;
	}
	
}

Viết lại hàm như sau
*/

void Output_Array(int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << " " << a[i][j];
		cout << endl;
	}
}

/* Tránh khai báo nhiều biến cùng một dòng
* Oke phần này ổn, để ý lại đặt tên biến là được

int dem(int a[][100], int n, int m)
{
	int st = 0, hang;

	for (int i = 0; i < n; i++)
	{
		int dem = 0;

		for (int j = 0; j < m; j++)
		{
			if (snt(a[i][j]))
				++dem;
		}

		if (dem > st)
		{
			st = dem;
			hang = i;
		}

	}

	cout << " hang co nhieu so nguyen to nhat ";
	cout << hang + 1 << endl;

	for (int i = 0; i < m; i++)
	{
		if (snt(a[hang][i]))
			cout << " " << a[hang][i];
	}
	cout << endl;
}

*/

void Counting_Prime_Number(int **a, int n, int m)
{
	int temp = 0;
	int colunm = 0;

	for (int i = 0; i < n; i++)
	{
		int count = 0;

		for (int j = 0; j < m; j++)
		{
			if (Prime_Number_Check(a[i][j]))
				count++;
		}

		if (count > temp)
		{
			temp = count;
			colunm = i;
		}

	}

	cout << "Hang co nhieu so nguyen to nhat ";
	cout << colunm + 1 << endl;

	for (int i = 0; i < m; i++)
	{
		if (Prime_Number_Check(a[colunm][i]))
			cout << " " << a[colunm][i];
	}

	cout << endl;
}

// Ở đây t viết đưa thêm 1 hàm nữa ra ngoài, là hàm xuất ra những số nguyên tố của từng hàng
void Output_Prime_Number_of_Row(int** a, int n, int m)
{
	cout << "cac so nguyen to cua tung hang la: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Prime_Number_Check(a[i][j]))
				cout << " " << a[i][j];
		}
		cout << endl;
	}
}

/*
* Vì ở trên mình dùng con trỏ cấp 2, nên ở đây mình cũng phải khai báo con trỏ cấp 2
* mà đã dùng đến con trỏ cấp 2, mình phải khai báo cấp phát động cho nó
* mà đã cấp phát, thì nhớ phải xóa, nhìn kĩ trong hàm main nhé
* Thực ra t có thể đưa 2 cái cấp phát và xóa ra ngoài nhưng t để trong hàm main để cho m dễ hiểu
* Trên quy tắc lập trình viên thì hàm main thường không được dài quá 1 màn hình, nếu dài quá 1 màn hình là m chưa tối ưu code
* Good luck =))
*/

int main()
{
	int n, m;
	cin >> n >> m;

	// Khai báo và Cấp phát cho mảng 2 chiều
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}

	Input_Array(a, n, m);

	Output_Array(a, n, m);

	Counting_Prime_Number(a, n, m);

	Output_Prime_Number_of_Row(a, n, m);

	// Xóa bộ nhớ cho mảng 2 chiều đã cấp phát
	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;

	return 0;
}