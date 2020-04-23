#include <iostream>
#include "五子棋_functions.hpp"

using namespace std;
//use ● or 〇

void display_grid(int arr[]) {
	cout << "   ";
	for (int col = 1; col <= 10; col++) {
		cout << "  " << col;
	}
	for (int col = 11; col <= 15; col++) {
		cout << " " << col;
	}
	cout << "\n\n";

	for (int row = 0; row < 30; row++) {
		if (row % 2 == 0) {
			if ((row / 2) + 1 >= 10) {
				cout << (row / 2) + 1 << " ";
			}
			else {
				cout << (row / 2) + 1 << "  ";
			}
			for (int col = 0; col < 15; col++) {
				int every2row = arr[15 * row / 2 + col];
				if (every2row == 1) {
					cout << "  X";
				}
				else if (every2row == 2) {
					cout << "  O";
				}
				else if (every2row == 0) {
					cout << "  +";
				}
				
			}
			cout << endl;
		}
		else {
			cout << endl;
		}
	}
}

bool detect_5(int arr[]) {
	if (detect_5_horizontal(arr) || detect_5_vertical(arr) || detect_5_diagonal_1(arr) || detect_5_diagonal_2(arr)) {
		return true;
	}
	else {
		return false;
	}
}

bool detect_5_horizontal(int arr[]) {
	for (int row = 0; row < 15; row++) {
		for (int i = 0; i < 11; i++) {
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] && arr[i] == arr[i + 3] && arr[i] == arr[i + 4] && arr[i] != 0) {
				return true;
			}
			else {
				continue;
			}
		}
	}
	return false;
}

bool detect_5_vertical(int arr[]) {
	for (int row = 0; row < 11; row++) {
		for (int col = 0; col < 15; col++) {
			if (arr[row*15 + col] == arr[row*15 + col + 15] && arr[row*15 + col] == arr[row*15 + col + 30] 
				&& arr[row*15 + col] == arr[row*15 + col + 45] && arr[row*15 + col] == arr[row*15 + col + 60] 
				&& arr[row*15 + col] != 0) {
				return true;
			}
			else {
				continue;
			}
		}
	}
	return false;
}

bool detect_5_diagonal_1(int arr[]) {
	for (int row = 0; row < 11; row++) {
		for (int col = 0; col < 11; col++) {
			if (arr[row*15 + col] == arr[row*15 + col + 16] && arr[row*15 + col] == arr[row*15 + col + 32] 
				&& arr[row*15 + col] == arr[row*15 + col + 48] && arr[row*15 + col] == arr[row*15 + col + 64] 
				&& arr[row*15 + col] != 0) {
				return true;
			}
			else {
				continue;
			}
		}
	}
	return false;
}

bool detect_5_diagonal_2(int arr[]) {
	for (int row = 4; row < 15; row++) {
		for (int col = 4; col < 15; col++) {
			if (arr[row*15 + col] == arr[row*15 + col + 14] && arr[row*15 + col] == arr[row*15 + col + 28] 
				&& arr[row*15 + col] == arr[row*15 + col + 42] && arr[row*15 + col] == arr[row*15 + col + 56] 
				&& arr[row*15 + col] != 0) {
				return true;
			}
			else {
				continue;
			}
		}
	}
	return false;
}

int take_input() {

	cout << ",请输入坐标（行，列）：";
	int x, y;
	cin >> x >> y;

	if (x > 15 || y > 15) {
		cout << "此位置无效。\n";
		take_input();
	}

	return 15 * (y - 1) + (x - 1);
}

void determine_user(int& user) {
	if (user == 1) {
		user = 2;
	}
	else {
		user = 1;
	}
}