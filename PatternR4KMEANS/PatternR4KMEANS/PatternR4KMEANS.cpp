// PatternR4KMEANS.cpp : 定义控制台应用程序的入口点。
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "math.h"
#include "stdlib.h"

struct point
{
	double x, y;
};

double distance(point a,point b)
{
	double dis;
	dis = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	return dis;
};

void main()
{
	int N; 
	point *Point;
	printf("请输入样本点的个数\n");
	scanf("%d", &N);
	if (N < 0){
		printf("Error\n");
	}
	Point = new point[N];
	for (int i = 0; i < N; i++)
	{
		printf("请输入第%d个点的坐标\n", i + 1);
		scanf("%lf,%lf", &Point[i].x, &Point[i].y);
	}
	//输入二十个坐标点的坐标

	int a, b;
	point point1, point2, pointa, pointb;
	printf("请输入两个初始聚类中心的点号\n");
	scanf("%d,%d", &a, &b);
	point1.x = Point[a - 1].x;
	point1.y = Point[a - 1].y;
	point2.x = Point[b - 1].x;
	point2.y = Point[b - 1].y;//选择初始聚类中心

	double dis1, dis2;
	int n1=0,n2=0;
	int aa[20], bb[20];
	while (1)
	{
		pointa.x = 0;
		pointa.y = 0;
		pointb.x = 0;
		pointb.y = 0;
		for (int i = 0; i<20; i++){
			aa[i] = 0;
			bb[i] = 0;
		}
		n1 = 0;
		n2 = 0;//值的初始化

		for (int i = 0; i < N; i++)
		{
			dis1 = distance(point1, Point[i]);
			dis2 = distance(point2, Point[i]);
			if (dis1 >= dis2)
			{
				n2++;
				pointb.x += Point[i].x;
				pointb.y += Point[i].y;
				bb[n2 - 1] = i + 1;
			}
			else
			{
				n1++;
				pointa.x += Point[i].x;
				pointa.y += Point[i].y;
				aa[n1 - 1] = i + 1;
			}
		}
		pointa.x = pointa.x / n1;
		pointa.y = pointa.y / n1;
		pointb.x = pointb.x / n2;
		pointb.y = pointb.y / n2;//每一次迭代时聚类中心的更新
		if (pointa.x == point1.x&&pointa.y == point1.y&&pointb.x == point2.x&&pointb.y == point2.y)
		{
			break;
		}//迭代结束的条件
		point1.x = pointa.x;
		point1.y = pointa.y;
		point2.x = pointb.x;
		point2.y = pointb.y;
	}//确定最终的聚类中心

	printf("第一个聚类中心是 %lf,%lf\n", point1.x, point1.y);
	printf("第二个聚类中心是 %lf,%lf\n", point2.x, point2.y);

	printf("属于第一类的点有\n");
	for (int i = 0; i<20; i++){
		if (aa[i] == 0)
		{
			break;
		}
		else
		{
				printf("%d\n", aa[i]);
			
		}
	}
	printf("属于第二类的点有\n");
	for (int i = 0; i<20; i++)
	{
		if (bb[i] == 0)
		{
			break;
		}
		else
		{
			printf("%d\n", bb[i]);
		}
	}
	delete []Point;
	system("pause");
}


