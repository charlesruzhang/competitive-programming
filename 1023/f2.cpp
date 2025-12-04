#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    const double h = sqrt(3.0)/2.0;
    const double PI = acos(-1.0);

    // Case 1: all triangles
    bool anyS = false, anyC = false, anyT = false;
    for(char c : s){
        anyS |= (c=='S');
        anyC |= (c=='C');
        anyT |= (c=='T');
    }
    if(!anyS && !anyC){
        // all T
        double P = 2.0*n + 1.0;
        cout << fixed << setprecision(10) << P << "\n";
        return 0;
    }
    // Case 2: all circles
    if(!anyS && !anyT){
        // all C
        double P = 2.0*(n-1) + PI;
        cout << fixed << setprecision(10) << P << "\n";
        return 0;
    }

    // Case 3: baseline emerges (any S or any T present)
    //  find first/last non‐T (i.e. square or circle)
    int l = 0, r = n-1;
    while(l<n && s[l]=='T') ++l;
    while(r>=0 && s[r]=='T') --r;
    // compute x_start, x_end on top line y=1
    double x_start = (l + (s[l]=='C'? 0.5 : 0.0));
    double x_end   = (r + 1 - (s[r]=='C'? 0.5 : 0.0));

    // bottom
    double P = n;

    // top
    P += (x_end - x_start);

    // helper to add side for a circle support
    auto circle_side = [&](double px, double py, double cx, double cy){
        // tangent from P=(px,py) to circle center (cx,cy), radius r=0.5
        double ux = px - cx, uy = py - cy;
        double L2 = ux*ux + uy*uy;
        double r2 = 0.25;
        double a = r2 / L2;
        double b = 0.5 * sqrt(max(0.0, L2 - r2)) / L2;
        double pxp = -uy, pyp = ux;   // perp(u)
        // choose the tangent that goes *upwards* towards y=1
        // left‐side: minus; right‐side: plus—we'll adjust externally.
        return tuple<double,double,double>(a, b, /*we'll use pxp,pyp too*/0);
    };
    // Actually let's write each side inline:

    // Left side from (0,0) up to (x_start,1)
    if(s[l]=='S'){
        P += hypot(x_start - 0.0, 1.0 - 0.0);
    } else {
        // circle
        double cx = x_start, cy = 0.5;
        double px0 = 0.0, py0 = 0.0;
        double ux = px0 - cx, uy = py0 - cy;
        double L2 = ux*ux + uy*uy;
        double a = 0.25 / L2;
        double b = 0.5 * sqrt(max(0.0, L2 - 0.25)) / L2;
        double perp_x = -uy, perp_y = ux;
        // tangent point T_l
        double tx = cx + a*ux - b*perp_x;
        double ty = cy + a*uy - b*perp_y;
        double lineLen = hypot(tx - px0, ty - py0);
        double angT = atan2(ty - cy, tx - cx);
        double arcLen = 0.5 * fabs( (PI/2) - angT );
        P += lineLen + arcLen;
    }

    // Right side from (x_end,1) down to (n,0)
    if(s[r]=='S'){
        P += hypot((double)n - x_end, 1.0 - 0.0);
    } else {
        // circle
        double cx = x_end, cy = 0.5;
        double px0 = n,   py0 = 0.0;
        double ux = px0 - cx, uy = py0 - cy;
        double L2 = ux*ux + uy*uy;
        double a = 0.25 / L2;
        double b = 0.5 * sqrt(max(0.0, L2 - 0.25)) / L2;
        double perp_x = -uy, perp_y = ux;
        // tangent point T_r
        double tx = cx + a*ux + b*perp_x;
        double ty = cy + a*uy + b*perp_y;
        double lineLen = hypot(tx - px0, ty - py0);
        double angT = atan2(ty - cy, tx - cx);
        double arcLen = 0.5 * fabs( (PI/2) - angT );
        P += lineLen + arcLen;
    }

    cout << fixed << setprecision(10) << P << "\n";
    return 0;
}
