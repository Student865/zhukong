 #include "all.h"
 
 typedef struct
{
    double wheelvel;  //����ٶȣ������ɸ���Ϊ�����ת��������
    double wheelangle; //���ƽ���복��������ǰ���нǣ�˳ʱ��Ϊ������Сλ��-pi/2��pi/2֮��
}wheelspeed_para;

struct wheel
{
    wheelspeed_para fl;//ǰ����
    wheelspeed_para fr;//ǰ����
    wheelspeed_para bl;//������
    wheelspeed_para br;//������
};


double aatan(double x,double y);
void Wheel_Vel(double vel,double direction,double omega,double pose_angle);
void set_motor(struct wheel Wheel);




 