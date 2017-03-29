# !/usr/bin/python

# huawei OJ必须使用这个if
# huawei OJ使用python2.x 只能使用raw_input()函数
# 在python3.x中已经不再使用raw_input()，改用input()
if __name__ == '__main__':
    input = input()
    strlist = input.split()
    print (len(list(strlist[-1:])[0]))