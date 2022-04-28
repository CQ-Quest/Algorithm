#输入和精度问题

多组数据输入

     while True:
           try:
              a,b,c=map(int,input().split())
              print(a+b+c)
           except:
                  break


实现特定次数输入(1)

    n=int(input())
    print(n,type(n))
    i=0
    while i<n:
            a,b,c=map(int,input().split())
            print(a+b+c)
            i+=1
        
实现特定次数输入(2)

    n=int(input())
    print(n,type(n))
    for i in range(0,n):
          a,b,c=map(int,input().split())
          print(a,type(a))
          print(b,type(b))
          print(c,type(c))
          
精度
   
    强制截断  #保留三位小数
    print(int(1.234567*1000)/1000)
    
    四舍五入
    f=1.23456
    print('%.4f' % f)
    print(format(f,'.2f'))
    
   
