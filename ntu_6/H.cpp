#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
struct vec{
    int dim;
    double x[101];
};
struct suplane{
    int dim,num;
    struct vec center,norm;
    struct vec a[101];
    double b;
};
vec add(vec a, vec b){
    vec c;
    c.dim = a.dim;
    for(int i = 1; i <= a.dim; i++){
        c.x[i] = a.x[i] + b.x[i];
    }
    return c;
}
vec sub(vec a, vec b){
    vec c;
    c.dim = a.dim;
    for(int i = 1; i <= a.dim; i++){
        c.x[i] = a.x[i] - b.x[i];
    }
    return c;
}
vec aver(vec sum, int num){
    vec c;
    for(int i = 1; i <= sum.dim; i++){
        c.x[i] = sum.x[i] / num;
    }
    return c;
}
vec mul(vec a, double b){
    vec c;
    c.dim = a.dim;
    for(int i = 1; i <= a.dim; i++){
        c.x[i] = a.x[i] * b;
    }
    return c;
}
vec cen(suplane a){
    vec c,sum;
    c.dim = a.dim;
    sum= a.a[1];
    for(int i = 2; i <= a.dim; i++){
        sum= add(sum, a.a[i]);
    }
    c = aver(sum, a.dim);
    return c;
}
double dot(vec a, vec b){
    double c = 0;
    for(int i = 1; i <= a.dim; i++){
        c += a.x[i] * b.x[i];
    }
    return c;
}
 vec normal_vec(suplane a){
    int n = a.dim;
    vec norm;
    norm.dim = n;
    for(int i = 1; i <= n; ++i) {
        norm.x[i] = 0;
    }
    double matrix[101][101];
    for(int i = 1; i < n; ++i) {
        vec diff = sub(a.a[i+1], a.a[1]);
        for(int j = 1; j <= n; ++j) {
            matrix[i][j] = diff.x[j];
        }
    }

    for(int i = 1; i < n; ++i) {
        matrix[n][i] = 0;
    }
    matrix[n][n] = 1;
    double result[101] = {0};
    result[n] = 1;

    for(int i = 1; i < n; ++i) {
        double sum = 0;
        for(int j = 1; j <= n; ++j) {
            sum += matrix[i][j] * result[j];
        }
        norm.x[i] = -sum / matrix[i][i];
    }

    norm.x[n] = 1;

    return norm;
}
vec normalize( vec a){
    vec c;
    c.dim = a.dim;
    double sum = 0;
    for(int i = 1; i <= a.dim; i++){
        sum += a.x[i] * a.x[i];
    }
    sum = sqrt(sum);
    for(int i = 1; i <= a.dim; i++){
        c.x[i] = a.x[i] / sum;
    }
    return c;
}
double dis(vec a, vec b){
    double c = 0;
    for(int i = 1; i <= a.dim; i++){
        c += (a.x[i] - b.x[i]) * (a.x[i] - b.x[i]);
    }
    c = sqrt(c);
    return c;
}
long long t,i,j,n,m,tt;
suplane p[101];
vec v[101];
double di;
int main() {
    cin>>t;
    tt=0;
    while(t--){
        tt++;
        cin>>n>>m;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                cin>>v[i].x[j];
            }
        }
        p[m].dim=m;
        p[m].num=m;
        for(i=1;i<=m;i++){
            p[m].a[i]=v[i];
        }
        p[m].center=cen(p[m]);
        p[m].norm=normalize(normal_vec(p[m]));
        p[m].b=dot(p[m].norm,p[m].center);
        for(i=m;i<=n;i++){
            if(i!=m){
                p[i]=p[i-1];
                p[i].dim=i;
                p[i].num=i;
                p[i].a[i]=v[i];
                p[i].center=cen(p[i]);
                p[i].norm=normalize(normal_vec(p[i]));
                p[i].b=dot(p[i].norm,p[i].center);
            }
            di=dis(p[i].center,v[1]);
            di= sqrt(1-di*di);
            v[i+1]= add(p[i].center,mul(p[i].norm,di));
        }
        cout<<"Case #"<<tt<<":\n";
        for(i=m+1;i<=n+1;i++){
            for(j=1;j<=n;j++){
                cout<<v[i].x[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
