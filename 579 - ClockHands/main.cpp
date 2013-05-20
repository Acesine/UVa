#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int h;
    char t,s;
    scanf("%d:%c%c",&h,&t,&s);
    int m = (t-'0')*10+(s-'0');
    while(h!=0 || m!=0)
    {
        double angh = 360.0/12*(h+1.0*m/60);
        double angm = 360.0/60*m;
        double diff = fabs(angh-angm);
        if(diff>=180)
            diff = 360-diff;
        printf("%.3f\n",diff);

        scanf("%d:%c%c",&h,&t,&s);
        m = (t-'0')*10+(s-'0');
    }
    return 0;
}
