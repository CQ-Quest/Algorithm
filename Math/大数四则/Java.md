# 四则运算

          public class Main{
          public static void main(String []args)
          {
          Scanner cin = new Scanner(new BufferedInputStream(System.in));
          while(cin.hasNext())
          {
          BigInteger a=cin.nextBigInteger();
          BigInteger b=cin.nextBigInteger();
          BigInteger c1=a.add(b);   //大数加法
          System.out.println("加的结果为 "+c1);
          BigInteger c2=a.subtract(b); //大数减法
          System.out.println("减的结果为 "+c2);
          BigInteger c3=a.multiply(b); //大数乘法
          System.out.println("乘的结果为 "+c3);
          BigInteger c4=a.divide(b); //大数除法
          System.out.println("除的结果为 "+c4);
          //BigInteger c5=a.mod(b); //大数模
          BigInteger c5=a.remainder(b);
          System.out.println("模的结果为 "+c5);
          BigInteger c6=a.max(b);//取最大
          System.out.println("最大为 "+c6);
          BigInteger c7=a.min(b); //取最小
          System.out.println("最小为 "+c7);
          if(a.equals(b)) //判断是否相等
          System.out.println("相等");
          else System.out.println("不相等");
          BigInteger c8=a.gcd(b); //求最大公约数
          System.out.println("最大公约数为 "+c8);
          }
           }
        }
        
#Java实用大数模板

       import java.util.*;
       import java.math.*;
       public class Main{
               public static void main(String args[]){
                       Scanner cin = new Scanner(System.in);
                       BigInteger a,b;
                       while (cin.hasNext()){
                               a = cin.nextBigInteger();
                               b = cin.nextBigInteger();
                               System.out.println(a.add(b));//加
                               System.out.println(a.subtract(b));//减
                               System.out.println(a.multiply(b));//乘
                               System.out.println(a.divide(b));//除
                               System.out.println(a.remainder(b));//取模
                               if( a.compareTo(b) == 0 ) System.out.println("a == b");//判断大小
                               else if( a.compareTo(b) > 0 ) System.out.println("a > b");
                               else if( a.compareTo(b) < 0 ) System.out.println("a < b");
                               System.out.println(a.abs());//绝对值
                       }
               }
       }
