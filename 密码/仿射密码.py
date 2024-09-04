# 字母表
dict1="abcdefghijklmnopqrstuvwxyz"
def Decode(c,k1,k2):
    x, y = get(k1,k2)
    #x0为逆元
    x0 = x % 26
    # 明文m
    m=""
    for i in c:
        # 找到索引位置
        pos=((dict1.find(i)-k2)*x0)%26
        m+=dict1[pos]
    return m

# 加密模块
def Encode(m,k1,k2):
    # 明文m
    c=""
    for i in m:
        # 找到索引位置
        pos=(dict1.find(i)*k1+k2)%26
        c+=dict1[pos]
    return c

# 判断有无逆元

# 欧几里德算法求最大公约数
def gcd(a, b):
    remainder = a % b
    while remainder != 0:
        a = b
        b = remainder
        remainder = a % b
    return b


# 欧几里得扩展算法求线性方程的x与y
def get(a, b):
    if b == 0:
        return 1, 0
    else:
        k = a // b
        remainder = a % b
        x1, y1 = get(b, remainder)
        x, y = y1, x1 - k * y1
    return x, y


if __name__=="__main__":
    # 判断
    judge=input("加密(1)OR解密(0)")
    if judge==1:
        # m 明文
        m=input("输入明文")
        key1,key2=input("输入密钥").split()
        # 判断是否 正确 密钥
        flag = gcd(key1, key2)
        if flag==1:
            print("密文:",Encode(m,int(key1),int(key2)))
        else:
            print("密钥出错")
    else:
        # c 密文
        c=input("输入密文")
        key1,key2=input("输入密钥").split()
        key1=int(key1)
        key2=int(key2)
        flag = gcd(key1,key2)
        if flag==1:
            print("明文:",Decode(c,key1,key2))
        else:
            print("密钥出错")
