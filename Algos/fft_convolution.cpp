#include <iostream>     // std::cout
#include <complex>
#include <cmath>
using namespace std;
complex<long double>* recur(complex<long double>* a, int n){
    if(n==1){
        return a;
    }
    long double pi = acos(-1);
    // long double theta = pi*2/n;
    complex<long double> c = complex<long double>(cos(pi*2/n),sin(pi*2/n));
    complex<long double> w = complex<long double>(1,0);
    complex<long double> a_1[n/2];
    for(int i=0;i<n;i+=2){
        a_1[i/2] = a[i];
    }
    complex<long double> *y_1 = recur(a_1, n/2);
    // complex<long double> *y_1 = (complex<long double> *)malloc((n/2)*(sizeof(complex<long double>)));
    // y_1 = recur(a_1, n/2);
    complex<long double> a_2[n/2];
    for(int i=1;i<n;i+=2){
        a_2[i/2] = a[i];
    }
    // complex<long double> *y_2 = (complex<long double> *)malloc((n/2)*(sizeof(complex<long double>)));
    // y_2 = recur(a_2, n/2);
    complex<long double> *y_2 = recur(a_2, n/2);
    complex<long double> *y = (complex<long double>* )malloc(n*(sizeof(complex<long double>)));
    for(int k=0;k<=(n/2 - 1);k++){
        y[k] = y_1[k] + w*y_2[k];
        y[k+n/2] = y_1[k] - w*y_2[k];
        w = w*c;
    }
    return y;
}
complex<long double>* recur2(complex<long double>* a, int n){
    if(n==1){
        return a;
    }
    long double pi = acos(-1);
    // long double theta = acos(-1)*(-2)/n;
    complex<long double> c = complex<long double>(cos(pi*(-2)/n),sin(pi*(-2)/n));
    complex<long double> w = complex<long double>(1,0);
    complex<long double> a_1[n/2];
    for(int i=0;i<n;i+=2){
        a_1[i/2] = a[i];
    }
    // complex<long double> *y_1 = (complex<long double> *)malloc((n/2)*(sizeof(complex<long double>)));
    // y_1 = recur2(a_1, n/2);
    complex<long double> *y_1 = recur2(a_1, n/2);
    complex<long double> a_2[n/2];
    for(int i=1;i<n;i+=2){
        a_2[i/2] = a[i];
    }
    // complex<long double> *y_2 = (complex<long double> *)malloc((n/2)*(sizeof(complex<long double>)));
    // y_2 = recur2(a_2, n/2);
    complex<long double> *y_2 = recur2(a_2, n/2);
    complex<long double> *y = (complex<long double>* )malloc(n*(sizeof(complex<long double>)));
    for(int k=0;k<=(n/2 - 1);k++){
        y[k] = y_1[k] + w*y_2[k];
        y[k+n/2] = y_1[k] - w*y_2[k];
        w = w*c;
    }
    return y;
}
int main ()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int N=1;
        while(N<2*n){
            N*=2;
        }
        // N*=2;
        std::complex<long double> x[N];
        std::complex<long double> y[N];
        long double i1,r;
        for(int i=0;i<n;i++){
            cin>>r>>i1;
            x[i] = complex<long double>(r,i1);
        }
        for(int i=n;i<N;i++){
            x[i]={0,0};
        }
        for(int i=0;i<n;i++){
            cin>>r>>i1;

            y[i]=complex<long double>(r,i1);
        }
        for(int i=n;i<N;i++){
            y[i]=complex<long double>(0,0);  //y[i]=complex(0,0);
        }
        complex<long double> *x1 = (complex<long double>* )malloc(N*(sizeof(complex<long double>)));
        x1 = recur(x, N);
        // for(int i=0;i<N;i++){
        //     printf("(%.3lf,%.3lf)\n",real(x1[i]),imag(x1[i]));
        // }
        complex<long double> *y1 = (complex<long double>* )malloc(N*(sizeof(complex<long double>)));
        y1 = recur(y,N);
        // for(int i=0;i<N;i++){
        //     printf("(%.3lf,%.3lf)\n",real(y1[i]),imag(y1[i]));
        // }
        complex<long double> *ans = (complex<long double>* )malloc(N*(sizeof(complex<long double>)));
        for(int i=0;i<N;i++){
            ans[i] = y1[i] * x1[i];
            // cout<<ans[i]<<"\n";
            // real(ans[i]) = 
        } 
        complex<long double> *ans1 = (complex<long double> *)malloc(N*(sizeof(complex<long double>)));
        ans1 = recur2(ans, N);
        complex<long double> div = complex<long double>(N*1.0,0.0);
        for(int i=0;i<N;i++){
            ans1[i] = ans1[i]/div;
            long double a1 = real(ans1[i]);
            long double a2 = imag(ans1[i]);
            if(a1>=-0.0005 && a1<0){
                a1=0.0;
            }
            if(a2>=-0.0005 && a2<0){
                a2=0.0;
            }
            printf("(%.3Lf,%.3Lf)\n",a1,a2);
        }
    }    


    return 0;

}