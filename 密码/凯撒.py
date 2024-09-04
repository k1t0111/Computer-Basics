dict1="abcdefghijklmnopqrstuvwxyz"
def Decode(c,n):
    # 明文m
    m=""
    for i in c:
        # 找到索引位置
        pos=(dict1.find(i)-n)%26
        m+=dict1[pos]
    return m
# 加密模块
def Encode(m,n):
    # 明文m
    c=""
    for i in m:
        # 找到索引位置
        pos=(dict1.find(i)+n)%26
        c+=dict1[pos]
    return c
if __name__=="__main__":
    # 判断
    judge=input("加密(1)OR解密(0)")
    if judge==1:
        # m 明文
        m=input("输入明文")
        key=eval(input("输入密钥"))
        print("密文:",Encode(m,key))
    else:
        # c 密文
        c=input("输入密文")
        key=eval(input("输入密钥"))
        print("明文:",Decode(c,key))