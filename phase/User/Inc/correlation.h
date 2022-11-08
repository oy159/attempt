//
// Created by 86187 on 2022/10/25.
//
#ifndef CORRELATION_H
#define CORRELATION_H

/***********************************************
本文件为基于arm dsp库，利用fft加速计算互相关或自相关的支持库
一、使用指南
		在使用前务必在cube 上方魔术棒右数第三个图标 Manage Run-Time Environment
																	中点击CMSIS左侧加号，弹出菜单中勾选DSP库，单击下侧ok以自动装载dsp库
																	其他IDE请自行配置以保证DSP库正常运行

二、更新日志
			7.28 文档建立
			7.29 补充直接计算相位，不需要完整自相关序列
***********************************************/

#include "fft_user.h"


void real_to_im_f32(float * DataBuffer,int NPT);
/***********************************************************
*功能：计算序列互相关，AB相同时为自相关											*
*参数：1.DataBufferA：互相关序列A  要求float类型，纯实数，函数内自动转化为虚数，大小要求为NPT的四倍以上
*			 2.DataBufferB:	互相关序列B  要求float类型，纯实数，函数内自动转化为虚数，大小要求为NPT的四倍以上
*			 3.NPT：        转换点数，或者序列长度
*输出说明：
*  		 输出储存在DataBufferA内，前2*NPT-1为有效输出，后续数据混乱，不会自动补零
*注意事项：
*  		 NPT尽量基2，基4以避免不可预知的问题
************************************************************/
void xcorr(float * DataBufferA,float * DataBufferB,int NPT);
/***********************************************************
*功能：计算序列互相关的序列0，AB相同时为自相关											*
*参数：1.DataBufferA：互相关序列A  要求float类型，纯实数，大小要求为NPT
*			 2.DataBufferB:	互相关序列B  要求float类型，纯实数，大小要求为NPT
*			 3.NPT：        转换点数，或者序列长度
************************************************************/
float xcorr0(float * DataBufferA,float * DataBufferB,int NPT);
/***********************************************************
*功能：计算序列相位差								*
*参数：1.DataBufferA：互相关序列A  要求float类型，纯实数，大小要求为NPT
*			 2.DataBufferB:	互相关序列B  要求float类型，纯实数，大小要求为NPT
*			 3.NPT：        转换点数，或者序列长度
************************************************************/
float get_phase(float * DataBufferA,float * DataBufferB,int NPT);
/***********************************************************
*功能：计算序列的PHAT广义互相关，AB相同时为自相关											*
*参数：1.DataBufferA：互相关序列A  要求float类型，纯实数，函数内自动转化为虚数，大小要求为NPT的四倍以上
*			 2.DataBufferB:	互相关序列B  要求float类型，纯实数，函数内自动转化为虚数，大小要求为NPT的四倍以上
*			 3.NPT：        转换点数，或者序列长度
*输出说明：
*  		 输出储存在DataBufferA内，前2*NPT-1为有效输出，后续数据混乱，不会自动补零
*注意事项：
*  		 NPT尽量基2，基4以避免不可预知的问题
************************************************************/
void PHAT_xcorr(float * DataBufferA,float * DataBufferB,int NPT);


#endif //CORRELATION_H