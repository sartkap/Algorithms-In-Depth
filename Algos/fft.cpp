#include <iostream>     // std::cout
#include <complex>      // std::complex, std::real
using namespace std;
complex<double>* recur(complex<double>* a, int n){
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    if(n==1){
        return a;
    }
    double theta = M_PI*2/n;
    complex<double> c = {cos(theta),sin(theta)};
    complex<double> w = {1,0};
    complex<double> a_1[n/2];
    for(int i=0;i<n;i+=2){
        a_1[i/2] = a[i];
    }
    complex<double> *y_1 = recur(a_1, n/2);
    complex<double> a_2[n/2];
    for(int i=1;i<n;i+=2){
        a_2[i/2] = a[i];
    }
    complex<double> *y_2 = recur(a_2, n/2);
    complex<double> *y = (complex<double>* )malloc(n*(sizeof(complex<double>)));
    for(int k=0;k<=(n/2 - 1);k++){
        y[k] = y_1[k] + w*y_2[k];
        y[k+n/2] = y_1[k] - w*y_2[k];
        w = w*c;
    }
    return y;
}
int main ()
{    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin>>t;
    // cout<<t;
    while(t--){
        int n;
        cin>>n;
        // cout<<n;
        int N=1;
        while(N<n){
            N*=2;
        }
        // cout<<N<<"\n";
        std::complex<double> x[N];
        double i1,r;
        for(int i=0;i<n;i++){
            cin>>r>>i1;
            // cout<<r<<i;
            x[i] = {r,i1};
            // cout<<x<<"\n";
        }
        for(int i=n;i<N;i++){
            x[i]={0,0};
        }
        // for(int i=0;i<N;i++){
        //     cout<<x[i]<<" ";
        // }
        // cout<<"\n";
        complex<double> *y = (complex<double>* )malloc(N*(sizeof(complex<double>)));
        y = recur(x, N);
        for(int i=0;i<N;i++){
            // cout<<y[i]<<"\n";
            printf("(%.3lf,%.3lf)\n",real(y[i]),imag(y[i]));
            // printf("%.3lf",x[i]);
            // cout<<fixed<<setprecision(3)<<y[i]<<"\n";
        }

    }    


    return 0;

}