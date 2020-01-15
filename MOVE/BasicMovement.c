#include "BasicMovement.h"

struct wheel WheelsSpeed;//WheelsSpeed[0]�������������ٶ�,WheelsSpeed[1]��һ���ٶ�

/*
 * ������: InitWheelsSpeed
 * ��  ��: ��ʼ������WheelsSpeed[2]��
 * ��  �룺����P
 * ��  ��: ����P�복������ϵy��������н�
 * ��  ��: �ⲿ����
 */
void InitWheelsSpeed(void)
{
		
		WheelsSpeed.bl.wheelangle = 0;
		WheelsSpeed.bl.wheelvel = 0;
		WheelsSpeed.fl.wheelangle = 0;
		WheelsSpeed.fl.wheelvel = 0;
		WheelsSpeed.br.wheelangle = 0;
		WheelsSpeed.br.wheelvel = 0;
		WheelsSpeed.fr.wheelangle = 0;
		WheelsSpeed.fr.wheelvel = 0;
	
}

/*
 * ������: GetVectorRadian
 * ��  ��: ������P�복������ϵy��������нǣ�˳ʱ��Ϊ��,���û����ơ�
 * ��  �룺����P
 * ��  ��: ����P�복������ϵy��������н�
 * ��  ��: �ⲿ����
 */
double GetVectorRadian(Position P)
{
	double radian = 0;
	if (P.x > 0)
		radian = pi / 2 - atan(P.y / P.x);
	else if (P.x < 0)
		radian = -pi / 2 - atan(P.y / P.x);
	else
	{
		if (P.y > 0)
			radian = 0;
		else if (P.y < 0)
			radian = pi;
	}
	return radian;
}

/*
 * ������: WheelsSpeed_Cycle
 * ��  ��: ����M���Խ��ٶ�w0(˳ʱ��Ϊ���������ƣ���תʱ�ĸ����ӵ��ٶȴ�С���Լ��ٶ��복������ϵy��������нǣ�˳ʱ��Ϊ��
           �н�λ��-pi/2~pi/2,���û����ơ�
 * ��  �룺��P���Կռ������Լ����ٶ�w0������GPS����b����GPS
 * ��  ��: �ĸ����ӵ��ٶȴ�С���Լ��ٶ��복������ϵy��нǱ���WheelsSpeed[0]
 * ��  ��: �ⲿ����
 */
