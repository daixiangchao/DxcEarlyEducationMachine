#include "huarongdao.hpp"


void Huarongdao::showpuzzle() {
	//int poi[8][2] = {{250,80},{250,180},{250,280},{350,80},{350,180},{350,280},{450,80},{450,180}};
	cout << pzz[0] << " " << pzz[1] << " " << pzz[2] << endl; // ��1��
	cout << pzz[3] << " " << pzz[4] << " " << pzz[5] << endl; // ��2��
	cout << pzz[6] << " " << pzz[7] << " " << pzz[8] << endl; // ��3��
}


void Huarongdao::move(string direct) // �����ƶ�����
{
	if (direct == "w") { // ����
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
		else if (start) { printf("���ܲ���\n"); }
	}
	else if (direct == "s") { // s����
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
			printf("���ܲ���\n");
		}
	}
	else if (direct == "a") { // a����
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
		else if (start) { printf("���ܲ���\n"); }
	}
	else if (direct == "d") { // d����
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
		else if (start) { printf("���ܲ���\n"); }
	}
	else { printf("��������ȷ�Ĳ���\n"); }
}
int Huarongdao::hrdmain()
{
	bool won;
	won = false; // ��ճɹ��ж�
	start = false; // ��տ�ʼ�ж�
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) // ��������,����Խ�ߴ��ҳ̶�Խ��
	{
		int p = rand() % 4;
		if (p == 0)
		{
			move("w"); // ����������
		}
		else if (p == 1)
		{
			move("s"); // ����������
		}
		else if (p == 2)
		{
			move("a"); // ����������
		}
		else
		{
			move("d"); // ����������
		}
	}
	printf("#####\n");
	start = true; // �����ѿ�ʼ
	while (won == false)
	{
		showpuzzle(); // ��ʾ����
		string run;
		cout << "���������" << endl;
		cin >> run;
		if ("q" == run) return 0;
		move(run);
		if (pzz[0] == 1 && pzz[1] == 2 && pzz[2] == 3 && pzz[3] == 4 && pzz[4] == 5 && pzz[5] == 6 && pzz[6] == 7 && pzz[7] == 8 && pzz[8] == 0) // ��������ǳ�ʼ����Ϊ�ɹ�
		{
			showpuzzle();
			printf("�ɹ�!");
			won = true;//�����ѳɹ�
			return 0;
		}
	}
	return 0;
}