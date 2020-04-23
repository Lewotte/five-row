#include <iostream>
#include "五子棋_functions.cpp"

using namespace std;

int main() {
	int grid[225];
	for (int j = 0; j < 225; j++) {
		grid[j] = 0;
	}

	bool grid_status[225];
	for (int j = 0; j < 225; j++) {
		grid_status[j] = false;
	}

	int user = 1;
	int fullness = 0;

	display_grid(grid);

	while (!detect_5(grid) && fullness != 225) {

		if (user == 1) {
			cout << "玩家X：\n";
		}
		else if (user == 2) {
			cout << "玩家O：\n";
		}

		int user_input = take_input();

		while (grid_status[user_input]) {
			cout << "这个位置已被占用，请再次输入坐标。\n";
			user_input = take_input();
		}
		grid[user_input] = user;
		grid_status[user_input] = true;

		display_grid(grid);
		determine_user(user);

		for (int j = 0; j < 225; j++) {
			if (grid_status[j] == true) {
				fullness++;
			}
			else {
				continue;
			}
		}
	}
	system("PAUSE");
	return 0;
}