void GetWheelsSpeed_Cycle(struct Point M, double w0)
{
	struct Point TempPosition, TempPosition1;
//TempPosition�洢���ӵ�תȦ������
	TempPosition1.x = (GPS.position.y - M.y - LENGTH_LR / 2 * sin(GPS.radian) + LENGTH_FB / 2 * cos(GPS.radian));
	TempPosition1.y = (-GPS.position.x + M.x - LENGTH_FB / 2 * sin(GPS.radian) - LENGTH_LR / 2 * cos(GPS.radian));
	TempPosition.x = -TempPosition1.y;
	TempPosition.y = TempPosition1.x;
	WheelsSpeed.fr.wheelvel = GetLength(M, TempPosition) * fabs(w0);	
	WheelsSpeed.fr.wheelangle = GetVectorRadian(TempPosition1)-GPS.radian;	
	if (WheelsSpeed.fr.wheelangle > pi / 2)
	{
		WheelsSpeed.fr.wheelangle -= pi;
		WheelsSpeed.fr.wheelvel = -WheelsSpeed.fr.wheelvel;
	}
	if (WheelsSpeed.fr.wheelangle < -pi / 2)
	{
		WheelsSpeed.fr.wheelangle += pi;
		WheelsSpeed.fr.wheelvel = -WheelsSpeed.fr.wheelvel;
	}
	WheelsSpeed.fr.wheelangle = WheelsSpeed.fr.wheelangle / pi * 180;
	/**********************************/

	TempPosition1.x = (GPS.position.y - M.y + LENGTH_LR / 2 * sin(GPS.radian) + LENGTH_FB / 2 * cos(GPS.radian));
	TempPosition1.y = (-GPS.position.x + M.x - LENGTH_FB / 2 * sin(GPS.radian) + LENGTH_LR / 2 * cos(GPS.radian));
	TempPosition.x = -TempPosition1.y;
	TempPosition.y = TempPosition1.x;
	
	WheelsSpeed.fl.wheelvel = GetLength(M, TempPosition) * fabs(w0);
	WheelsSpeed.fl.wheelangle = GetVectorRadian(TempPosition1) - GPS.radian;

	if (WheelsSpeed.fl.wheelangle > pi / 2)
	{
		WheelsSpeed.fl.wheelangle -= pi;
		WheelsSpeed.fl.wheelvel = -WheelsSpeed.fl.wheelvel;
	}
	if (WheelsSpeed.fl.wheelangle < -pi / 2)
	{
		WheelsSpeed.fl.wheelangle += pi;
		WheelsSpeed.fl.wheelvel = -WheelsSpeed.fl.wheelvel;
	}

	/**********************************/

	TempPosition1.x = (GPS.position.y - M.y + LENGTH_LR / 2 * sin(GPS.radian) - LENGTH_FB / 2 * cos(GPS.radian));
	TempPosition1.y = (-GPS.position.x + M.x + LENGTH_FB / 2 * sin(GPS.radian) + LENGTH_LR / 2 * cos(GPS.radian));
	TempPosition.x = -TempPosition1.y;
	TempPosition.y = TempPosition1.x;
	
	WheelsSpeed.bl.wheelvel = GetLength(M, TempPosition) * fabs(w0);
	WheelsSpeed.bl.wheelangle = GetVectorRadian(TempPosition1) - GPS.radian;
	
	if (WheelsSpeed.bl.wheelangle > pi / 2)
	{
		WheelsSpeed.bl.wheelangle -= pi;
		WheelsSpeed.bl.wheelvel = -WheelsSpeed.bl.wheelvel;
	}
	if (WheelsSpeed.bl.wheelangle < -pi / 2)
	{
		WheelsSpeed.bl.wheelangle += pi;
		WheelsSpeed.bl.wheelvel = -WheelsSpeed.bl.wheelvel;
	}
	
	/**********************************/

	TempPosition1.x = (GPS.position.y - M.y - LENGTH_LR / 2 * sin(GPS.radian) - LENGTH_FB / 2 * cos(GPS.radian));
	TempPosition1.y = (-GPS.position.x + M.x + LENGTH_FB / 2 * sin(GPS.radian) - LENGTH_LR / 2 * cos(GPS.radian));
	TempPosition.x = -TempPosition1.y;
	TempPosition.y = TempPosition1.x;
	
	WheelsSpeed.br.wheelvel = GetLength(M, TempPosition) * fabs(w0);
	WheelsSpeed.br.wheelangle = GetVectorRadian(TempPosition1) - GPS.radian;
	
	if (WheelsSpeed.br.wheelangle > pi / 2)
	{
		WheelsSpeed.br.wheelangle -= pi;
		WheelsSpeed.br.wheelvel = -WheelsSpeed.br.wheelvel;
	}
	if (WheelsSpeed.br.wheelangle < -pi / 2)
	{
		WheelsSpeed.br.wheelangle += pi;
		WheelsSpeed.br.wheelvel = -WheelsSpeed.br.wheelvel;
	}

}
/*
 * ������: Run_Cycle
  * ��  ��: �ó�����M���Խ��ٶ�w0(˳ʱ��Ϊ���������ƣ���תʱ��
 * ��  �룺��P���Կռ������Լ����ٶ�w0������GPS����b����GPS
 * ��  ��: �ĸ����ӵ��ٶȴ�С���Լ��ٶ��복������ϵy��нǱ���WheelsSpeed[0]
 * ��  ��: �ⲿ����
 */
void Run_Cycle(struct Point M, double w0)
{
	GetWheelsSpeed_Cycle( M, w0);
	set_motor(WheelsSpeed);	
}
/*
 * ������: GetWheelsSpeed_Line
 * ��  ��: ����������v,�����������ϵy��������н�theta����ֱ��ʱ�ĸ����ӵ��ٶȴ�С���Լ��ٶ��복������ϵy��������нǣ�˳ʱ��Ϊ��
		       �н�λ��-90~90,���ýǶ��ơ�
 * ��  �룺����v���н�theta
 * ��  ��: �ĸ����ӵ��ٶȴ�С���Լ��ٶ��복������ϵy��нǱ���WheelsSpeed[0]
 * ��  ��: �ⲿ����
 */
void GetWheelsSpeed_Line(double v,double theta)
{
	
	WheelsSpeed.bl.wheelvel = WheelsSpeed.br.wheelvel = WheelsSpeed.fl.wheelvel = WheelsSpeed.fl.wheelvel = v;
	theta = (theta - GPS.radian);
	if (theta> pi/2)
	{
		WheelsSpeed.br.wheelangle =theta- pi;
		WheelsSpeed.bl.wheelvel = WheelsSpeed.br.wheelvel = WheelsSpeed.fl.wheelvel = WheelsSpeed.fl.wheelvel = -v;
	}
	if (theta <- pi/2)
	{
		WheelsSpeed.br.wheelangle = theta + pi;
		WheelsSpeed.bl.wheelvel = WheelsSpeed.br.wheelvel = WheelsSpeed.fl.wheelvel = WheelsSpeed.fl.wheelvel = -v;
	}
}

/*
 * ������: Run_Line
 * ��  ��: �ó���������v,�����������ϵy��������н�theta��������)����ֱ��
 * ��  �룺����v���н�theta
 * ��  ��: �ĸ����ӵ��ٶȴ�С���Լ��ٶ��복������ϵy��нǱ���WheelsSpeed[0]
 * ��  ��: �ⲿ����
 */
void Run_Line(double v,double theta)
{
	GetWheelsSpeed_Line( v,theta);
	set_motor(WheelsSpeed);
}

