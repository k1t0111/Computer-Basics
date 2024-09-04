# @author: K1t0
# @descruption: 路由器分组转发算法
# @time: 24/4/14

# 路由1
def Route1(ip):
    #路由表
    list1={"192.168.1.0":"内部","192.168.2.0":"路由2","192.168.3.0":"路由2"}
    a,b,c,d=ip.split(".")
    #目的网络地址
    a=  int(a) & 255
    b = int(b) & 255
    c = int(c) & 255
    d = int(d) & 0
    ip=str(a)+"."+str(b)+"."+str(c)+"."+str(d)

    for i in list1:
        if i==ip:
            print(list1[i])
            if list1[i] == "内部":
                return 0
            else:
                return 1
    print("未找到")


def Route2(ip):
    #路由表
    list1={"192.168.1.0":"路由1","192.168.2.0":"内部","192.168.3.0":"路由3"}
    a,b,c,d=ip.split(".")
    #目的网络地址
    a=  int(a) & 255
    b = int(b) & 255
    c = int(c) & 255
    d = int(d) & 0
    ip=str(a)+"."+str(b)+"."+str(c)+"."+str(d)

    for i in list1:
        if i==ip:
            print(list1[i])
            if list1[i]=="内部":
                return 0
            else:
                return 1
    print("未找到")

def Route3(ip):
    #路由表
    list1={"192.168.1.0":"路由1","192.168.2.0":"路由2","192.168.3.0":"内部"}
    a, b, c, d = ip.split(".")
    # 目的网络地址
    a = int(a) & 255
    b = int(b) & 255
    c = int(c) & 255
    d = int(d) & 0
    ip = str(a) + "." + str(b) + "." + str(c) + "." + str(d)

    for i in list1:
        if i == ip:
            print(list1[i])
            if list1[i] == "内部":
                return 0
            else:
                return 1
    print("未找到")

if __name__=="__main__":
    ip=input("请输入目的ip:")
    if Route1(ip):
        if Route2(ip):
            Route3(ip)
