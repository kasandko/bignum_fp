# bfp::remainder info

Algorithm:
```cpp
float remainder(float x, float y)
{
    float r = x / y;
    float ir = float(int(r));
    bool sgn = ir >= 0.0f;
    float ir_next = sgn ? ir + 1.0 : ir - 1.0;

    float k1 = ir_next - r;
    float k2 = r - ir;

    if (!sgn)
    {
        k1 = -k1;
        k2 = -k2;
    }

    float nearest = k1 < k2 ? ir_next : ir;
    return x - nearest * y;
}
```

Tests:
* p1 = 7.0, p2 = 5.0
    * remainder(+p1, +p2) == 2
    * remainder(+p1, -p2) == 2
    * remainder(-p1, +p2) == -2
    * remainder(-p1, -p2) == -2
* p1 = 5.0, p2 = 3.0
    * remainder(+p1, +p2) == -1
    * remainder(+p1, -p2) == -1
    * remainder(-p1, +p2) == 1
    * remainder(-p1, -p2) == 1
* p1 = 5.0, p2 = 2.0
    * remainder(+p1, +p2) == 1
    * remainder(+p1, -p2) == 1
    * remainder(-p1, +p2) == -1
    * remainder(-p1, -p2) == -1
