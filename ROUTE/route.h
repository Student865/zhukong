 #include "all.h"
 
 typedef struct
{
    double wheelvel;  //轮毂速度，可正可负，为负电机转动方向反向
    double wheelangle; //轮毂平面与车身纵轴正前方夹角，顺时针为正，大小位于-pi/2至pi/2之间
}wheelspeed_para;

struct wheel
{
    wheelspeed_para fl;//前左轮
    wheelspeed_para fr;//前右轮
    wheelspeed_para bl;//后左轮
    wheelspeed_para br;//后右轮
};


double aatan(double x,double y);
void Wheel_Vel(double vel,double direction,double omega,double pose_angle);
void set_motor(struct wheel Wheel);




 