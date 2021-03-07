//created by TheAcOH
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a;//样本测定值个数
    double R;//极差
    double R_1;double R_2;//可疑值与其最邻近样本之差
    double q_1;double q_2;//统计量
    int Q_;//置信度
    int i;//数组末项项数
    int j;//数组首项项数
    double x = 0;//平均值
    cout<<"Please input the number of measured values： "<<endl;
    cin >> a;
    double A[a];//用数组A存放数据样本
    if (a <= 3 or a >= 10)
    {
        //排除测定值不合规范的情况
        cout<<"Q-test is suitable for the tests with 3 -10 measured values."<<endl;
        system("pause");
        system("cls");
    }
    else
    {
        //依次输入测定值
        for(int e = 0; e < a; e++)
        {
            double n;
            cout<<"Please input NO."<< e + 1 <<" measured value."<<endl;
            cin >> n;
            A[e] = n;
        }
        //确定置信度
        cout<<"Please input the confidence level as a percentage, and remember to delete'%'."<<endl;
        cin >> Q_;
        //冒泡排序 将测定值从小到大排序
        for(int c = 0; c < a - 1; c++)
        {
            for (int d = 0; d < a - c - 1; d++)
            {
                if(A[d] > A[d + 1])
                {
                    double temp = A[d];
                    A[d] = A[d + 1];
                    A[d + 1] = temp;
                }
            }
        }
//测试冒泡排序
//        for(int i = 0; i < a ;i++)
//        {
//            cout<<A[i]<<" " ;
//        }
        for(i = a - 1, j = 0 ; (i - j) > 0 ; i-- , j++)
        {
            double Q;
            switch(Q_)
            {
                case 90 :
                    if (a == 3)
                    {
                        Q = 0.95;
                    }
                    else if(a == 4){
                        Q = 0.76;
                    }
                    else if(a == 5){
                        Q = 0.64;
                    }
                    else if(a == 6){
                        Q = 0.56;
                    }
                    else if(a == 7){
                        Q = 0.51;
                    }
                    else if(a == 8){
                        Q = 0.47;
                    }
                    else if(a == 9){
                        Q = 0.44;
                    }
                    else if(a == 10){
                        Q = 0.41;
                    }
                    break;
                case 95 :
                    if (a == 3)
                    {
                        Q = 0.98;
                    }
                    else if(a == 4){
                        Q = 0.85;
                    }
                    else if(a == 5){
                        Q = 0.73;
                    }
                    else if(a == 6){
                        Q = 0.64;
                    }
                    else if(a == 7){
                        Q = 0.59;
                    }
                    else if(a == 8){
                        Q = 0.54;
                    }
                    else if(a == 9){
                        Q = 0.51;
                    }
                    else if(a == 10){
                        Q = 0.48;
                    }
                    break;
                case 99 :
                    if (a == 3)
                    {
                        Q = 0.99;
                    }
                    else if(a == 4){
                        Q = 0.93;
                    }
                    else if(a == 5){
                        Q = 0.82;
                    }
                    else if(a == 6){
                        Q = 0.74;
                    }
                    else if(a == 7){
                        Q = 0.68;
                    }
                    else if(a == 8){
                        Q = 0.63;
                    }
                    else if(a == 9){
                        Q = 0.60;
                    }
                    else if(a == 10){
                        Q = 0.57;
                    }
                    break;
                default:
                    cout<<"The confidence level of input is illegal."<<endl;
                    system("pause");
                    system("cls");
            }
            //求极差
            R = A[i] - A[j];
            //求出可疑值与其最邻近值之差
            R_1 = A[j + 1] - A[j];
            R_2 = A[i] - A[i - 1];
            //求统计量
            double q;
            q_1 = (R_1) / R;
            q_2 = (R_2) / R;
            if(q_1 > q_2)//由于目前不知道q_1与q_2相等时如何做数据的取舍，故不考虑该情况。
            {
                q = q_1;
                if(q <= Q)
                {
                    for(int t = j; t <= i ; t++)
                    {
                        cout<<A[t]<<"  ";

                    }
                    break;
                }
                else
                {
                    i++;
                    a--;
                }
            }
            else
                {
                q = q_2;
                if(q <= Q)
                {
                    for(int t = j; t <= i; t++)
                    {
                        cout<<A[t]<<"  ";
                    }
                    break;
                }
                else
                {
                    j--;
                    a--;
                }
            }

        }
        cout<<endl<<"The above is the sample retained after removing the suspicious value： "<<endl<<endl;
        //计算平均值
        for(int i_ = j; i_ <= i; i_++)
        {
            double x_;
            x_ = (A[i_]) / (i - j + 1);
            x = x + x_;
        }
        cout<<"The average value is: "<<x<<endl<<endl;
        //计算标准偏差
        double s_1 = 0;
        for(int i_ = j; i_ <= i; i_++)
        {
            double s_;
            s_ = (A[i_] - x) * (A[i_] - x);
            s_1 = s_1 + s_;
        }
        double S = sqrt((s_1)/(i - j));
        cout<<"The standard deviation is: "<<S<<endl<<endl;
        //计算变异系数
        double CV;
        CV = S / x;
        cout<<"The Coefficient of Variation is: "<<CV<<endl;
    }
    system("pause");
    return 0;
}
