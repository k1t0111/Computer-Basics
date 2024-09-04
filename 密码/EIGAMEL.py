# @author:K1t0
# @time:24/5/26
# @description: 实现 eigamal算法


import math
# 函数功能:实现 eigamal算法的加密 参数 Pk 公钥 g y  k  p  作为素数 M 明文
def Enc_EiGamal(Pk,M,p):
    C=[]
    c1 = pow(Pk[0], Pk[2], p)
    c2 = (M * pow(Pk[1], Pk[2], p)) % p
    C.append(c1)
    C.append(c2)
    return C

# 函数功能:实现 eigamal算法的解密 Nk 私钥x  C 密文
def Dec_EiGamal(Nk,C,p):
    C1_inv = pow(C[0], -Nk, p)
    # 计算 M' = C1^-d * C2
    M_prime = (C1_inv * C[1]) % p
    return M_prime

if __name__=="__main__":
    # 输入公钥
    d = 6
    h = pow(10, d, 97)
    Pk=[10,h,97]
    p=97
    M=42
    Nk=6
    C = Enc_EiGamal(Pk, M, p)
    print("加密:",C)
    print("解密",Dec_EiGamal(Nk,C,p))





