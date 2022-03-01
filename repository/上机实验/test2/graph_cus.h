#ifndef ONE_
#define ONE_ "  *       *       *       *       *       *       *       *       *     "
#endif

#ifndef TWO_
#define TWO_ "********       *       *       **********       *       *       ********"
#endif

#ifndef THREE_
#define THREE_ "********       *       *       *********       *       *       *********"
#endif

#ifndef FOUR_
#define FOUR_ "*      **      **      **      *********       *       *       *       *"
#endif

#ifndef FIVE_
#define FIVE_ "*********       *       *       ********       *       *       *********"
#endif

#ifndef SIX_
#define SIX_ "*********       *       *       *********      **      **      *********"
#endif

#ifndef SEVEN_
#define SEVEN_ "********       *       *       *       *       *       *       *       *"
#endif

#ifndef EIGHT_
#define EIGHT_ "*********      **      **      **********      **      **      *********"
#endif

#ifndef NIGHT_
#define NIGHT_ "*********      **      **      *********       *       *       *********"
#endif

#ifndef ZERO_
#define ZERO_ "*********      **      **      **      **      **      **      *********"
#endif

#include <string>
using std::string;
string switch_str(char a)
{
    string re_left;
    switch(a)//分情况从graph_cus.h中获取对应的字符串图像
    {
        default:/*throw(runtime_error)*/break;
        case '1':re_left=ONE_;break;
        case '2':re_left=TWO_;break;
        case '3':re_left=THREE_;break;
        case '4':re_left=FOUR_;break;
        case '5':re_left=FIVE_;break;
        case '6':re_left=SIX_;break;
        case '7':re_left=SEVEN_;break;
        case '8':re_left=EIGHT_;break;
        case '9':re_left=NIGHT_;break;
        case '0':re_left=ZERO_;break;
    }
    return re_left;
}