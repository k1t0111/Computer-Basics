# @Name:K1t0
# @Time: 24/4/10
# @des: 维吉尼亚

def Encode(m,num,list1):
    # 密文c
    c=""
    count=0
    for i in m:
        if count==num:
            count=0
        # 位置
        pos=(dict1.find(i)+list1[count])%26
        c+=dict1[pos]
        count+=1
    return c

def Decode(c,num,list1):
    # 明文m
    m=""
    count=0
    for i in c:
        if count==num:
            count=0
        # 位置
        pos=(dict1.find(i)-list1[count])%26
        m+=dict1[pos]
        count+=1
    return m

# 字母表
dict1="abcdefghijklmnopqrstuvwxyz"
# 分析key
def  Analyze_key(key):
    # 计数
    num=len(key)
    list1=[]
    for i in range(num):
        # 找位移
        list1.append(dict1.find(key[i]))
    return list1

if __name__=="__main__":

    # 判断
    judge=eval(input("加密(1)OR解密(0)"))

    if judge==1:
        # m 明文
        m=input("输入明文")
        key=input("输入密钥")
        num = len(key)
        list1=Analyze_key(key)
        print(list1)
        print("密文:",Encode(m,num,Analyze_key(key)))
    else:
        # c 密文
        c=input("输入密文")
        key=input("输入密钥")
        Analyze_key(key)
        num = len(key)
        list1=Analyze_key(key)
        print("明文:",Decode(c,num,list1))
