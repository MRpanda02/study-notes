#include<iostream>
using namespace std;
class MyDate {
public:
	int y, m, d, r = 0;
	MyDate();
	MyDate(int, int, int);
	void date_in(int y_, int m_, int d_);
	void compute(int num);
	int dvalue(MyDate& over);
	int inspect();
	void yesterday();
	int day(MyDate&);
};
MyDate::MyDate() {
	y = 0; m = 1; d = 1;
}
MyDate::MyDate(int y_, int m_, int d_) {
	MyDate::date_in(y_, m_, d_);
}
void MyDate::date_in(int y_, int m_, int d_) {
	MyDate::y = y_; MyDate::m = m_; MyDate::d = d_;
};
void MyDate::compute(int num) {
	d += num;
	while (r == 0)
		if (m <= 12) {
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				if (d > 31) {
					d -= 31; m += 1;
				}
			}
			else if (m == 4 || m == 6 || m == 9 || m == 11) {
				if (d > 30) {
					d -= 30; m += 1;
				}
			}

			else if (m == 2) {
				if (y % 4 == 0) {
					if (d > 29) {
						d -= 29; m += 1;
					}
				}
				if (y % 4 != 0) {
					if (d > 28) {
						d -= 28; m += 1;
					}
				}
			}
			else { r = 1; }
		}
		else if (m > 12) {
			m -= 12; y += 1;
		}
	if (d < 0) {
		m -= 1;
		if (m == 1 || m == 5 || m == 7 || m == 10 || m == 12) {

			d += 30;
		}
		else if (m == 2 || m == 4 || m == 6 || m == 8 || m == 11) {
			d += 31;
		}
		else if (m == 3) {
			if (y % 4 == 0) {
				d += 29;
			}
			if (y % 4 != 0) {
				d += 28;
			}

		}
	}
}
int MyDate::dvalue(MyDate& over) {
	int day(MyDate);
	MyDate::y -= over.y; MyDate::m -= over.m; MyDate::d -= over.d;
	return MyDate::day(over);
}
int MyDate::day(MyDate& now) {
	int i, r;
	r = ((now.y - now.y % 4) / 4) * 1461;
	for (i = now.m; i > 0; i--) {
		switch (i) {
		case 2:r += 31;
		case 3:r += 28 ? 29 : now.y % 4 != 0;
		case 4:r += 31;
		case 5:r += 30;
		case 6:r += 31;
		case 7:r += 30;
		case 8:r += 31;
		case 9:r += 31;
		case 10:r += 30;
		case 11:r += 31;
		case 12:r += 30;
		}
	}
	r += now.d;
	return r;
}
int MyDate::inspect() {
	if (MyDate::y >= 0) {
		if (MyDate::m <= 12) {
			if (MyDate::m == 1 || MyDate::m == 3 || MyDate::m == 5 || MyDate::m == 7 || MyDate::m == 8 || MyDate::m == 10 || MyDate::m == 12) {
				if (MyDate::d <= 31) {
					return  1;
				}
			}
			else if (MyDate::m == 4 || MyDate::m == 6 || MyDate::m == 9 || MyDate::m == 11) {
				if (MyDate::d <= 30) {
					return  1;
				}
			}

			else if (MyDate::m == 2) {
				if (MyDate::y % 4 == 0) {
					if (MyDate::d <= 29) {
						return  1;
					}
				}
				if (MyDate::y % 4 != 0) {
					if (MyDate::d <= 28) {
						return  1;
					}
				}
			}
		}
	}
	else return 0;
}
void MyDate::yesterday() {
	MyDate::compute(-1);
}
int inspect(int y_, int m_, int d_) {
	if (y_ >= 0) {
		if (m_ <= 12) {
			if (m_ == 1 || m_ == 3 || m_ == 5 || m_ == 7 || m_ == 8 || m_ == 10 || m_ == 12) {
				if (d_ <= 31) {
					return  1;
				}
			}
			else if (m_ == 4 || m_ == 6 || m_ == 9 || m_ == 11) {
				if (d_ <= 30) {
					return  1;
				}
			}

			else if (m_ == 2) {
				if (y_ % 4 == 0) {
					if (d_ <= 29) {
						return  1;
					}
				}
				if (y_ % 4 != 0) {
					if (d_ <= 28) {
						return  1;
					}
				}
			}
		}
	}
	return 0;
}
int main() {
	int y, m, d, choose = 0;
	MyDate today,thatday;
	// cout << today.y <<;

star:
	cout << "请输入日期，以回车间隔\n";
	cin >> y; cin >> m; cin >> d;
	if (inspect(y, m, d) == 1) {
		today.date_in(y, m, d);
	}
	else { goto star; cout << "请重新输入"; }
	cout << today.y << "年" << today.m << "月" << today.d << "日";
	cout << "请输入功能；\n1：与某日的相差天数\n2：某天之后的日期，输入为负时，为某天之前\n3：昨天\n";
	cin >> choose;
	if (choose == 1) {
	star1:
		cout << "请输入日期，以回车间隔";
		cin >> y; cin >> m; cin >> d;
		if (inspect(y, m, d) == 1) {
			thatday.date_in(y, m, d);
		}
		else { goto star1; }
		cout << today.dvalue(thatday);
	}
	if (choose == 2) {
		int add = 0;
		cin >> add;
		thatday = today;
		thatday.compute(add);
		cout << thatday.y << "年" << thatday.m << "月" << thatday.d << "日";
	}
	if (choose == 3) {
		thatday = today;
		thatday.yesterday();
		cout << thatday.y << "年" << thatday.m << "月" << thatday.d << "日";
	}
}
