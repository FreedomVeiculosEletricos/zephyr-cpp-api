#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

#ifdef __cplusplus
}
#endif

#endif // _CALCULATOR_H_