// exercise 7-7.c
/*
编写程序，要求输入一周中的工作小时数，然后打印工资总额、税金以及净工资。作如下假设：
    a.基本工资等级=10.0美元/小时
    b.加班（超过40小时）=1.5倍的时间
    c.税率    前300美元为15%
              下一个150美元为20%
              余下的为25%
用#define定义常量，不必关心本例是否符合当前的税法。
 */

#include <stdio.h>

#define BASEPAY 10.0
#define BASEHRS 40
#define OTPAY 1.5 * BASEPAY
#define BREAK1 300
#define BREAK2 150
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25

int main(void) {
    double hours;
    double pay;
    double taxes;
    double rest;

    printf("请输入一周的工作小时数："); 
    scanf("%lf", &hours);
    if(hours <= BASEHRS) {
        pay = BASEPAY * hours;
    } else {
        pay = BASEPAY * BASEHRS + (hours - BASEHRS) * OTPAY;
    }

    if(pay <= BREAK1) {
        taxes = pay * RATE1;
    } else if(pay <= BREAK1 + BREAK2) {
        taxes = BREAK1 * RATE1 +(pay - BREAK1) * RATE2;
    } else {
        taxes = BREAK1 * RATE1 + BREAK2 * RATE2+(pay - BREAK1 - BREAK2) * RATE3;
    }

    rest = pay - taxes; 
    printf("一周中工作%.2lf小时，工资为%.2lf美元，税金%.2lf美元，净工资%.2lf美元。\n", 
           hours, pay, taxes, rest);

    return 0;
}
//新建的new branch分支
