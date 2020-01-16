/* Includes ------------------------------------------------------------------*/
#include "M_List.h"
#include "M_Func.h"
#include "M_Sys.h"

#include "all.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/*�˵�*/
struct M_Type MainMenu[M_NUM];
struct M_Type M_System[M_NUM];
struct M_Type *CurrentMenu = MainMenu;//��ʼ����ǰ�˵�Ϊ���˵�
//���˵��µ��Ӳ˵�
struct M_Type MainMenu[M_NUM]=
{	/*Name              �˵�����                ����                �ڵ�*/
	{"1.System",        M_UFunc,                sys_dog,            {MainMenu, NULL} },
	{"2.FastDog",       M_Empty,                NULL,               {MainMenu, NULL} },
	{"3.Gyro",          M_UFunc,                NULL,               {MainMenu, NULL} },
	{"4.SRAM",          M_UFunc,                sys_SRAM,           {MainMenu, NULL} },
	{"5.M3508",         M_SMenu,                NULL,               {MainMenu, M_FastDog} },
	{"6.Servo",         M_UFunc,                sys_servo,          {MainMenu, NULL} },
	//{"7.Run a line1",    M_UFunc,               Run_Line_Trial1,     {MainMenu, NULL} },   //������,����ɾ
	{"7.GPS",           M_SMenu,                NULL,               {MainMenu, M_System} },
	//{"8.Run a line",    M_UFunc,                Run_Line_Trial,     {MainMenu, NULL} },  //�����á�����ɾ
};
//������ϵͳ���ú���
struct M_Type M_System[M_NUM]=
{	/*Name              �˵�����                ����                �ڵ�*/
  {"1.Gyro",          M_UFunc,            sys_Gyro,               {MainMenu, NULL} }, //������
  {"2.Encoder",       M_UFunc,            sys_Encoder,            {MainMenu, NULL} }, //����
  {"3.GPS",           M_UFunc,            sys_GPS,                {MainMenu, NULL} }, //GPS
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
};
struct M_Type M_FastDog[M_NUM]=
{	/*Name              �˵�����                ����                �ڵ�*/
	{"1.Location",      M_UFunc,                sys_loc3508,               {MainMenu, NULL} },
	{"2.Speed",      		M_UFunc,                sys_spd3508,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
	{" ",               M_Empty,                NULL,               {MainMenu, NULL} },
};

/********************************    END OF FILE    ***************************/
