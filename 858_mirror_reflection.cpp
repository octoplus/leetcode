#include<bits/stdc++.h>

using namespace std;

// 本题关键在于光线会在左右两面镜子之间来回反射，而且每反射一次，就会向上升q的距离
// 就算触顶反射了，只是改变方向，上升或下降的距离是一样的

int mirrorReflection(int p, int q) {
    while (p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p % 2 + q % 2;
}

int main(){
    cout<<mirrorReflection(2,1)<<endl;
    return 0;
}