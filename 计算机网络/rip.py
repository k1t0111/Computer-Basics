# @author:K1t0
# @description:  内网网关算法rip
# @Time: 24-5-1

## 路由器

def route(Table_Side,Sou_Route):
    # 内部路由表
    Self_Table=[["192.168.49.1",1,"route3"],["192.168.49.2",2,"route1"]]
    # 开始处理
    for i in range(0,len(Table_Side)):
        Table_Side[i][1]+=1
        Table_Side[i][2]=Sou_Route
    ## 开始匹配
    ## 将本地路由表内容的首个字段网段放进 列表方便查找 pos
    list1=[]
    for i in range(0,len(Self_Table)):
        list1.append(Self_Table[i][0])
    ## 先看网段  后看路由器名字 之后再看距离大小
    for i in Table_Side:
        if i[0] in list1:
        #pos 表示 下标
            pos=list1.index(i[0])
            if i[2] == Self_Table[pos][2]:
                Self_Table[pos]=i
            else:
                if i[1] <=Self_Table[pos][1]:
                    Self_Table[pos]=i
        else:
            Self_Table.append(i)
    print(Self_Table)

if __name__ == "__main__":
    ## 测试
    Table_Side=[["192.168.49.3",2,"route2"],["192.168.49.1",2,"直接交付"],["192.168.49.2",1,"route4"]]
    route(Table_Side,"route3")





