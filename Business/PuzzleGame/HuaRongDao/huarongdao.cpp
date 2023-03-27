#include "huarongdao.hpp"


void Huarongdao::showpuzzle() {
	//int poi[8][2] = {{250,80},{250,180},{250,280},{350,80},{350,180},{350,280},{450,80},{450,180}};
	cout << pzz[0] << " " << pzz[1] << " " << pzz[2] << endl; // 第1行
	cout << pzz[3] << " " << pzz[4] << " " << pzz[5] << endl; // 第2行
	cout << pzz[6] << " " << pzz[7] << " " << pzz[8] << endl; // 第3行
}


void Huarongdao::move(string direct) // 定义移动函数
{
	if (direct == "w") { // 向上
		if (pzz[0] == 0) {
			pzz[0] = pzz[3];
			pzz[3] = 0;
		}
		else if (pzz[1] == 0) {
			pzz[1] = pzz[4];
			pzz[4] = 0;
		}
		else if (pzz[2] == 0) {
			pzz[2] = pzz[5];
			pzz[5] = 0;
		}
		else if (pzz[3] == 0) {
			pzz[3] = pzz[6];
			pzz[6] = 0;
		}
		else if (pzz[4] == 0) {
			pzz[4] = pzz[7];
			pzz[7] = 0;
		}
		else if (pzz[5] == 0) {
			pzz[5] = pzz[8];
			pzz[8] = 0;
		}
		else if (start) { printf("不能操作\n"); }
	}
	else if (direct == "s") { // s向下
		if (pzz[3] == 0) {
			pzz[3] = pzz[0];
			pzz[0] = 0;
		}
		else if (pzz[4] == 0) {
			pzz[4] = pzz[1];
			pzz[1] = 0;
		}
		else if (pzz[5] == 0) {
			pzz[5] = pzz[2];
			pzz[2] = 0;
		}
		else if (pzz[6] == 0) {
			pzz[6] = pzz[3];
			pzz[3] = 0;
		}
		else if (pzz[7] == 0) {
			pzz[7] = pzz[4];
			pzz[4] = 0;
		}
		else if (pzz[8] == 0) {
			pzz[8] = pzz[5];
			pzz[5] = 0;
		}
		else if (start) {
			printf("不能操作\n");
		}
	}
	else if (direct == "a") { // a向左
		if (pzz[0] == 0) {
			pzz[0] = pzz[1];
			pzz[1] = 0;
		}
		else if (pzz[1] == 0) {
			pzz[1] = pzz[2];
			pzz[2] = 0;
		}
		else if (pzz[3] == 0) {
			pzz[3] = pzz[4];
			pzz[4] = 0;
		}
		else if (pzz[4] == 0) {
			pzz[4] = pzz[5];
			pzz[5] = 0;
		}
		else if (pzz[6] == 0) {
			pzz[6] = pzz[7];
			pzz[7] = 0;
		}
		else if (pzz[7] == 0) {
			pzz[7] = pzz[8];
			pzz[8] = 0;
		}
		else if (start) { printf("不能操作\n"); }
	}
	else if (direct == "d") { // d向右
		if (pzz[1] == 0) {
			pzz[1] = pzz[0];
			pzz[0] = 0;
		}
		else if (pzz[2] == 0) {
			pzz[2] = pzz[1];
			pzz[1] = 0;
		}
		else if (pzz[4] == 0) {
			pzz[4] = pzz[3];
			pzz[3] = 0;
		}
		else if (pzz[5] == 0) {
			pzz[5] = pzz[4];
			pzz[4] = 0;
		}
		else if (pzz[7] == 0) {
			pzz[7] = pzz[6];
			pzz[6] = 0;
		}
		else if (pzz[8] == 0) {
			pzz[8] = pzz[7];
			pzz[7] = 0;
		}
		else if (start) { printf("不能操作\n"); }
	}
	else { printf("请输入正确的操作\n"); }
}
int Huarongdao::hrdmain()
{
	bool won;
	won = false; // 清空成功判断
	start = false; // 清空开始判断
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) // 打乱棋盘,数字越高打乱程度越高
	{
		int p = rand() % 4;
		if (p == 0)
		{
			move("w"); // 随机方向打乱
		}
		else if (p == 1)
		{
			move("s"); // 随机方向打乱
		}
		else if (p == 2)
		{
			move("a"); // 随机方向打乱
		}
		else
		{
			move("d"); // 随机方向打乱
		}
	}
	printf("#####\n");
	start = true; // 设置已开始
	while (won == false)
	{
		showpuzzle(); // 显示棋盘
		string run;
		cout << "请输入操作" << endl;
		cin >> run;
		if ("q" == run) return 0;
		move(run);
		if (pzz[0] == 1 && pzz[1] == 2 && pzz[2] == 3 && pzz[3] == 4 && pzz[4] == 5 && pzz[5] == 6 && pzz[6] == 7 && pzz[7] == 8 && pzz[8] == 0) // 如果棋盘是初始样子为成功
		{
			showpuzzle();
			printf("成功!");
			won = true;//设置已成功
			return 0;
		}
	}
	return 0;
}