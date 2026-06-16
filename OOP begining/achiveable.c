#include <stdio.h>
int theMaximumAchievableX(int num, int t)
{
    int count = 0;
    int i;
    if (num > t)
    {
        for (i = 1; i <= num; i++)
        {
            count++;
        }
        return count;
    }
    else if (num < t)
    {
        for (i = 1; i <= num; i++)
        {
            count++;
        }
        return count;
    }
    else
    {
        return count;
    }
}
int main()
{
    int num = 5;
    int t = 2;

    if (num > t)
    {
        for (i = 1; i <= num; i++)
        {
            count++;
        }
        return count;
    }
    else if (num < t)
    {
        for (i = 1; i <= num; i++)
        {
            count++;
        }
        return count;
    }
    else
    {
        return count;
    }

    return 0;
}