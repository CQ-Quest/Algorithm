1.自定义比较函数  
a.元素不是结构体  

      struct cmp{
      bool operator() (const int &a ,const int &b){
      return a > b;
      }
      };
      set<int,cmp> s; 

b.元素是结构体  

      struct info{
      string name;
      double score;
      bool operator < (const inof &a) const{
      return a.score<score;
      }
      };
      set<info> s;
      
      
2.vector  
(1).创建  

    vector<int> v;
    vector<double> v(10,8.6)        //定义了 v 向量容器，有10个元素，每个元素的值为8.6；
    //注意此处与数组相比,优势是可以不用遍历，直接将所需的元素赋同一初值8.6。  

(2)添加元素    

    v.push_back(2);                 在容器尾部追加新元素2。
    v.insert(v.begin()+2,8);           在第二个元素前面插入8
    （注意：vector容器的元素统计和数组的下标一样都是从零开始）
     括号里面（迭代器位置，需要插入的元素值）
 
(3).删除元素   

      v.clear();                              清空容器
      v.erase(v.begin()+2);                删除第2个元素（从0开始计数）
      v.erase(v.begin()+2;v.begin()+5);   删除第2个元素到第5个之间
(4).向量的大小  

    v.size();                               返回元素个数
    v.empty();                             判断是否为空，非空 返回0，空  返回1
(5)元素访问、遍历  
用迭代器访问元素  

      vector<int>::iterator it;
      for(it=v.begin();it!=v.end();it++)
      用下标像数组那样
      for(i=0;i<v.size();i++)
      cout<<v[i]<<endl;

(6)元素反向排列与排序            

      反向排列：reverse(v.begin(),v.end());
      排序：
      sort(v.begin(),v.end());                升序
      sort(v.begin(),v.end()，cmp);        根据排序函数cmp排序 

3.map,unordered_map
