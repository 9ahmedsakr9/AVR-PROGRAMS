#list
mylist = ["one",1,"akasdf", "one", True]
print(mylist)
print(mylist[1])
print(mylist[-1])
print(mylist[0:2])
print(mylist[0:1])
print(mylist[::1])
print(mylist[::2])
mylist[0] =5
print(mylist)
mylist[1] =6
print(mylist)
mylist[0,1,2,3,4] = 1,1,1,1,1
print(mylist)
mylist[0:6] = 1,2,3,4,5,6,7#
print(mylist)
newlist = ["ha"]
newlist.append("kerjeko ")
print(newlist)
a=[1,2,3]
b=[5,6,7]
a.append(b)
print(a)
c=[11,22,33]
d=[55,66,77]
c.extend(d)
print(c)
a.remove(1)
print(a)
a= [5,-9,-6,21,1,2,3,0,0,19587,-989898]
a.sort(reverse=True)
print(a)
a.sort(reverse=False)
print(a)
a.sort()
print(a)
b =["ahmed","belal","amen","Sakr","youssef"]
b.sort()
print(b)
b.sort(reverse=True)
print(b)
b.sort(reverse=False)
print(b)
abs=[1,2,3]
abs.reverse()
print(abs)