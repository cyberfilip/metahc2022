#include <iostream>
using namespace std;
long long stala = 1e9 + 7;

unsigned long long calc(int a[], int n, int x[], int q) {
    sort(x, x + q);
    long long sq = 0;
    long long s = 0;
    long long result = 0;
    for (int z = 0; z < n; z++) {
        long long cordXf = x[0] - a[z];
        cordXf %= stala;
        if (cordXf < 0) {
            cordXf += stala;
        }
       // cout << cordXf << " " << stala << endl;
        s += cordXf;
        s %= stala;
        cordXf *= cordXf;
        cordXf %= stala;
        sq += cordXf;
        sq %= stala;
        //cout <<  "z:" << z << " x[0]" << x[0] << " a[z]" << a[z] << ", s:" << s << " sq:" << sq << endl;
    }
    result = sq;
    for (int g = 1; g < q; g++) {
        long long d = x[g] - x[g - 1];
        //cout << "g:" << g << ", d:" << d << endl;
        d %= stala;
        long long newS = s;
        newS += (d * n) % stala;
        newS %= stala;
        //cout << "newS:" << newS << endl;
        long long newSq = sq;
        newSq += (((d * d) % stala)*n)%stala;
        //cout << "newSq + d*d:" << newSq << endl;
        newSq %= stala;
        d *= 2;
        d %= stala;
        d *= s;
        d %= stala;
      //  cout << "2*d*s:" << d << endl;
        newSq += d;
        newSq %= stala;
      // cout << "newSq:" << newSq << endl;
        result += newSq;
        result %= stala;
        //cout <<"result:" << result <<endl;
        s = newS;
        sq = newSq;
    }
    return result;
}

int a[500001]; //drzewa
int b[500001]; //drzewa
int x[500001]; //studnie
int y[500001]; //studnie

int main() {
    //cout << stala * stala;
    int t;
    cin >> t;
    int cases = 0;
    // REMOVE
   // t=1;

    for (int i = 0; i < t; i++) {
        cases++;
        unsigned long long wynik = 0;
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> a[j] >> b[j];
        }

        int q;
        cin >> q;
        //cout << n << ' ' << q << endl;

        for (int l = 0; l < q; l++) {
            cin >> x[l] >> y[l];
        }
//        for (int g = 0; g < q; g++) {
//            for (int z = 0; z < n; z++) {
//                long long cordXf = x[g] - a[z];
//                long long cordYf = y[g] - b[z];
//                wynik += (cordXf * cordXf) % stala;
//                wynik %= stala;
//                wynik += (cordYf * cordYf) % stala;
//                wynik %= stala;
//            }
//        }
//        cout << "Case #" << cases << ": " << wynik % stala << '\n';
        unsigned long long result_x = calc(a, n, x, q);
        unsigned long long result_y = calc(b, n, y, q);
        cout << "Case #" << cases << ": " << (result_x + result_y) % stala << '\n';

    }
}