# GCD定义

     整数a和b的最大公因数是指能同时整除a和b的最大整数，记为gcd(a, b)。
     例如：gcd(15, 81) = 3，gcd(0, 44) = 44，gcd(0, 0) = 0，gcd(-6, -15) = 3，gcd(-17，289) = 17。
     注意：由于-a的因子和a的因子相同，因此gcd(a, b) = gcd(|a|, |b|)。编码时只需要关注正整数的最大公因数。
# GCD性质

    （1）gcd(a,b) = gcd(a, a+b) = gcd(a, ka+b)
    （2）gcd(ka, kb) = k·gcd(a, b)
    （3）定义多个整数的最大公约数：gcd(a, b, c) = gcd(gcd(a, b), c)
    （4）若gcd(a, b) = d，则gcd(a/d, b/d) = 1，即a/d与b/d互素。这个定理很重要。
    （5）gcd(a+cb, b) = gcd(a, b)

#LCM

     int LCM(int a,int b){
         return a/__gcd(a,b) * b;
     }
