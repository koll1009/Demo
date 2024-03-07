#variable
var1 = "test"
var2 = str(33)
var3 = [4, 2, 3] #list
for x in var3:
    print(x)

#use indentation to indicate code block
if True:
    print(len(var1), var1)
    print(var2)
    print(type(var1))
    print(type(1))
    print(type(1.2))
    print(type(True))
    print(type(var3))
    print(var3)

def fun1(arg1):
    print(arg1)
    
fun1("koll")

import random
print(random.randrange(1, 10))

errMsg = "this is error message from {}"
print(errMsg.format(36))

print("test operator")
print(2**3)#exponentiation
print(9/4)
print(9//4)#floor division

#list
#list can contain different data types
#a collection which is ordered and changeable. allow duplicate members
_list = list(("apple", 5, "pear", 6))
print(_list[0], _list[1])
print(_list[2], _list[3])
_list.insert(2, "insert")
_list.append("orange")
print(_list[:len(_list)])
_list.remove("orange")
print(_list[:len(_list)])
for i in range(len(_list)): #loop through index
  print(_list[i])
  

#class
class Person:
    def __init__(self, name, age):
        self.name_ = name
        self.age_ = age
        self.fruits_ = ["apple", "pear", "banana"]
    
    def __str__(self):
        return f"{self.name_}({self.age_})"
    
    def __iter__(self):
        self.index_ = 0
        return self

    def __next__(self):
        if self.index_ < len(self.fruits_):
            ret = self.fruits_[self.index_]
            self.index_ += 1
            return ret 
        else:
            raise StopIteration

p1 = Person("Jerry", 6)
print(p1)
for fruit in p1:
    print(fruit)


