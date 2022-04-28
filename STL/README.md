#  输出小数点后精准位数 #  
      #include<iomanip>    //流操作符头文件  
      cout<<fixed<<setprecision(4)<<n<<endl;     //精确到小数点后4位


#   全排列函数 next_permutation #  

      #include<bits/stdc++.h> 
      int main(){
         int n;  
         cin>>n;  
         string s;  
         while(n--){  
         cin>>s;  
         sort(s.begin(),s.end());  
         do{  
            cout<<s<<endl;  
         }while(next_permutation(s.begin(),s.end()));  
         cout<<endl;  
         }  
      }  



# 概率随机数    

      #include<ctime》   
      srand((unsigned)time(NULL));     //保证随机分配种子(在循环之外)    
       for(int i=1;i<=10;i++)  
             i=rand() % 2;                //50%的机率  

         for(int i=1;i<=100;i++)  
         i=rand()%100+1;               //从0到100随机取数  
   
   


   
# 字符串处理

     getline(cin,str)等同于cin.getline(str,x).其中x为要读取的元素个数
     strlen()、strcpy()等字符串处理函数，只有字符串数组可以用；
     size()、length()是string类的方法，只有string类可以用。
     size()与length()完全等同，遇到空字符不会被截断，可以返回字符串真实长度；
     strlen()遇到空字符串会被截断，无法返回字符串真实长度。
     对字符串后四位特殊处理，从而得到年份
     string类中的substr()函数：截取字符串中的子串。如：

       string s1=s.substr(4);    //从下标4开始一直到结束
       string s2=s.substr(5,3);    //从下标5开始，3个字符
